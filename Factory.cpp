#include "Factory.h"

ImgSelection::ImgSelection(QImage goalPic)
{
    this->goalPic = goalPic;
}

void ImgSelection::select(map<std::pair<int, int>, Chromosome*>& population)
{
    // Calculate average fitness
    float fitness = 0;
    for (auto chromosome = population.begin(); chromosome != population.end(); ++chromosome)
        fitness += dynamic_cast<ChromosomePic*>(chromosome->second)->fitness(goalPic);

    fitness /= population.size();

    // Select the 'fittest'
    for (auto chromosome = population.begin(); chromosome != population.end();)
    {
        ChromosomePic *pic = dynamic_cast<ChromosomePic*>(chromosome->second);

        int selectionCount;
        selectionCount = fitness * 110 / 100;

        if (pic->fitness(this->goalPic) > selectionCount) {
            population.erase(chromosome++);
        }
        else
             ++chromosome;

    }
}

Factory::Factory()
{
    this->goalImg = QImage("C:/Users/seNNNz0rel/Documents/Lab Sem II/GeneticalAlgorithm/imgExample.png");
    this->selection = new ImgSelection(goalImg);

}

Factory::Factory(std::string imgPath)
{
    this->goalImg = QImage(QString::fromStdString(imgPath));
    this->selection = new ImgSelection(goalImg);
}

Factory::Factory(ImgSelection *selection)
{
    this->selection = selection;
}

Factory::Factory(const Factory &other)
{
    this->goalImg = other.goalImg;
    this->selection = other.selection;
}

void Factory::create(map<std::pair<int, int>, Chromosome*>& population)
{
    // If the 'organism' is empty, we create 50 random pixels to fill the picture
    if (population.size() <= 5)
        for (int i = 0; i < 10000; i++) {
            // random pos
            int randX = rand() % (goalImg.width() - 1) + 1;
            int randY = rand() % (goalImg.height() - 1) + 1;

            // rand colors
            int randR = rand() % 255 + 1;
            int randG = rand() % 255 + 1;
            int randB = rand() % 255 + 1;
            population.emplace(std::make_pair(std::make_pair(randX, randY), new ChromosomePic(randX,
                                                   randY,
                                                   QColor(randR, randG, randB))));
        }

    // Go through each 2 chromosomes and combine them, choosing an equal amount of 'genes' from both of them
    selection->select(population);

    // build vector in order to access random keys
    vector<std::pair<int, int>> randomm;

    for (auto it = population.begin(); it != population.end(); ++it)
        randomm.push_back(it->first);

    // Choose a percentage to combine based on how many pixels there are
    int nrToCombine;
    if (population.size() < 1000)
        nrToCombine = population.size() * 50 / 100;
    else if (population.size() > 1000)
        nrToCombine = population.size() * 25 / 100;
    else
        nrToCombine = population.size() * 15 / 10000;

    for (int i = 0; i < nrToCombine; i++)
    {
        auto f = population.find(randomm[rand() % (randomm.size() - 1) + 0]);
        auto s = population.find(randomm[rand() % (randomm.size() - 1) + 0]);

        Chromosome *newC = combine(f->second, s->second);

        // If chromosome exists already, pick the one with a better fitness
        population.emplace(std::make_pair(std::make_pair(dynamic_cast<ChromosomePic*>(newC)->getX(), dynamic_cast<ChromosomePic*>(newC)->getY()), newC));
    }

}

Chromosome *Factory::combine(Chromosome *fChromosome, Chromosome *sChromosome)
{
    // Create new chromosome
    ChromosomePic* newChromosome;

    ChromosomePic* f = dynamic_cast<ChromosomePic*>(fChromosome);
    ChromosomePic* s = dynamic_cast<ChromosomePic*>(sChromosome);

    // If first and second chromosomes are equal we have asexual reproduction
    if (fChromosome == sChromosome) {
        // random pos
        int randX = rand() % (goalImg.width() - 1) + 1;
        int randY = rand() % (goalImg.height() - 1) + 1;

        // rand colors
        int randR = rand() % 255 + 0;
        int randG = rand() % 255 + 0;
        int randB = rand() % 255 + 0;

        ChromosomePic* randChromosome = new ChromosomePic(randX,
                                                          randY,
                                                          QColor(randR, randG, randB));
        // Pick random traits from both chromosomes

        // Pick random colors
        if ((rand() % 1 + 0) % 2 == 0)
            randR = f->getColor().red();
        else
            randR = randChromosome->getColor().red();

        if ((rand() % 1 + 0) % 2 == 0)
            randG = f->getColor().green();
        else
            randG = randChromosome->getColor().green();

        if ((rand() % 1 + 0) % 2 == 0)
            randB = f->getColor().blue();
        else
            randB = randChromosome->getColor().blue();

        // Pick random positions

        randX = rand() % (this->goalImg.width() - 1) + 1;
        randY = rand() % (this->goalImg.height() - 1) + 1;

        newChromosome = new ChromosomePic(randX, randY, QColor(randR, randG, randB));

        delete randChromosome;
        return newChromosome;
    }
    else {
        // Pick random traits from both chromosomes

        int randR, randG, randB, randX, randY;

        // Pick random colors
        if ((rand() % 1 + 0) % 2 == 0)
            randR = f->getColor().red();
        else
            randR = s->getColor().red();

        if ((rand() % 1 + 0) % 2 == 0)
            randG = f->getColor().green();
        else
            randG = s->getColor().green();

        if ((rand() % 1 + 0) % 2 == 0)
            randB = f->getColor().blue();
        else
            randB = s->getColor().blue();

        // Pick random positions

        randX = rand() % (this->goalImg.width() - 1) + 1;
        randY = rand() % (this->goalImg.height() - 1) + 1;

        newChromosome = new ChromosomePic(randX, randY, QColor(randR, randG, randB));

        return newChromosome;
    }
}
