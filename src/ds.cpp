#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <numeric>
#include <stack>
#include "adjacence_matrix.h" 
#include "adjacence_list.h"
#include "arete.h"
#include "summit.h"

// TEST SI UN NOM EST DANS UNE LISTE DE NOMS
bool is_not_in (std::vector<std::string>& vecteur, std::string& elt) {
    for (std::string mot: vecteur) {
        if (elt == mot) {
            return false ;
        }
    }
    return true ;
}

// RECURSIF LISTE
std::tuple<std::vector<std::string>, std::vector<Arete>> DSRL (
    AdjacenceList& graph_list, std::string& starting_summit, 
    std::vector<std::string>& visited_summits, std::vector<Arete>& visited_aretes) {

    if (is_not_in(visited_summits, starting_summit)) {
        
        visited_summits.push_back(starting_summit) ;
        std::vector<Arete> neighbours_list = graph_list.arete_list(starting_summit) ;
        
        for (Arete& arete: neighbours_list) {
            
            std::string summit = arete.directed_to() ;

            if(is_not_in(visited_summits, summit)) {
                
                visited_aretes.push_back(arete) ;
                
                DSRL(graph_list, summit, visited_summits, visited_aretes) ;
            }
        }
    }
    return {visited_summits, visited_aretes} ;
}

//RECURSIF MATRICE, on fait la même chose en utilisant la fonction construite en question 1
//où on retrouve la liste d'adjacence d'un sommet à partir de son nom
std::tuple<std::vector<std::string>, std::vector<Arete>> DSRM (
    AdjacenceMatrix& graph_list, std::string& starting_summit, 
    std::vector<std::string>& visited_summits, std::vector<Arete>& visited_aretes) {

    if (is_not_in(visited_summits, starting_summit)) {
        
        visited_summits.push_back(starting_summit) ;
        std::vector<Arete> neighbours_list = graph_list.arete_list(starting_summit) ;
        
        for (Arete& arete: neighbours_list) {
            
            std::string summit = arete.directed_to() ;

            if(is_not_in(visited_summits, summit)) {
                
                visited_aretes.push_back(arete) ;
                
                DSRM(graph_list, summit, visited_summits, visited_aretes) ;
            }
        }
    }
    return {visited_summits, visited_aretes} ;
}

// ITERATIF LISTE

std::tuple<bool, std::string, Arete> exist_neighbour_list (AdjacenceList& graph_list, std::string& summit, std::vector<std::string>& visited_summits) {
    std::vector<Arete> neighbours_list = graph_list.arete_list(summit) ;
    for (Arete& arete: neighbours_list){
        
        std::string neighbour = arete.directed_to() ;
            
        if (is_not_in(visited_summits, neighbour)) {
            return {true, neighbour, arete} ;
        }
    }
    return {false, "nobody", neighbours_list[0]} ;
}

std::tuple<std::vector<std::string>, std::vector<Arete>> DSIL (AdjacenceList& graph_list, std::string& starting_summit) 
{
    std::vector<std::string> visited_summits ; 
    std::vector<Arete> visited_aretes ;
    std::stack<std::string> pile ;

    pile.push(starting_summit) ;
    visited_summits.push_back(starting_summit) ;

    while (pile.size() > 0) {
        
        std::string new_summit = pile.top() ;

        // on teste l'existence d'un voisin de ce nouveau sommet qui n'as pas été visité
        auto [booléen, neighbour, arete] = exist_neighbour_list(graph_list, new_summit, visited_summits) ;
        if (booléen) {
            pile.push(neighbour) ;
            visited_summits.push_back(neighbour) ;
            visited_aretes.push_back(arete) ;
        }
        // si il n'existe pas de voisin non visité, on dépile.
        else { 
            pile.pop() ;
        }
    }
    return {visited_summits, visited_aretes} ;
}

// ITERATIF MATRICE, on adapte le code précédent avec le bon type

std::tuple<bool, std::string, Arete> exist_neighbour_matrix (AdjacenceMatrix& graph_matrix, std::string& summit, std::vector<std::string>& visited_summits) {
    std::vector<Arete> neighbours_list = graph_matrix.arete_list(summit) ;
    for (Arete& arete: neighbours_list){
        
        std::string neighbour = arete.directed_to() ;
            
        if (is_not_in(visited_summits, neighbour)) {
            return {true, neighbour, arete} ;
        }
    }
    return {false, "nobody", neighbours_list[0]} ;
}

std::tuple<std::vector<std::string>, std::vector<Arete>> DSIM (AdjacenceMatrix& graph_matrix, std::string& starting_summit) 
{
    std::vector<std::string> visited_summits ; 
    std::vector<Arete> visited_aretes ;
    std::stack<std::string> pile ;

    pile.push(starting_summit) ;
    visited_summits.push_back(starting_summit) ;

    while (pile.size() > 0) {
        
        std::string new_summit = pile.top() ;

        // on teste l'existence d'un voisin de ce nouveau sommet qui n'as pas été visité
        auto [booléen, neighbour, arete] = exist_neighbour_matrix(graph_matrix, new_summit, visited_summits) ;
        if (booléen) {
            pile.push(neighbour) ;
            visited_summits.push_back(neighbour) ;
            visited_aretes.push_back(arete) ;
        }
        // si il n'existe pas de voisin non visité, on dépile.
        else { 
            pile.pop() ;
        }
    }
    return {visited_summits, visited_aretes} ;
}
