#include "Graph.h"
#include<iostream>
#include <vector>
using namespace std;

Graph::Graph(int idGraph) {
    id = idGraph;
    if (id == 1) {
        nodeNames = { "A", "B", "C", "D", "E", "F", "G" };
        for (int i = 0; i < 7; i++) {
            string fromNode = nodeNames[i];
            for (int j = 0; j < 7; j++) {
                if (matriceProxi01[i][j] != 0 && matriceProxi01[i][j] != 100) {
                    string toNode = nodeNames[j];
                    int cost = matriceProxi01[i][j];
                    Connection connection = { cost, fromNode, toNode };
                    connections.emplace_back(connection);
                }

            }
        }
    }
    else if (id == 2) {
        const int sizeTable = 10;
        nodeNames = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
        for (int i = 0; i < sizeTable; i++) {
            string fromNode = nodeNames[i];
            for (int j = 0; j < sizeTable; j++) {
                if (matriceProxi02[i][j] != 0 && matriceProxi02[i][j] != 100) {
                    string toNode = nodeNames[j];
                    int cost = matriceProxi02[i][j];
                    Connection connection = { cost, fromNode, toNode };
                    connections.emplace_back(connection);
                }

            }
        }
    }
}

vector<Connection*> Graph::GetConnection(string fromNode) {
    vector<Connection*> connectionsToReturn;
    for (int i = 0; i < connections.size(); i++) {
        if (connections[i].fromNode == fromNode) {
            connectionsToReturn.push_back(&connections[i]);
        }
    }
    return connectionsToReturn;
}

int Graph::GetDistance(string fromNode, string goalNode) {
    auto it = find(nodeNames.begin(), nodeNames.end(), fromNode);
    int indexFromNode = distance(nodeNames.begin(), it);

    it = find(nodeNames.begin(), nodeNames.end(), goalNode);
    int indexGoalNode = distance(nodeNames.begin(), it);

    if (id == 1) {
        return matriceDistance01[indexFromNode][indexGoalNode];
    }
    else if (id == 2) {
        return matriceDistance02[indexFromNode][indexGoalNode];
    }

}

void Graph::DisplayConnection() {
    for (int i = 0; i < connections.size(); i++) {
        cout << connections[i].fromNode << " -> " << connections[i].toNode << " = " << connections[i].cost << endl;
    }
}

void Graph::DisplayNodeNames(string fromNode) {
    for (int i = 0; i < nodeNames.size(); i++) {
        if (nodeNames[i] != fromNode && i != nodeNames.size() && i !=0) {
            cout << "- ";
        }
        if (nodeNames[i] != fromNode) {
            cout << nodeNames[i] << " ";
        }
    }
    cout << endl;
}

bool Graph::IsInNodeList(string nodeName) {
    for (int i = 0; i < nodeNames.size(); i++) {
        if (nodeNames[i] == nodeName) {
            return true;
        }
    }
    return false;
}
