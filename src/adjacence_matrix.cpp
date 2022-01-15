#include "adjacence_matrix.h"

AdjacenceMatrix::AdjacenceMatrix (int dimension, std::vector<std::string> summit_names, std::vector<std::vector<double>> matrix) :
        dimension(dimension),
        summit_names(summit_names),
        matrix(matrix)
        {}

void AdjacenceMatrix::print_matrix() {
    for(int i=0 ; i < dimension ; i++) {
        for (int j=0 ; j < dimension ; j++) {
            std::cout << "L'arête entre le sommet " << summit_names[i] <<
            " et le sommet " << summit_names[j] <<
            "est : " << matrix[i][j] << std::endl ;
        }
    }
}

std::vector<Arete> AdjacenceMatrix::arete_list(std::string sommet) {
    std::vector<Arete> adjacence_vector ;
    for (int i = 0 ; i < dimension ; i++) {
        if (summit_names[i] == sommet) {
            for (int j = 0 ; j < dimension ; j++) {
                if (matrix[i][j] != 0) {
                    Arete arete_ij(matrix[i][j], summit_names[j]) ;
                    adjacence_vector.push_back(arete_ij) ;
                }
            }
        }
    }
    return adjacence_vector ;
}

std::vector<std::vector<double>> AdjacenceMatrix::tab_adjacence() {
    return matrix ;
}

std::vector<std::string> AdjacenceMatrix::names () {
    return summit_names ; 
}