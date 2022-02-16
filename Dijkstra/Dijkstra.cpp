#include <iostream>
#include <vector>
using namespace std;

class Connection;

//struct ui contient les informations de la node
struct NodeRecord {
    string nodeName;
    string connection;
    int costSoFar;

    inline bool operator ==( NodeRecord t) {
        return nodeName == t.nodeName && costSoFar == t.costSoFar;
    }
};

//class qui contient les informtions des connections
class Connection {
public:
    Connection(){}
    Connection(int pCost, string pFromNode, string pToNode) { cost = pCost; fromNode = pFromNode; toNode = pToNode; }
    ~Connection(){}

    int GetCost() { return cost; }
    string GetFromNode() { return fromNode; }
    string GetToNode() { return toNode; }

private:
    int cost;
    string fromNode;
    string toNode;
};

//class qui contient les nodes
class Graph {
public:
    Graph() {
        const int sizeTable = 7;
        const vector<string> nodeNames = { "A", "B", "C", "D", "E", "F", "G" };
        int matriceProxi[sizeTable][sizeTable]{
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
                    Connection connection(cost, fromNode, toNode);
                    connections.emplace_back(connection);
                }

            }
        }
    }
    ~Graph() {}
    vector<Connection*> GetConnection(string fromNode) {
        vector<Connection*> connectionsToReturn;
        for (int i = 0; i < connections.size(); i++) {
            if (connections[i].GetFromNode() == fromNode) {
                connectionsToReturn.push_back(&connections[i]);
            }
        }
        return connectionsToReturn;
    }

    void DisplayConnection() {
        for (int i = 0; i < connections.size(); i++) {
            cout << connections[i].GetFromNode() << " -> " << connections[i].GetToNode() << " = " << connections[i].GetCost() << endl;
        }
    }
private:
    vector<Connection> connections;
};

//class pour faire liste de nodes
class PathfindingList {
public:
    PathfindingList(){}
    ~PathfindingList(){}

    NodeRecord GetSmallestElement() {
        int smallerCost = 100;
        NodeRecord nodeToReturn;
        for (int i = 0; i < nodes.size(); i++) {
            int cost = nodes[i].costSoFar;
            if (cost < smallerCost) {
                smallerCost = cost;
                nodeToReturn = nodes[i];
            }
        }
        return nodeToReturn;
    }

    bool IsContain(string nodeName) {
        for (int i = 0; i < nodes.size(); i++) {
            if (nodeName == nodes[i].nodeName) {
                return true;
            }
        }
        return false;
    }

    void Add(NodeRecord node) {
        nodes.push_back(node);
        length++;
    }

    void Remove(string nodeName) {
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

    int GetLen() { return length; }

    void DisplayNodes() {
        for (int i = 0; i < nodes.size(); i++) {
            cout << nodes[i].connection << " " << nodes[i].costSoFar << " (colonne " << nodes[i].nodeName << ")" <<  endl;
        }
    }

private:
    vector<NodeRecord> nodes;
    int length = 0;
};

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
            cout << "connection trouve : " << currentConnections[i]->GetFromNode() << " -> " << currentConnections[i]->GetToNode() << " = " << currentConnections[i]->GetCost() << endl;
            //on get le cost et la toNode
            string endNodeName = currentConnections[i]->GetToNode();
            int endNodeCost = currentConnections[i]->GetCost() + currentNode.costSoFar;

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

    closedList.DisplayNodes();
}

int main(){
    Graph graph;

    //graph.DisplayConnection();

    pathfindDijkstra(graph, "A", "G");

    return 0;
}