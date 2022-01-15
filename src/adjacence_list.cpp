#include "adjacence_list.h"
#include "summit.h"

AdjacenceList::AdjacenceList (std::unordered_map<std::string, Summit> graph_list) :
    graph_list(graph_list)
    {}

int AdjacenceList::size() {
    return graph_list.size() ;
}

std::unordered_map<std::string, Summit> AdjacenceList::map() {
    return graph_list ;
}


void AdjacenceList::print_list() {
    for (auto& elem: graph_list) { //pb parcourt le dictionnaire à l'envers
        elem.second.print_summit() ;
    }
}

std::vector<Arete> AdjacenceList::arete_list(std::string sommet) {
    std::vector<Arete> vector ;
    for (auto& elem: graph_list) {
        if (elem.first == sommet) {
            vector = elem.second.give_adj_list() ;
        }
    }
    return vector ;
}