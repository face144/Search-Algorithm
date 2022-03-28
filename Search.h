#ifndef SEARCH_ALGORITHM_SEARCH_H
#define SEARCH_ALGORITHM_SEARCH_H

#include "Grid.h"
#include "Node.h"
#include "Cell.h"
#include <ctime>
#include <list>

class Search {
    Grid grid;
    vector <int> visitedNodes;
    list <int> nodeQueue;

    unsigned populationSize, generation;
    vector <Cell> population;
    string target, genes;

    string CreateGnome();
    chat MutatedGened();

    bool NodeIsVisited(int id);
    bool NodeIsQueued(int id);
    void AddVisitedNode(int id);
    void AddNodeToQueue(int id);
    void DFS(int startNodeID);
    void BFS(int startNodeID);

public:
    explicit Search(const string &filename);
    Search();
    ~Search();
    void BreathFirstSearch(int startNodeID);
    void DepthFirstSearch(int startNodeID);
    void GeneticSearch(string target, string genes);

};


#endif //SEARCH_ALGORITHM_SEARCH_H
