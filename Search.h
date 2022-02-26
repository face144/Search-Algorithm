#ifndef SEARCH_ALGORITHM_SEARCH_H
#define SEARCH_ALGORITHM_SEARCH_H

#include "Grid.h"
#include "Node.h"
#include <ctime>
#include <list>

class Search {
    Grid grid;
    vector <int> visitedNodes;
    list <int> nodeQueue;

    bool NodeIsVisited(int id);
    bool NodeIsQueued(int id);
    void AddVisitedNode(int id);
    void AddNodeToQueue(int id);
    void DFS(int startNodeID);
    void BFS(int startNodeID);

public:
    explicit Search(const string &filename);
    ~Search();
    void BreathFirstSearch(int startNodeID);
    void DepthFirstSearch(int startNodeID);

};


#endif //SEARCH_ALGORITHM_SEARCH_H
