#pragma once
#include <iostream>
#include "Graph.h"

void pathfindDijkstra(Graph graph, std::string start, std::string end);
void pathfindAstar(Graph graph, std::string start, std::string end);