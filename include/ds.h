#pragma once
#include "adjacence_matrix.h" 
#include "adjacence_list.h"
#include "arete.h"

//PARCOURS EN PROFONDEUR

//Fonction auxilliaire
bool is_not_in (std::vector<std::string>& vecteur, std::string& elt) ;

//RECURSIF pour les listes d'adjacnce et les matrices
std::tuple<std::vector<std::string>, std::vector<Arete>> DSRL (AdjacenceList& graph_list, std::string& starting_summit, 
    std::vector<std::string>& visited_summits, std::vector<Arete>& visited_aretes) ;

std::tuple<std::vector<std::string>, std::vector<Arete>> DSRM (
    AdjacenceMatrix& graph_list, std::string& starting_summit, 
    std::vector<std::string>& visited_summits, std::vector<Arete>& visited_aretes) ;

//ITERATIF pour les listes d'adjacnce et les matrices
std::tuple<bool, std::string, Arete> exist_neighbour_list (AdjacenceList& graph_list, std::string& summit, std::vector<std::string>& visited_summits) ;
std::tuple<std::vector<std::string>, std::vector<Arete>> DSIL (AdjacenceList& graph_list, std::string& starting_summit) ;

std::tuple<bool, std::string, Arete> exist_neighbour_matrix (AdjacenceMatrix& graph_matrix, std::string& summit, std::vector<std::string>& visited_summits) ;
std::tuple<std::vector<std::string>, std::vector<Arete>> DSIM (AdjacenceMatrix& graph_matrix, std::string& starting_summit) ;