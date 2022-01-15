#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <numeric>
#include <stdexcept>
#include "adjacence_list.h"
#include "summit.h"
#include "arete.h"
#include "ds.h"

std::vector<std::vector<std::string>> read_graph (std::string filename) {
    
    std::vector<std::vector<std::string>> data ;

    std::ifstream input_file(filename) ;
    
    std::string line;

    while (getline(input_file, line)) {
        
        while (getline(input_file, line)) {
            std::istringstream iss(line);
            std::string x;
            std::vector<std::string> arete;
            while (iss >> x) {
                arete.push_back(x);
            }
            data.push_back(arete) ;
        }
    }
    return data ;          
}

bool not_end_graph (std::string filename) {
    int end = filename.size() ;
    if ( (filename[end-1] == 'h') & (filename[end-2] == 'p') 
    & (filename[end-3] == 'a') & (filename[end-4] == 'r') & (filename[end-5] == 'g') 
    & (filename[end-6] == '.')) {
        return false ;
    }
    return true ;
}

AdjacenceList create_graph (int argc, std::string filename){

// ON LIT LE FICHIER ET ON STOCKE LES DONNEES :
    std::vector<std::vector<std::string>> donnees = read_graph(filename) ;

// ON CREE LA LISTE DES SOMMETS :   
    std::vector<std::string> summit_list ;

    for (std::vector<std::string> vec: donnees) {
        if (is_not_in(summit_list, vec[0])) {
            summit_list.push_back(vec[0]) ;
        }
        if (is_not_in(summit_list, vec[1])) {
            summit_list.push_back(vec[1]) ;
        }
    }

// ON CREE LA LISTE D'ADJACENCE :
    std::unordered_map<std::string, Summit> graph_list ;

    for (std::string summit_name: summit_list) {
        std::vector<Arete> adjacence_vector ;
        for (std::vector<std::string> vec: donnees) {
            if (vec[0] == summit_name) {

                double arete_value = std::stod(vec[2]) ;
                std::string sommet_sortant = vec[1] ;
                Arete arete_summit (arete_value, sommet_sortant);

                adjacence_vector.push_back(arete_summit) ;
            }
        }
        Summit summit_class(summit_name, adjacence_vector) ;
        graph_list.insert({summit_name, summit_class}) ;
    }
    
    AdjacenceList graph(graph_list) ;
    return graph ;
}