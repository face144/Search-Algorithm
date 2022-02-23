#include "Grid.h"

Grid::Grid() {}

Grid::Grid(const string& filename) {
    totalNodes = 0;
    fstream fs(filename);

    if (!fs.is_open())
        throw "Failed to open file.";

    while (!fs.eof()) {
        string buffer;
        getline(fs, buffer);
        int i = 0;

        if (buffer[i] == 't') {
            // Total nodes
            buffer.erase(buffer.begin());
            istringstream iss(buffer);
            iss >> totalNodes;
            for (int j = 0; j < totalNodes; ++j)
                grid.emplace_back(Node(j + 1));

        } else if (buffer[i] == 'c') {
            // Two nodes connection
            buffer.erase(buffer.begin());
            istringstream iss(buffer);
            int n1, n2;
            int cost;
            iss >> n1;
            iss >> n2;
            iss >> cost;

            Node* temp;
            bool endNodeFound = false;
            for (int j = 0; j < grid.size(); j++) {
                if (grid[j].GetID() == n2 && !endNodeFound) {
                    temp = &grid[j];
                    endNodeFound = true;
                    j = 0;
                }

                if (grid[j].GetID() == n1 && endNodeFound) {
                    grid[j].AddConnection(temp);
                }
            }
        }
    }
}

Grid::~Grid() {
    grid.erase(grid.begin(), grid.end());
}

vector <connection> Grid::GetConnections(int currentNodeID) {
    for (auto &n : grid) {
        if (n.GetID() == currentNodeID) {
            return n.GetConnections();
        }
    }
}

int Grid::GetLowestCostConnection(int currentNodeID) {
    int lowestCost = -1;
    int lowestID = -1;

    for (int i = 0; i < GetConnections(currentNodeID).size(); i++) {
        if (lowestCost == -1 && lowestID == -1) {
            lowestCost = GetConnections(currentNodeID)[i].cost;
            lowestID = GetConnections(currentNodeID)[i].connectedNode->GetID();

        } else if (lowestCost >= GetConnections(currentNodeID)[i].cost) {
            lowestCost = GetConnections(currentNodeID)[i].cost;
            lowestID = GetConnections(currentNodeID)[i].connectedNode->GetID();
        }
    }

    return lowestID;
}
