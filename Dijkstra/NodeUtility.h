#pragma once
#include <iostream>

//This struct contain all the information for a Node
struct NodeRecord {
    std::string nodeName;
    std::string connection;
    int costSoFar;

    inline bool operator ==(NodeRecord t) {
        return nodeName == t.nodeName && costSoFar == t.costSoFar;
    }
};

//contains informations about connection between two nodes 
struct Connection {
    int cost;
    std::string fromNode;
    std::string toNode;
};

