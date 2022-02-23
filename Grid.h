#ifndef SEARCH_ALGORITHM_GRID_H
#define SEARCH_ALGORITHM_GRID_H
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Node.h"

using namespace std;

class Grid {
    vector <Node> grid;
    int totalNodes;
    vector <connection> GetConnections(int currentNodeID);

public:
    Grid();
    Grid(const string& filename);
    ~Grid();
    int GetLowestCostConnection(int currentNode);
};


#endif //SEARCH_ALGORITHM_GRID_H
