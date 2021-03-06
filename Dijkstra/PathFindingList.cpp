#include "PathFindingList.h"
#include <iostream>
using std::string;
using std::find;
using std::cout;
using std::endl;

NodeRecord PathfindingList::GetSmallestElement() {
    int smallerCost = 1000;
    NodeRecord nodeToReturn;
    for (int i = 0; i < nodes.size(); i++) {
        //nodeToReturn = nodes with the smallest costSoFar
        int cost = nodes[i].costSoFar;
        if (cost < smallerCost) {
            smallerCost = cost;
            nodeToReturn = nodes[i];
        }
        //if two nodes with the same smallest costSoFar, nodeToReturn = node with the smallest distanceToGoal
        else if (cost == smallerCost) {
            if (nodeToReturn.distanceToGoal >= nodes[i].distanceToGoal) {
                nodeToReturn = nodes[i];
            }
        }
    }
    return nodeToReturn;
}

bool PathfindingList::IsContain(string nodeName) {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodeName == nodes[i].nodeName) {
            return true;
        }
    }
    return false;
}

void PathfindingList::Add(NodeRecord node) {
    nodes.push_back(node);
}

void PathfindingList::Remove(string nodeName) {
    bool finish = false;
    while (!finish) {
        NodeRecord nodeToRemove;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodeName == nodes[i].nodeName) {
                nodeToRemove = nodes[i];
                break;
            }
        }
        auto it = find(nodes.begin(), nodes.end(), nodeToRemove);
        nodes.erase(it);

        if (!IsContain(nodeName)) {
            finish = true;
        }
    }
}

int PathfindingList::GetLen() { return nodes.size(); }

void PathfindingList::DisplayNodes() {
    for (int i = 0; i < nodes.size(); i++) {
        cout << nodes[i].connection << " " << nodes[i].distanceToGoal << " " << nodes[i].costSoFar << " (colonne " << nodes[i].nodeName << ")" << endl;
    }
}

NodeRecord* PathfindingList::GetNode(string nodeName) {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i].nodeName == nodeName) {
            return &nodes[i];
        }
    }
}
