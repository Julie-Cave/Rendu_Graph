#include "test.h"

void test1 (AdjacenceList test_list) {
    std::cout << "Représentation liste d'adjacence" << std::endl ;
    test_list.print_list();

    std::cout << ""<< std::endl ;

    std::cout << "Représentation matrice d'adjacence" << std::endl ;
    AdjacenceMatrix test_matrix = to_matrix(test_list) ;
    test_matrix.print_matrix() ;

    std::cout <<""<< std::endl ;

    std::cout << "Retour à la liste d'adjacence" << std::endl ;
    AdjacenceList test_list2 = to_list(test_matrix) ;
    test_list2.print_list() ;
}

void test31 (AdjacenceList graph, std::string A){
    std::vector<std::string> visited_summits ;
    std::vector<Arete> visited_aretes ;

    auto [sommets, aretes] = DSRL(graph, A, visited_summits, visited_aretes) ;

    std::cout << "Sommets parcourus" << std::endl ;
    for (auto& summit: sommets) {
        std::cout << "parcours" ;
        std::cout << summit << std::endl ;
    }
    std::cout << "Aretes parcourues" << std::endl ;
    for (Arete& arete: aretes) {
        arete.print_arete() ;
    }
}

void test32 (AdjacenceList graph, std::string A) {
    AdjacenceMatrix graph_matrix = to_matrix(graph) ;

    std::vector<std::string> visited_summits2 ;
    std::vector<Arete> visited_aretes2 ;

    auto [sommets2, aretes2] = DSRM(graph_matrix, A, visited_summits2, visited_aretes2) ;

    for (auto& summit: sommets2) {
        std::cout << "parcours" ;
        std::cout << summit << std::endl ;
    }

    for (Arete& arete: aretes2) {
        arete.print_arete() ;
    }
}

void test41 (AdjacenceList graph, std::string A) {
    
    auto [sommets, aretes] = DSIL(graph, A) ;

    for (auto& summit: sommets) {
        std::cout << "parcours" ;
        std::cout << summit << std::endl ;
    }

    for (Arete& arete: aretes) {
        arete.print_arete() ;
    }
}

void test42 (AdjacenceList graph, std::string A) {

    AdjacenceMatrix graph_matrix = to_matrix(graph) ;
    auto [sommets, aretes] = DSIM(graph_matrix, A) ;

    for (auto& summit: sommets) {
        std::cout << "parcours" ;
        std::cout << summit << std::endl ;
    }

    for (Arete& arete: aretes) {
        arete.print_arete() ;
    }
}

void test51 (AdjacenceList graph, std::string A, int n) {
    
    auto [sommets, aretes] = LSL(graph, A, n) ;

    for (auto& summit: sommets) {
        std::cout << "parcours" ;
        std::cout << summit << std::endl ;
    }

    for (Arete& arete: aretes) {
        arete.print_arete() ;
    }
}

void test52 (AdjacenceList graph, std::string A, int n) {
    
    AdjacenceMatrix graph_matrix = to_matrix(graph) ;
    auto [sommets, aretes] = LSM(graph_matrix, A, n) ;

    for (auto& summit: sommets) {
        std::cout << "parcours" ;
        std::cout << summit << std::endl ;
    }

    for (Arete& arete: aretes) {
        arete.print_arete() ;
    }
}

void test61 (AdjacenceList graph, std::string M, std::string S) {
    auto [chemin, parcours] = dijkstra(graph, M, S) ;

    std::cout << "Le chemin le plus court est " ;
    for(auto& c: chemin) {
        std::cout<< c << ", " ;
    }

    std::cout <<std::endl ;
    std::cout << "Il fait " << parcours << std::endl ;
}

void test71 (AdjacenceList graph) {
    AdjacenceMatrix graph_matrix = to_matrix(graph) ;
    
    std::vector<std::vector<double>> chemins = floydwarshall(graph_matrix) ;
    std::vector<std::string> sommets = graph_matrix.names() ;

    for(int i = 0 ; i < chemins.size() ; i++){
        for(int j = 0 ; j < chemins.size() ; j++){
            std::cout << "distance entre sommets " << sommets[i] << " et "<< sommets[j]<< " est " << chemins[i][j] << std::endl ;
        }
    }
}