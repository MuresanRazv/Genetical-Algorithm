#pragma once
#include <vector>
#include "Chromosome.h"
#include "Factory.h"
#include <QDebug>

using std::vector;


class GA : public Factory{
public:
    // Constructor
    GA();
    GA(string imgPath);
    GA(const GA& other);

    // Destructor
    ~GA();

    // Operations
    void select();
    QImage returnOrganism();
    void run();

private:
    map<std::pair<int, int>, Chromosome*> population;
    Factory factory;
};
