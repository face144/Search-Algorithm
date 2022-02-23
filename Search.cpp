#include "Search.h"

Search::Search(const string& filename, int startNodeID, int endNodeID) {
    this->startNodeID = startNodeID;
    this->endNodeID = endNodeID;
    steps = 0;
    grid = *new Grid(filename);
    srand(time(NULL));
}

Search::~Search() {

}

void Search::Start() {
    int currentNodeID = startNodeID;
    cout << "--- Search Start ---" << endl;
    cout << "Starting on Node " << currentNodeID << endl << endl;

    do {
        steps++;
        if (!NodeIsDead(currentNodeID)) {
            if (NodeIsDead(grid.GetLowestCostConnection(currentNodeID)))

        }

        cout << "Step Number: " << steps << endl;
        cout << "Current Node ID: " << currentNodeID << endl << endl;

    } while (currentNodeID != endNodeID);
    cout << "--- Search End ---" << endl;
    cout << "Solution Found!" << endl;

    system("pause");
}

bool Search::NodeIsRepeated(int id) {
    for (auto &n : previousNodes) {
        if (n == id)
            return true;
    }
    return false;
}

bool Search::NodeIsDead(int id) {
    for (auto &n : deadNodes) {
        if (n == id)
            return true;
    }
    return false;
}

void Search::AddUsedNode(int id) {
    for (auto & i : previousNodes) {
        if (i == id)
            return;
    }
    previousNodes.emplace_back(id);
}

void Search::AddDeadNode(int id) {
    for (auto & i : deadNodes) {
        if (i == id)
            return;
    }
    deadNodes.emplace_back(id);
}
