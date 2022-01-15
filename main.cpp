#include "adjacence_matrix.h"
#include "arete.h"
#include "summit.h"
#include "adjacence_list.h"
#include "read.h"
#include "graph.h"
#include "ds.h"
#include "ls.h"
#include "shortestpath.h"
#include "test.h"

int main (int argc, char** argv) {

// premier test : y a-t-il un fichier ?
    if (argc <= 1) {
        std::cerr << "no file" << std::endl ;
        return 1 ;
    }

    // si on a passé le premier test on peut attribuer un string au nom du fichier
    std::string filename = argv[1] ;

// deuxième test : le fichier est-il du bon type ?
    if (not_end_graph(filename)) {
        std::cerr << "invalid file" << std::endl ;
        return 1 ;
    }

    // si on a passé le deuxième test on peut former la liste d'adjacence du graph
    AdjacenceList test_list = create_graph(argc, filename) ;

/* QUESTION 1 et 2 : tester les classes par les fonctions print, le passage d'une représentation à l'autre
    test1(test_list) ;
*/

/* QUESTION 3 : TEST PARCOURS EN PROFONDEUR RECURSIF
    //liste d'adjacence
    std::cout << "test pour les listes d'adjacences" << std::endl ;
    test31(test_list, "A") ;
    std::cout << "" << std::endl ;
    //matrice
    std::cout << "test pour les matrices d'adjacences" << std::endl ;
    test32(test_list, "B") ; 
*/

/* QUESTION 4 : TEST PARCOURS EN PROFONDEUR ITERATIF
    //liste d'adjacence
    std::cout << "test pour les listes d'adjacences" << std::endl ;
    test41(test_list, "A") ;
    std::cout << "" << std::endl ;
    //matrice d'adjacence
    std::cout << "test pour les matrices d'adjacences" << std::endl ;
    test42(test_list, "B") ;
    std::cout << "" << std::endl ;
*/

/* QUESTION 5 : TEST PARCOURS EN LARGEUR
    //liste d'adjacence
    std::cout << "test pour les listes d'adjacences" << std::endl ;
    test51(test_list, "", 2) ;
    std::cout << "A" << std::endl ;
    //matrice d'adjacence
    std::cout << "test pour les matrices d'adjacences" << std::endl ;
    test52(test_list, "A", 2) ;
    std::cout << "" << std::endl ;
*/

/*QUESTION 6 : TEST DIJKSTRA
    test61(test_list, "M", "S") ;
*/

/* QUESTION 7 : TEST FLOYD WARSHALL
    test71(test_list) ; 
*/
    
    return 0 ;
}

