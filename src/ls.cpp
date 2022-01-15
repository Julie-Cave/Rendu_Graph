#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <numeric>
#include <queue>
#include "adjacence_matrix.h" 
#include "adjacence_list.h"
#include "arete.h"
#include "summit.h"
#include "ds.h"

// PARCOURS EN PROFONDEUR LISTE
std::tuple<std::vector<std::string>, std::vector<Arete>> LSL (AdjacenceList& graph_list, std::string& starting_summit, int dist){
    
    std::vector<std::string> visited_summits ;
    std::vector<Arete> visited_aretes ;
    std::queue<std::string> file ;
    std::string new_summit ;
    std::unordered_map<std::string, int> distance ;

//on initialise le dictionnaire où on va stocker les sommets accessibles et la distance minimale pour s'y rendre
    distance.insert({starting_summit, 0}) ;
    visited_summits.push_back(starting_summit) ;
    file.push(starting_summit) ;

    while (not(file.empty())) {
        
        new_summit = file.front() ;
        file.pop() ;
        std::vector<Arete> neighbours_list = graph_list.arete_list(new_summit) ;
        
        for (Arete& arete: neighbours_list) {
            
            std::string neighbour = arete.directed_to() ;

            if (is_not_in(visited_summits, neighbour)) {
                file.push(neighbour) ;
                visited_summits.push_back(neighbour) ;
                visited_aretes.push_back(arete) ;
                distance.insert({neighbour, distance[new_summit]+1}) ;
            }
        }

        if (distance[file.front()] == dist) {
            return {visited_summits, visited_aretes} ;
        }
    }
    return {visited_summits, visited_aretes} ;
}

// PARCOURS EN PROFONDEUR MATRICE
std::tuple<std::vector<std::string>, std::vector<Arete>> LSM (AdjacenceMatrix& graph_list, std::string& starting_summit, int dist) {
    
    std::vector<std::string> visited_summits ;
    std::vector<Arete> visited_aretes ;
    std::queue<std::string> file ;
    std::string new_summit ;
    std::unordered_map<std::string, int> distance ;

    distance.insert({starting_summit, 0}) ;
    visited_summits.push_back(starting_summit) ;
    file.push(starting_summit) ;

    while (not(file.empty())) {
        
        new_summit = file.front() ;
        file.pop() ;
        std::vector<Arete> neighbours_list = graph_list.arete_list(new_summit) ;
        
        for (Arete& arete: neighbours_list) {
            
            std::string neighbour = arete.directed_to() ;

            if (is_not_in(visited_summits, neighbour)) {
                file.push(neighbour) ;
                visited_summits.push_back(neighbour) ;
                visited_aretes.push_back(arete) ;
                distance.insert({neighbour, distance[new_summit]+1}) ;
            }
        }

        if (distance[file.front()] == dist) {
            return {visited_summits, visited_aretes} ;
        }
    }

    return {visited_summits, visited_aretes} ;
}