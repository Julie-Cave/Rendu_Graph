//fonction pour passer à la représentation en matrice d'adjacence
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <numeric>
#include "adjacence_matrix.h" 
#include "adjacence_list.h"

//fonction pour passer à la représentation en matrice
AdjacenceMatrix to_matrix (AdjacenceList& graph_list) {
    
    int dimension = graph_list.size() ;
    std::unordered_map<std::string, Summit> graph = graph_list.map() ;
    std::vector<std::string> names ;
    std::vector<std::vector<double>> matrix (dimension, std::vector<double> (dimension, 0));
    
    for(auto& elem: graph) {
        names.push_back(elem.first) ;
    }
    for(int i = 0 ; i < names.size(); i++) {
        std::vector<Arete> adjacence_vector = graph_list.arete_list(names[i]) ;
        for (Arete& arete: adjacence_vector){
            for(int j = 0 ; j < names.size() ; j++) {
                if (names[j] == arete.directed_to()) {
                    double valeurij ;
                    valeurij = arete.arete_value() ;
                    matrix[i][j] = valeurij ;
                }
            }
        }
    }
    AdjacenceMatrix adjacence_matrix(dimension, names, matrix) ;
    return adjacence_matrix ;
}

//fonction pour passer à la représentation en liste d'adjacence
AdjacenceList to_list (AdjacenceMatrix& adjacence_matrix) {
    
    std::unordered_map<std::string, Summit> graph_list ;
    std::vector<std::string> names = adjacence_matrix.names() ;
    
    std::vector<std::vector<double>> matrix = adjacence_matrix.tab_adjacence() ;
    int dim = matrix.size() ;

    for(int i=0 ; i <  dim ; i++) {

        std::vector<Arete> adjacence_vector_i ;

        for (int j=0 ; j < dim ; j++) {
            
            if (matrix[i][j] != 0) {
                Arete arete_ij(matrix[i][j], names[j]) ;
                adjacence_vector_i.push_back(arete_ij) ;
            }
        }
        Summit summit_i (names[i], adjacence_vector_i) ;
        graph_list.insert({names[i], summit_i}) ;

    }
    AdjacenceList graph(graph_list) ;
    return graph ;
}