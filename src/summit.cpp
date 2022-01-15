#include "summit.h"

Summit::Summit (std::string name, std::vector<Arete> adjacence_list) :
    name(name),
    adjacence_list(adjacence_list)
    {}

std::string Summit::give_name() {
    return name ;
}

std::vector<Arete> Summit::give_adj_list() {
    return adjacence_list ;
}

void Summit::print_summit() {
    std::cout << "nom : " << name << std::endl ;
    for(Arete &arete: adjacence_list) {
        arete.print_arete() ;
    }
}