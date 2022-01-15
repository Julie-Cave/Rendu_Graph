
#pragma once 
#include "adjacence_list.h"
#include "summit.h"
#include "arete.h"

// Lecture d'un fichier lors de la compilation
std::vector<std::vector<std::string>> read_graph (std::string filename) ;

//Transformer le fichier en une liste d'adjacence
bool not_end_graph (std::string filename) ;
AdjacenceList create_graph (int argc, std::string filename) ;