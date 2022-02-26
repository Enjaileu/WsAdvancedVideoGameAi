#include "Graph.h"
#include "Pathfinding.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    cout << " ##### PATHFINDING MACHINE #####" << endl;
    cout << endl;
    bool finish = false;
    while (!finish) {

        //choose the graph
        cout << "Welcome to the pathfinding machine. This algorithm will give you the fastest path between two destinations. \nFirst, choose your graph (you can see how they look in the folder graph) :" << endl;
        int choice = 0;
        do {
            cout << "1 -> Graph 1" << endl;
            cout << "2 -> Graph 2" << endl;
            cin >> choice;
            cout << choice << endl;
            if (choice != 1 && choice != 2) {
                cout << "Your answer is incorrect." << endl;
            }
        } while (choice != 1 && choice != 2);
        cout << "You choose the graph " << choice << "." << endl;
        Graph graph(choice);
        cout << endl;

        //choose the start point and the end point
        string start = "";
        string end = "";
        cout << "Where begins your path ?" << endl;
        do {
            cout << "Choose between this destinations : " << endl;
            graph.DisplayNodeNames();
            cin >> start;
        } while (graph.IsInNodeList(start) == false);
        cout << endl;
        cout << "Now, where does it end?" << endl;
        do {

            cout << "Choose between this destinations : " << endl;
            graph.DisplayNodeNames(start);
            cin >> end;
        } while (graph.IsInNodeList(end) == false || end == start);
        cout << endl << "Your path is " << start << " -> " << end << endl;

        //choose the algorithm
        cout << endl << "Well done, now the pathfinding machine will find the fastest path from " << start << " to " << end << "." << endl;
        cout << "Wich algorithm do you want to use?" << endl;
        choice = -1;
        do {
            cout << "1 -> Dijkstra." << endl;
            cout << "2 -> A*." << endl;
            cin >> choice;
        } while (choice != 1 && choice != 2);

        if (choice == 1) {
            pathfindDijkstra(graph, start, end);
        }
        else {
            pathfindAstar(graph, start, end);
        }

        //try again?
        cout << endl;
        cout << "Do you want to try again?" << endl;
        string answer = "";
        do {
            cout << "Choose between \"yes\" and \"no\"." << endl;
            cin >> answer;
        } while (answer != "yes" && answer != "no");

        if (answer == "no") {
            cout << "Ok bye! Thanks for use the pathfinding machine !" << endl;
            finish = true;
        }
    }
     
    return 0;
}