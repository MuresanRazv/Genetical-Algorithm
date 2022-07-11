#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QWidget>
#include <QObject>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QMainWindow>
#include <QString>
#include <QShortcut>
#include <QKeyEvent>
#include <QEventLoop>
#include "GA.h"

class UI : public QMainWindow
{
    Q_OBJECT

public:
    UI(QWidget *parent = nullptr);
    ~UI();
    void createUI();

private:
    // Layouts
    QVBoxLayout *m_vLayout;
    QVBoxLayout *m_lowerBtnLayout;
    QVBoxLayout *m_upperLayout;
    QHBoxLayout *m_upperLayout2;
    QVBoxLayout *m_lowerLayout;

    // Combo Box
    QComboBox *m_choosePic;

    // Labels
    QLabel *goalImgLabel;
    QLabel *chromosomeImgLabel;

    // Buttons
    QPushButton *btn1X;
    QPushButton *btn5X;
    QPushButton *btn25X;
    QPushButton *btn125X;
    QPushButton *btn500X;
    QPushButton *btn1000X;
    QPushButton *btn10000X;

    QPushButton *startBtn;
    QPushButton *stopBtn;

    // Genetic Algorithm
    GA genAlg;
    bool reproduce;


public slots:
    //void handleStart();
    //void handleStop();
    void handle1x();
    void handle5x();
    void handle25x();
    void handle125x();
    void handle500x();
    void handle1000x();
    void handle10000x();

    void handleChangedPic(int);

};

#endif // MAINWINDOW_H
