#pragma once
#include <QImage>
#include <QRgb>
#include <QColor>
#include <QString>
#include <string>

using std::string;

// Pure virtual chromosome class
class Chromosome {
public:

    // Virtual fitness function which returns a float value representing how close the chromosome is to the goal
    virtual float fitness(QImage goalPic) = 0;

    // Destructor
    virtual ~Chromosome();
};

class ChromosomePic : public Chromosome {
public:
    // Constructor
    ChromosomePic(int x, int y, QColor color);
    ChromosomePic(const ChromosomePic& other);

    // Destructor
    ~ChromosomePic();

    // Getters
    int getX();
    int getY();
    QColor getColor();

    // Fitness Function : compares chromosome image with goal-image and returns a float result
    float fitness(QImage goalPic);

private:
    QColor color;
    int x, y;
};
