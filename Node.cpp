#include "Node.h"

Node::Node(int id) {
    this->id = id;
}

Node::~Node() {

}

void Node::AddConnection(Node* node, int cost) {
    connection conn;
    conn.connectedNode = node;
    conn.cost = cost;
    if (cost <= 0)
        throw "Connection cost invalid!";
    connections.push_back(conn);
}

int Node::GetID() {
    return id;
}

vector <connection> Node::GetConnections() {
    return connections;
}
