#include "Dijkstra.h"
#include "PathFindingList.h"
#include <iostream>
using namespace std;

void pathfindDijkstra(Graph graph, string start, string end) {

    //initialiser la 1ere node
    NodeRecord startRecord = { start, "", 0 };

    //initialiser le openlist et la closedlist
    PathfindingList openList;
    openList.Add(startRecord);
    PathfindingList closedList;

    //on iter tant qu'il y a des nodes dans l'open list
    while (openList.GetLen() > 0) {
        cout << "==================================" << endl;

        //La node que l'on va étudier (current node) est celle avec le plus petit cost
        NodeRecord currentNode = openList.GetSmallestElement();
        cout << "La node etudie est " << currentNode.connection << " " << currentNode.costSoFar << " (colonne " << currentNode.nodeName << ")" << endl;
        //si current est le goal, on a finit donc on break
        if (currentNode.nodeName == end) {
            cout << "on est arrive a " << end << endl;
            closedList.Add(currentNode);
            break;
        }

        //sinon, get un vector de pointeurs vers les connections de la currentNode
        vector<Connection*> currentConnections = graph.GetConnection(currentNode.nodeName);

        //et on loop les connections
        for (int i = 0; i < currentConnections.size(); i++) {
            cout << "connection trouve : " << currentConnections[i]->fromNode << " -> " << currentConnections[i]->toNode << " = " << currentConnections[i]->cost << endl;
            //on get le cost et la toNode
            string endNodeName = currentConnections[i]->toNode;
            int endNodeCost = currentConnections[i]->cost + currentNode.costSoFar;

            //skip si la toNode est closed
            if (closedList.IsContain(endNodeName)) {
                cout << "Mais cette colonne est bloque." << endl;
                continue;
            }
            //sinon on créer le nodeRecord et on l'ajoute à l'openList
            else {
                NodeRecord node = { endNodeName, currentNode.nodeName, endNodeCost };
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
        cout << "There is no solution... You can't go from " << start << " to " << end<< "." << endl;
    }

    //afficher le resultat
    if(openList.GetLen() >0 ){
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