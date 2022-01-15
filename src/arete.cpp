#include "arete.h"

Arete::Arete (double value, std::string sommet_sortant) :
    value(value),
    sommet_sortant(sommet_sortant)
    {}

void Arete::print_arete () {
    std::cout << "valeur arete : " << value << ", sommet sortant : " << sommet_sortant << std::endl ;
}

std::string Arete::directed_to() {
    return sommet_sortant ;
}

double Arete::arete_value () {
    return value ;
}
