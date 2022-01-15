#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#pragma once
#include "summit.h"


class AdjacenceList {

    std::unordered_map<std::string, Summit> graph_list ;

    public :

    AdjacenceList(std::unordered_map<std::string, Summit> graph_list) ;

    int size ();
    
    std::unordered_map<std::string, Summit> map() ;

    void print_list() ;

    std::vector<Arete> arete_list (std::string sommet) ;
}; 