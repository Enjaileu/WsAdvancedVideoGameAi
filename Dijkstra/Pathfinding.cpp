#include "Pathfinding.h"
#include "PathFindingList.h"
#include <iostream>
using namespace std;

void pathfindDijkstra(Graph graph, string start, string end) {
    //initialisation
    NodeRecord startRecord = { start, "", 0, 0 };

    PathfindingList openList;
    openList.Add(startRecord);
    PathfindingList closedList;

    //while there is nodes in openlist
    while (openList.GetLen() > 0) {
        //currentNode is the one with smallest costSoFar. It is finish if currentnode = endNode
        NodeRecord currentNode = openList.GetSmallestElement();
        if (currentNode.nodeName == end) {
            closedList.Add(currentNode);
            break;
        }

        //loop with connections
        vector<Connection*> currentConnections = graph.GetConnection(currentNode.nodeName);
        for (int i = 0; i < currentConnections.size(); i++) {
            string endNodeName = currentConnections[i]->toNode;
            int endNodeCost = currentConnections[i]->cost + currentNode.costSoFar;

            if (closedList.IsContain(endNodeName)) {
                continue;
            }
            else {
                NodeRecord node = { endNodeName, currentNode.nodeName, 0, endNodeCost };
                openList.Add(node);
            }
        }
        //parmi les nodes de l'openList, trouver celui avec le + petit costSoFar, l'enlever de l'open et la mettre dans closed
        NodeRecord newMinimum = openList.GetSmallestElement();
        openList.Remove(newMinimum.nodeName);
        closedList.Add(newMinimum);
    }
    if (openList.GetLen() == 0) {
    }

    //display result
    if (openList.GetLen() > 0) {
        vector<string> reversePath;
        reversePath.push_back(end);
        string step = end;
        while (step != start) {
            NodeRecord* node = closedList.GetNode(step);
            string connection = node->connection;
            reversePath.push_back(connection);
            step = connection;
        }

        cout << "The faster path is : ";
        for (int i = reversePath.size() - 1; i > -1; i--) {
            cout << reversePath[i] << " ";
            if (i > 0) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
}


void pathfindAstar(Graph graph, string start, string end) {
    //initialisation
    int initialDistance = graph.GetDistance(start, end);
    NodeRecord startRecord = { start, "", initialDistance, initialDistance };

    PathfindingList openList;
    openList.Add(startRecord);
    PathfindingList closedList;

    //while there is nodes in openlist
    while (openList.GetLen() > 0) {
        //currentNode is the one with smallest costSoFar. It is finish if currentnode = endNode
        NodeRecord currentNode = openList.GetSmallestElement();
        if (currentNode.nodeName == end) {
            closedList.Add(currentNode);
            break;
        }

        //loop connections
        vector<Connection*> currentConnections = graph.GetConnection(currentNode.nodeName);
        for (int i = 0; i < currentConnections.size(); i++) {
            string endNodeName = currentConnections[i]->toNode;
            int endNodeDistance = graph.GetDistance(endNodeName, end);
            int endNodeCost = currentConnections[i]->cost + currentNode.costSoFar + endNodeDistance;

            //skip if toNode is closed
            if (closedList.IsContain(endNodeName)) {
                cout << "Mais cette colonne est bloque." << endl;
                continue;
            }
            //else we add the toNode in openList
            else {
                NodeRecord node = { endNodeName, currentNode.nodeName, endNodeDistance, endNodeCost };
                openList.Add(node);
            }
        }

        //parmi les nodes de l'openList, trouver celui avec le + petit costSoFar, l'enlever de l'open et la mettre dans closed
        NodeRecord newMinimum = openList.GetSmallestElement();
        openList.Remove(newMinimum.nodeName);
        closedList.Add(newMinimum);

        cout << "La openList contient : " << endl;
        openList.DisplayNodes();
        cout << "La closedList contient : " << endl;
        closedList.DisplayNodes();
    }
    if (openList.GetLen() == 0) {
        cout << "There is no solution... You can't go from " << start << " to " << end << "." << endl;
    }

    //display result
    if (openList.GetLen() > 0) {
        vector<string> reversePath;
        reversePath.push_back(end);
        string step = end;
        while (step != start) {
            NodeRecord* node = closedList.GetNode(step);
            string connection = node->connection;
            reversePath.push_back(connection);
            step = connection;
        }

        cout << "The faster path is : ";
        for (int i = reversePath.size() - 1; i > -1; i--) {
            cout << reversePath[i] << " ";
            if (i > 0) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
}