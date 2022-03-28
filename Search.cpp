#include "Search.h"

Search::Search(const string& filename) {
    grid = *new Grid(filename);
}

Search::Search() {

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

void Search::GeneticSearch(string target, string genes) {

    bool found = false;
    for (int i = 0; i < populationSize; i++) {
        string gnome = CreateGnome();
        population.emplace_back(Cell(gnome));
    }

    while (!found) {
        sort(population.begin(), population.end());

        if (population[0].GetFitness() <= 0) {
            found = true;
            break;
        }

        vector <Cell> newPopulation;

        int s = (10 * populationSize) / 100;
        for (int i = 0; i < s; ++i) {
            newPopulation.push_back(population[i]);
        }

        s = (90 * populationSize) / 100;
        for (int i = 0; i < s; ++i) {
            int len = population.size();
            int r = RandomNum(0, 50);
            Cell parent1 = population[r];
            r = RandomNum(0, 50);
            Cell parent2 = population[r];
            Cell offspring = parent1.Mate(parent2);
            newPopulation.push_back(offspring);
        }

        population = newPopulation;

        cout<< "Generation: " << generation << "\t";
        cout<< "String: "<< population[0].chromosome <<"\t";
        cout<< "Fitness: "<< population[0].fitness << "\n";

        generation++;
    }

    cout<< "Generation: " << generation << "\t";
    cout<< "String: "<< population[0].chromosome <<"\t";
    cout<< "Fitness: "<< population[0].fitness << "\n";
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

string Search::CreateGnome() {
    int len = target.size();
    string gnome = "";
    for (int i = 0; i < len; ++i) {
        gnome += MutatedGenes();
    }
    return gnome;
}

char Search::MutatedGenes()
{
    int len = genes.size();
    int r = RandomNum(0, len - 1);
    return genes[r];
}
