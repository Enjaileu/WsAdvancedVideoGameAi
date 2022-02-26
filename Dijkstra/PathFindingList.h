#pragma once
#include <iostream>
#include <vector>
#include "NodeUtility.h"

//class to create node lists
class PathfindingList {
public:
    PathfindingList() {}
    ~PathfindingList() {}

    //get the node in nodes with the smallest costSoFar
    NodeRecord GetSmallestElement();

    //return if nodes contains a node with a certain nodeName
    bool IsContain(std::string nodeName);

    //add a node in nodes
    void Add(NodeRecord node);

    //remove a node from node
    void Remove(std::string nodeName);

    //return the nodes's length
    int GetLen();

    //display the nodes
    void DisplayNodes(); 

    //get the first node found with a certain nodeName (use only with the closedList!!)
    NodeRecord* GetNode(std::string nodeName);

private:
    std::vector<NodeRecord> nodes;
};