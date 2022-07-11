#include "Chromosome.h"



Chromosome::~Chromosome()
{
}

ChromosomePic::ChromosomePic(int x, int y, QColor color)
{
    this->x = x;
    this->y = y;
    this->color = color;
}

ChromosomePic::ChromosomePic(const ChromosomePic &other)
{
    this->x = other.x;
    this->y = other.y;
    this->color = other.color;
}

ChromosomePic::~ChromosomePic()
{
}

int ChromosomePic::getX()
{
    return this->x;
}

int ChromosomePic::getY()
{
    return this->y;
}

QColor ChromosomePic::getColor()
{
    return this->color;
}

float ChromosomePic::fitness(QImage goalPic)
{
    return (abs(goalPic.pixelColor(x, y).blue() - color.blue()) +
            abs(goalPic.pixelColor(x, y).red() - color.red()) +
            abs(goalPic.pixelColor(x, y).green() - color.green()));
}
