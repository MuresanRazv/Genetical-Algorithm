#include "UI.h"

UI::UI(QWidget *parent) : QMainWindow(parent)
{
    this->genAlg = GA();
    this->createUI();
}

UI::~UI()
{
}

void UI::createUI()
{
    QWidget* mainWidget{new QWidget};
    this->setCentralWidget(mainWidget);

    // Init Labels
    this->goalImgLabel = new QLabel("", mainWidget);
    this->goalImgLabel->setPixmap(QPixmap::fromImage(QImage("C:/Users/seNNNz0rel/Documents/Lab Sem II/GeneticalAlgorithm/imgExample.png")));

    this->chromosomeImgLabel = new QLabel("", mainWidget);

    // Init combobox
    this->m_choosePic = new QComboBox();

    this->m_choosePic->addItem("Example 1");
    this->m_choosePic->addItem("Example 2");
    this->m_choosePic->addItem("Example 3");

    QObject::connect(m_choosePic, SIGNAL(currentIndexChanged(int)), this, SLOT(handleChangedPic(int)));

    // Init for button
    this->btn1X = new QPushButton{"1X"};
    this->btn5X = new QPushButton{"5X"};
    this->btn25X = new QPushButton{"25X"};
    this->btn125X = new QPushButton{"125X"};
    this->btn500X = new QPushButton{"500X"};
    this->btn1000X = new QPushButton{"1000X"};
    this->btn10000X = new QPushButton{"10000X"};

    // Connect Button
    QObject::connect(btn1X, SIGNAL(clicked(bool)), this, SLOT(handle1x()));
    QObject::connect(btn5X, SIGNAL(clicked(bool)), this, SLOT(handle5x()));
    QObject::connect(btn25X, SIGNAL(clicked(bool)), this, SLOT(handle25x()));
    QObject::connect(btn125X, SIGNAL(clicked(bool)), this, SLOT(handle125x()));
    QObject::connect(btn500X, SIGNAL(clicked(bool)), this, SLOT(handle500x()));
    QObject::connect(btn1000X, SIGNAL(clicked(bool)), this, SLOT(handle1000x()));
    QObject::connect(btn10000X, SIGNAL(clicked(bool)), this, SLOT(handle10000x()));

    // Set Layouts
    this->m_vLayout = new QVBoxLayout();
    this->m_upperLayout = new QVBoxLayout();
    this->m_lowerLayout = new QVBoxLayout();
    this->m_upperLayout2 = new QHBoxLayout();
    this->m_lowerBtnLayout = new QVBoxLayout();

    this->m_upperLayout->addWidget(goalImgLabel);
    this->m_upperLayout2->addLayout(m_upperLayout);

    this->m_upperLayout2->addWidget(this->m_choosePic);

    this->m_lowerBtnLayout->addWidget(btn1X);
    this->m_lowerBtnLayout->addWidget(btn5X);
    this->m_lowerBtnLayout->addWidget(btn25X);
    this->m_lowerBtnLayout->addWidget(btn125X);
    this->m_lowerBtnLayout->addWidget(btn500X);
    this->m_lowerBtnLayout->addWidget(btn1000X);
    this->m_lowerBtnLayout->addWidget(btn10000X);

    this->m_lowerLayout->addWidget(chromosomeImgLabel);
    this->m_lowerLayout->addLayout(m_lowerBtnLayout);

    this->m_vLayout->addLayout(m_upperLayout2);
    this->m_vLayout->addLayout(m_lowerLayout);

    this->setGeometry(400, 100, 500, 500);

    mainWidget->setLayout(this->m_vLayout);
}

void UI::handle1x()
{
    // Start GA loop

        this->genAlg.run();

    // Show population
    this->chromosomeImgLabel->setPixmap(QPixmap::fromImage(this->genAlg.returnOrganism()));
}


void UI::handle5x()
{
    // Start GA loop
    for (int i = 0; i < 5; i++)
        this->genAlg.run();

    // Show population
    this->chromosomeImgLabel->setPixmap(QPixmap::fromImage(this->genAlg.returnOrganism()));
}


void UI::handle25x()
{
    // Start GA loop
for (int i = 0; i < 25; i++)
        this->genAlg.run();

    // Show population
    this->chromosomeImgLabel->setPixmap(QPixmap::fromImage(this->genAlg.returnOrganism()));
}


void UI::handle125x()
{
    // Start GA loop
    for (int i = 0; i < 125; i++)
        this->genAlg.run();

    // Show population
    this->chromosomeImgLabel->setPixmap(QPixmap::fromImage(this->genAlg.returnOrganism()));
}


void UI::handle500x()
{
    // Start GA loop
for (int i = 0; i < 500; i++)
        this->genAlg.run();

    // Show population
    this->chromosomeImgLabel->setPixmap(QPixmap::fromImage(this->genAlg.returnOrganism()));
}


void UI::handle1000x()
{
    // Start GA loop
    for (int i = 0; i < 1000; i++)
        this->genAlg.run();

    // Show population
    this->chromosomeImgLabel->setPixmap(QPixmap::fromImage(this->genAlg.returnOrganism()));
}


void UI::handle10000x()
{
    // Start GA loop
    for (int i = 0; i < 10000; i++)
        this->genAlg.run();

    // Show population
    this->chromosomeImgLabel->setPixmap(QPixmap::fromImage(this->genAlg.returnOrganism()));
}

void UI::handleChangedPic(int i)
{
    if (i == 0) {
        this->genAlg = GA("C:/Users/seNNNz0rel/Documents/Lab Sem II/GeneticalAlgorithm/imgExample.png");
        this->goalImgLabel->setPixmap(QPixmap::fromImage(QImage("C:/Users/seNNNz0rel/Documents/Lab Sem II/GeneticalAlgorithm/imgExample.png")));

    }
    else if (i == 1) {
        this->genAlg = GA("C:/Users/seNNNz0rel/Documents/Lab Sem II/GeneticalAlgorithm/example2.png");
        this->goalImgLabel->setPixmap(QPixmap::fromImage(QImage("C:/Users/seNNNz0rel/Documents/Lab Sem II/GeneticalAlgorithm/example2.png")));
    }
    else {
        this->genAlg = GA("C:/Users/seNNNz0rel/Documents/Lab Sem II/GeneticalAlgorithm/example3.png");
        this->goalImgLabel->setPixmap(QPixmap::fromImage(QImage("C:/Users/seNNNz0rel/Documents/Lab Sem II/GeneticalAlgorithm/example3.png")));
    }
}
