#pragma once
#include <string>
#include <vector>
#include <map>
#include "Chromosome.h"
#include <random>
#include <QDebug>
#include <utility>
#include <iterator>

using std::string;
using std::vector;
using std::map;

class Selection {
public:
    virtual void select(map<std::pair<int, int>, Chromosome*>& population) = 0;
};

class ImgSelection : public Selection {
public:
    // Constructor
    ImgSelection(QImage goalPic);

    // Select function
    void select(map<std::pair<int, int>, Chromosome*>& population);
private:
    QImage goalPic;
};

class Factory {
public:
    // Constructor
    Factory();
    Factory(string imgPath);
    Factory(ImgSelection* selection);
    Factory(const Factory& other);

    // Create a new generation by combining fittest chromosomes
    void create(map<std::pair<int, int>, Chromosome*>& population);

    // Combine two chromosomes
    Chromosome* combine(Chromosome* fChromosome, Chromosome* sChromosome);


private:
    Selection* selection;
    QImage goalImg;
};
