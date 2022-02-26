#pragma once
#include <iostream>

//This struct contain all the information for a Node in Dijkstra algorithm
struct NodeRecord {
    std::string nodeName;
    std::string connection;
    int distanceToGoal;
    int costSoFar;

    inline bool operator ==(NodeRecord t) {
        return nodeName == t.nodeName && costSoFar == t.costSoFar && distanceToGoal == t.distanceToGoal && connection == t.connection;
    }
};

//contains informations about connection between two nodes 
struct Connection {
    int cost;
    std::string fromNode;
    std::string toNode;

    inline bool operator ==(Connection t) {
        return cost == t.cost && fromNode == t.fromNode && toNode == t.toNode;
    }
};

