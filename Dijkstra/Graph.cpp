#include "Graph.h"
#include<iostream>
#include <vector>
using namespace std;

Graph::Graph(int idGraph) {
    if (idGraph == 1) {
        nodeNames = { "A", "B", "C", "D", "E", "F", "G" };
        const int sizeTable = 7;
        const int matriceProxi[sizeTable][sizeTable]{
            //A     B     C     D     E     F     G
             {0,    2,    1,    100,  100,  100,  100 }, //A
             {2,    0,    100,  4,    6,    100,  100},  //B
             {1,    100,  0,    100,  5,    1,    100},  //C
             {100,  4,    100,  0,    100,  100,  5},    //D
             {100,  6,    5,    100,  0,    2,    4},    //E
             {100,  100,  1,    100,  2,    0,    100},  //F
             {100,  100,  100,  5,    4,    100,  0}     //G
        };

        for (int i = 0; i < sizeTable; i++) {
            string fromNode = nodeNames[i];
            for (int j = 0; j < sizeTable; j++) {
                if (matriceProxi[i][j] != 0 && matriceProxi[i][j] != 100) {
                    string toNode = nodeNames[j];
                    int cost = matriceProxi[i][j];
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
