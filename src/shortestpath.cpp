#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
#include <numeric>
#include <limits>
#include "adjacence_matrix.h" 
#include "adjacence_list.h"
#include "arete.h"
#include "summit.h"
#include "ds.h"

// Outils pour la suite
std::string sommet_minimal (std::unordered_map<std::string, double> distances, std::vector<std::string>& start_summits) {
    double min = std::numeric_limits<double>::infinity() ;
    std::string min_summit ; 

    for(auto& elt: distances) {
        //int occurence = std::count(start_summits.begin(), start_summits.end(), elt.first) ;
        for(auto& c: start_summits){
            if(elt.first == c) {
                if (min > elt.second) {
                    min = elt.second ;
                    min_summit = elt.first ;
                }
            }
        }
    }
    return min_summit ;
}

void erase_minimum(std::vector<std::string>& start_summits, std::string minimum) {
    for(int i = 0 ; i < start_summits.size() ; i++) {
        if (minimum == start_summits[i]) {
            start_summits.erase(start_summits.begin()+i) ;
        }
    }
}

bool is_in_vector(std::vector<std::string> start_summits, std::string neighbour){
    for (std::string& name: start_summits) {
        if(neighbour == name){
            return true ;
        }
    }
    return false ;
}

std::vector<std::string> path(std::unordered_map<std::string, std::string> passage, std::string depart, std::string arrivee) {
    std::vector<std::string> chemin ;
    std::string sommet = arrivee ;
    std::string transit ;

    while (transit != depart) {
        chemin.push_back(sommet) ;
        transit = sommet ;
        sommet = passage[transit] ;
    }

    return chemin ;
}

//ALGORITHME DE DIJKSTRA pour les listes d'adjacence
std::tuple<std::vector<std::string>, double> dijkstra (AdjacenceList& graph, std::string depart, std::string arrivee){
    
    //initialisation des objets dont on a besoin
    std::unordered_map<std::string, double> distances ;
    std::unordered_map<std::string, std::string> passage ;
    double inf = std::numeric_limits<double>::infinity() ;
    std::vector<std::string> start_summits ;
    std::vector<std::string> grey_summits ;
    std::string minimum ;

    for (auto& elt: graph.map()) {
        distances.insert({elt.first, inf}) ;
        passage.insert({elt.first, "NaN"}) ;
        start_summits.push_back(elt.first) ;
    }

    //initialisation à partir des données de départ
    distances[depart] = 0 ;

    // on s'arrête au bout d'un moment si les deux sommets ne sont pas liés
    int c = 0 ;

    while (start_summits.size()> 0) {
        minimum = sommet_minimal(distances, start_summits) ;
        //std::cout<< minimum << std::endl ;
        
        grey_summits.push_back(minimum) ; 
        erase_minimum(start_summits, minimum) ;
        start_summits.shrink_to_fit() ;
        
        //std::cout<< start_summits.size() << std::endl ;

        std::vector<Arete> neighbours = graph.arete_list(minimum) ;

        for (Arete& arete: neighbours) {
            std::string neighbour = arete.directed_to() ;
            double value = arete.arete_value() ;

            if (is_in_vector(start_summits, neighbour)) {
                if (distances[neighbour] > distances[minimum] + value) {
                    distances[neighbour] = distances[minimum] + value ;
                    passage[neighbour] = minimum ;
                }
            }
        }
        
        c+= 1;
        if (c> 100){
            std::cout << "les deux sommets ne sont probablement pas reliés" << std::endl ;
            std::vector<std::string> chemin ;
            double inf = std::numeric_limits<double>::infinity() ;
            return {chemin, inf} ;
        }
    }
    std::vector<std::string> chemin_arrivee = path(passage, depart, arrivee) ; // a l'envers

    // On renverse l'ordre du vecteur pour avoir le chemin depuis l'arrivée vers le départ
    int n = chemin_arrivee.size() ;
    std::vector<std::string> chemin (n, "Nan");
    

    for (auto& name: chemin_arrivee) {
        chemin[n-1] = name ;
        n = n - 1 ;
    }
    
    // Et si on ne peut pas atteindre le sommet ?

    // On retourne le chemin le plus court et sa longueur
    return {chemin, distances[arrivee]} ;
}

//ALGORITHME DE FLOYD WARSHALL pour les matrices

std::vector<std::vector<double>> floydwarshall (AdjacenceMatrix& graph) {
    std::vector<std::vector<double>> matrix = graph.tab_adjacence() ;
    int dimension = matrix.size() ;

// On met à jour la matrice d'adjacence pour mettre à une distance infinie des points non connectés et à 0 les sommets avec eux mêmes
    for (int i = 0 ; i < dimension ; i++){
        for(int j = 0 ; j < dimension ; j++) {
            if (matrix[i][j] == 0) {
                if (i != j) {
                    matrix[i][j] = std::numeric_limits<double>::infinity() ;
                }
            }
        }
    }

// Algorithme en lui même 
    for(int k = 0 ; k < dimension ; k++){
        for(int l = 0 ; l < dimension ; l++) {
            for(int m = 0 ; m < dimension ; m++) {
                matrix[l][m] = std::min(matrix[l][m], matrix[l][k] + matrix[k][m]) ;
            }
        }
    }

    return matrix ;
}
