#ifndef SEARCH_ALGORITHM_NODE_H
#define SEARCH_ALGORITHM_NODE_H
#include <vector>

using namespace std;

class Node;

typedef struct Connection {

    Node* connectedNode;
    int cost;

}connection;

class Node {
    vector <connection> connections;
    int id;

public:
    Node(int id);
    ~Node();
    void AddConnection(Node* node, int cost = 1);
    vector <connection> GetConnections();
    int GetID();

};


#endif //SEARCH_ALGORITHM_NODE_H
