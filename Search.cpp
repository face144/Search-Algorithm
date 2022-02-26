#include "Search.h"

Search::Search(const string& filename) {
    grid = *new Grid(filename);
}

Search::~Search() = default;

void Search::DFS(int startNodeID) {
    int currentNodeID = startNodeID;
    cout << "Current Node: " << currentNodeID << endl;
    AddVisitedNode(currentNodeID);

    vector <connection> conn = grid.GetConnections(currentNodeID);
    for (auto & i : conn) {
        if (!NodeIsVisited(i.connectedNode->GetID()))
            DepthFirstSearch(i.connectedNode->GetID());
    }
}

void Search::DepthFirstSearch(int startNodeID) {
    visitedNodes.clear();
    nodeQueue.clear();
    DFS(startNodeID);
}

void Search::BFS(int startNodeID) {
    int currentNodeID = startNodeID;
    AddVisitedNode(currentNodeID);
    AddNodeToQueue(currentNodeID);

    while(!nodeQueue.empty()) {
        currentNodeID = nodeQueue.front();
        cout << "Current Node: " << currentNodeID << endl;
        nodeQueue.pop_front();

        vector <connection> conn = grid.GetConnections(currentNodeID);
        for (auto & i : conn) {
            if (!NodeIsVisited(i.connectedNode->GetID())) {
                AddVisitedNode(i.connectedNode->GetID());
                AddNodeToQueue(i.connectedNode->GetID());
            }
        }
    }
}

void Search::BreathFirstSearch(int startNodeID) {
    visitedNodes.clear();
    nodeQueue.clear();
    BFS(startNodeID);
}

bool Search::NodeIsVisited(int id) {
    for (auto &n : visitedNodes) {
        if (n == id)
            return true;
    }
    return false;
}

bool Search::NodeIsQueued (int id) {
    for (auto &n : nodeQueue) {
        if (n == id)
            return true;
    }
    return false;
}

void Search::AddVisitedNode (int id) {
    for (auto & i : visitedNodes) {
        if (i == id)
            return;
    }
    visitedNodes.emplace_back(id);
}

void Search::AddNodeToQueue (int id) {
    for (auto & i : nodeQueue) {
        if (i == id)
            return;
    }
    nodeQueue.emplace_back(id);
}
