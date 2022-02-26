#include "Graph.h"
#include<iostream>
#include <vector>
using namespace std;

Graph::Graph(int idGraph) {
    if (idGraph == 1) {
        const int sizeTable = 7;
        nodeNames = { "A", "B", "C", "D", "E", "F", "G" };
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
        const int matriceDistance[sizeTable][sizeTable]{
            //A     B     C     D     E     F     G
             {0,    4,    4,    9,    7,    6,    11 },  //A
             {4,    0,    5,    6,    6,    7,    8},    //B
             {4,    5,    0,    9,    4,    1,    3},    //C
             {9,    6,    9,    0,    6,    9,    3},    //D
             {7,    6,    4,    6,    0,    3,    6},    //E
             {6,    7,    1,    9,    3,    0,    9},    //F
             {11,   8,    3,    3,    6,    9,    0}     //G
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
    else if (idGraph == 2) {
        const int sizeTable = 10;
        nodeNames = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
        const int matriceProxi[sizeTable][sizeTable]{
            //A     B     C     D     E     F     G     H     I     J
             {0,    4,    100,  100,  100,  100,  100,  100,  8,    5 },    //A
             {100,  0,    5,    100,  100,  100,  100,  100,  6,    100 },  //B
             {100,  100,  0,    6,    100,  100,  100,  100,  4,    100 },  //C
             {100,  100,  100,  0,    4,    100,  100,  5,    8,    5 },    //D
             {100,  100,  100,  100,  0,    100,  100,  3,    100,  100 },  //E
             {100,  100,  100,  100,  2,    0,    3,    3,    100,  100 },  //F
             {100,  100,  100,  100,  100,  2,    0,    100,  5,    4 },    //G
             {100,  100,  100,  4,    100,  100,  2,    0,    3,    2 },    //H
             {100,  100,  4,    100,  100,  100,  5,    100,  0,    3 },    //I
             {100,  100,  100,  100,  100,  100,  3,    100,  100,  0 },    //J
        };
        const int matriceDistance[sizeTable][sizeTable]{
            //A     B     C     D     E     F     G     H     I     J
             {0,    4,    9,    15,   16,   15,   9,    10,   5,    2 },  //A
             {4,    0,    7,    13,   14,   14,   9,    9,    4,    5 },  //B
             {9,    7,    0,    6,    8,    8,    7,    3,    5,    9 },  //C
             {15,   13,   6,    0,    2,    5,    9,    5,    10,   14 }, //D
             {16,   14,   8,    2,    0,    3,    9,    6,    11,   14 }, //E
             {15,   14,   8,    5,    3,    0,    7,    6,    10,   13 }, //F
             {9,    9,    7,    9,    9,    7,    0,    4,    5,    6 },  //G
             {10,   9,    3,    5,    6,    6,    4,    0,    5,    8 },  //H
             {5,    4,    5,    10,   11,   10,   5,    5,    0,    4 },  //I
             {2,    5,    9,    14,   14,   13,   6,    8,    4,    0 },  //J
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
