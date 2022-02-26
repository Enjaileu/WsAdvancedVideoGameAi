#pragma once
#include <iostream>
#include <vector>
#include "NodeUtility.h"

//class qui contient les nodes
class Graph {
public:
    Graph() {};
    Graph(int idGraph);
    ~Graph() {}

    //return the connections with a certain fromNode
    std::vector<Connection*> GetConnection(std::string fromNode);
    //return if a certain nodeName is in nodeNames
    bool IsInNodeList(std::string nodeName);

    //display connections list
    void DisplayConnection();
    //display nodes list
    void DisplayNodeNames(std::string fromNode = "");


private:
    std::vector<Connection> connections;
    std::vector<std::string> nodeNames;
};