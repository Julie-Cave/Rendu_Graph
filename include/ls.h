#pragma once
#include "adjacence_matrix.h" 
#include "adjacence_list.h"
#include "arete.h"
// Parcours en largeur pour les listes d'adjacence et les matrices

std::tuple<std::vector<std::string>, std::vector<Arete>> LSL (AdjacenceList& graph_list, std::string& starting_summit, int dist) ;

std::tuple<std::vector<std::string>, std::vector<Arete>> LSM (AdjacenceMatrix& graph_list, std::string& starting_summit, int dist) ;