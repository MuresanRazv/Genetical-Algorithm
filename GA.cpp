#include "GA.h"

GA::GA()
{
    this->factory = Factory();
}

GA::GA(std::string imgPath)
{
    this->factory = Factory(imgPath);
}

GA::GA(const GA &other)
{
    this->factory = other.factory;
    this->population = other.population;
}

GA::~GA()
{
}

void GA::select()
{
    srand(time(NULL));
    this->factory.create(this->population);
}

QImage GA::returnOrganism()
{
    qDebug() << population.size();

    QImage organism = QImage("C:/Users/seNNNz0rel/Documents/Lab Sem II/GeneticalAlgorithm/blankJpg.png");
    QImage goalImg = QImage("C:/Users/seNNNz0rel/Documents/Lab Sem II/GeneticalAlgorithm/example3.png");

    for (auto ch = population.begin(); ch != population.end(); ++ch) {
        organism.setPixelColor(dynamic_cast<ChromosomePic*>(ch->second)->getX(),
                         dynamic_cast<ChromosomePic*>(ch->second)->getY(),
                        dynamic_cast<ChromosomePic*>(ch->second)->getColor());
    }

    return organism;
}


void GA::run()
{
    this->select();
}
