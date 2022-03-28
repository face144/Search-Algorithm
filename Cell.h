#ifndef SEARCH_ALGORITHM_CELL_H
#define SEARCH_ALGORITHM_CELL_H
#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Cell {
    string chromosome;
    int fitness;
    string genes, target;

    int CalFitness();
    static int RandomNum(int start, int end);
    char MutatedGenes();

public:
    Cell(string chromosome);
    Cell Mate(Cell parent2);
    void GeneticSearch();
    int GetFitness() const;
    void SetGenes(string genes);
    void SetTarget(string target);
    bool operator<(const Cell &ind1) const;
};


#endif //SEARCH_ALGORITHM_CELL_H
