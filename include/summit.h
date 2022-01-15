#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#pragma once
#include "arete.h"

class Summit {
    
    std::string name ;
    std::vector<Arete> adjacence_list ;

    public :

    Summit (std::string name, std::vector<Arete> adjacence_list);
    
    std::string give_name();

    std::vector<Arete> give_adj_list(); 

    void print_summit ();

};