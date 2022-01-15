#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class Arete {

    double value ;
    std::string sommet_sortant ;

    public :

    Arete (double value, std::string sommet_sortant) ;

    std::string directed_to (); // récupérer le sommet sortant

    double arete_value () ; // récupérer la valeur de l'arête

    void print_arete () ;

} ;
