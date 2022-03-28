#include "Cell.h"

Cell::Cell(const string& chromosome, const string& target, const string& genes) {
    this->target = target;
    this->genes = genes;
    this->chromosome = chromosome;
    fitness = CalFitness();
    this->genes = genes;
    populationSize = 100;
    generation = 0;
    srand(time(0));
}

Cell::Cell(string chromosome) {
    this->target = "";
    this->genes = "";
    this->chromosome = chromosome;
    fitness = CalFitness();
    populationSize = 100;
    generation = 0;
    srand(time(0));
}

Cell Cell::Mate(Cell parent2) {
    string childChromosome = "";

    int len = chromosome.size();

    for (int i = 0; i < len; ++i) {
        float p = RandomNum(0, 100) / 100;

        if (p < .45)
            childChromosome += chromosome[i];

        else if (p < .9)
            childChromosome += parent2.chromosome[i];

        else
            childChromosome += MutatedGenes();
    }

    return Cell(childChromosome);
}

int Cell::CalFitness() {
    int len = target.size();
    int fitness = 0;

    for (int i = 0; i < len; ++i) {
        if (chromosome[i] != target[i])
            fitness++;
    }
    return fitness;
}

int Cell::RandomNum(int start, int end)
{
    int range = (end - start) + 1;
    int random_int = start + ( rand() % range );
    return random_int;
}

char Cell::MutatedGenes()
{
    int len = genes.size();
    int r = RandomNum(0, len - 1);
    return genes[r];
}

void Cell::GeneticSearch() {

}

bool Cell::operator<(const Cell &ind1) const {
    return this->GetFitness() < ind1.GetFitness();
}

int Cell::GetFitness() const {
    return fitness;
}

void Cell::SetGenes(string genes) {
    this->genes = genes;
}

void Cell::SetTarget(string target) {
    this->target = target;
}
