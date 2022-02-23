#ifndef SEARCH_ALGORITHM_SEARCH_H
#define SEARCH_ALGORITHM_SEARCH_H

#include "Grid.h"
#include "Node.h"
#include <ctime>

class Search {
    int startNodeID;
    int endNodeID;
    int steps;
    Grid grid;
    vector <int> previousNodes;
    vector <int> deadNodes;

    bool NodeIsRepeated(int id);
    bool NodeIsDead(int id);
    void AddUsedNode(int id);
    void AddDeadNode(int id);

public:
    Search(const string &filename, int startNodeID, int endNodeID);
    ~Search();
    void Start();

};


#endif //SEARCH_ALGORITHM_SEARCH_H
