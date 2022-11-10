/*
 * main.cpp
 *
 *      Author: Sebastian Flores Lemus
 */
#include <iostream>
#include <cstring>
#include "ugraph.h"


int main(int argc, char* argv[]) {
	/************************ UMatrixGraph *********************/
	UMatrixGraph<int> umg(5);
	
	umg.addEdge(1, 2);
	umg.addEdge(2, 3);
	umg.addEdge(2, 4);
	umg.addEdge(3, 5);
	umg.addEdge(4, 3);
	umg.addEdge(5, 4);

  std::cout << "\n\nMatriz\n";
	std::cout << umg.toString();
	
	std::set<int> edges = umg.getConnectionFrom(2);
	std::set<int>::iterator itr;
	
	std::cout << "\n\n";

	UListGraph<int> ulg(5);
	
	ulg.addEdge(1, 2);
	ulg.addEdge(2, 3);
	ulg.addEdge(2, 4);
	ulg.addEdge(3, 5);
	ulg.addEdge(4, 3);
	ulg.addEdge(5, 4);

  std::cout << "Lista\n\n";
	std::cout << ulg.toString();
  
	std::cout << "\n\n";

  std::cout << "BFS & DFS Matriz\n\n"; 

  std::cout << "DFS(1) ->\t";
	edges = dfs(&umg, 1);
	for (itr = edges.begin(); itr != edges.end(); itr++) {
		std::cout << (*itr) << "\t";
	}
	
	std::cout << "\nBFS(2) ->\t";
	edges = bfs(&umg,2);
	for (itr = edges.begin(); itr != edges.end(); itr++) {
		std::cout << (*itr) << "\t";
	}
	std::cout << "\n\n";
	
	edges = ulg.getConnectionFrom(3);
	
	std::cout << "\n";

  std::cout << "BFS & DFS Lista\n\n"; 
	
	std::cout << "DFS(3) ->\t";
	edges = dfs(&ulg, 3);
	for (itr = edges.begin(); itr != edges.end(); itr++) {
		std::cout << (*itr) << "\t";
	}
	std::cout << "\n\n";

  edges = ulg.getConnectionFrom(4);
	
	std::cout << "BFS(4) ->\t";
	edges = bfs(&ulg, 4);
	for (itr = edges.begin(); itr != edges.end(); itr++) {
		std::cout << (*itr) << "\t";
	}
	std::cout << "\n\n";

  }
