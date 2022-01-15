#pragma once
#include "adjacence_list.h"
#include "adjacence_matrix.h"
#include "arete.h"
#include "summit.h"
#include "ds.h"
#include "ls.h"
#include "graph.h"
#include "read.h"
#include "shortestpath.h"

// TEST Q1 et Q2 avec le fichier test.graph par exemple
void test1 (AdjacenceList test_list) ;

//TESTS Q3
void test31 (AdjacenceList graph, std::string A) ;
void test32 (AdjacenceList graph, std::string A) ;

//TESTS Q4
void test41 (AdjacenceList graph, std::string A) ;
void test42 (AdjacenceList graph, std::string A) ;

//TESTS Q5
void test51 (AdjacenceList graph, std::string A, int n) ;
void test52 (AdjacenceList graph, std::string A, int n) ;

//TEST Q6 
void test61 (AdjacenceList graph, std::string M, std::string S) ;

//TEST Q7
void test71 (AdjacenceList graph) ;