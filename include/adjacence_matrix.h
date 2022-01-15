#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#pragma once
#include "adjacence_list.h"
#include "summit.h"

// attention ici on met pour les sommets inateignables la valeur 0
// de même entre 2 mêmes sommets

class AdjacenceMatrix {
    int dimension ;
    std::vector<std::string> summit_names ;
    std::vector<std::vector<double>> matrix ;

    public :

    AdjacenceMatrix (int dimension, std::vector<std::string> summit_names, std::vector<std::vector<double>> matrix) ; 
    
    std::vector<Arete> arete_list(std::string sommet) ;

    std::vector<std::vector<double>> tab_adjacence () ;

    std::vector<std::string> names () ;

    void print_matrix () ;

};