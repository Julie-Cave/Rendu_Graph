#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
#include <numeric>
#include <limits>
#pragma once
#include "adjacence_matrix.h" 
#include "adjacence_list.h"
#include "arete.h"

// Trouve le sommet qui est à la plus petite distance du sommet de départ et qui n'a pas été traité
std::string sommet_minimal (std::unordered_map<std::string, double> distances, std::vector<std::string>& start_summits) ;

// Efface un sommet appelé minimum de la liste des sommets
void erase_minimum(std::vector<std::string>& start_summits, std::string minimum) ;

// Retourne le chemin le plus court à l'envers (du sommet d'arrivée au départ)
std::vector<std::string> path(std::unordered_map<std::string, std::string> passage, std::string depart, std::string arrivee) ;

// Algorithme Dijkstra
std::tuple<std::vector<std::string>, double> dijkstra (AdjacenceList& graph, std::string depart, std::string arrivee) ;

// Algorithme Floyd Warshall
std::vector<std::vector<double>> floydwarshall (AdjacenceMatrix& graph) ;
