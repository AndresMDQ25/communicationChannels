#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
//#include <QPair>
#include <QFileDialog>
#include <QPixmap>
#include "imageanalyzer.h"
#include "communicationchannel.h"
#include "probabilitiescalculator.h"
#include "about.h"
#include <QDebug>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_selectFileButton_clicked();
    void on_startButton_clicked();
    void on_aboutButton_clicked();

private:
    Ui::MainWindow *ui;
    QString filePath;
    QString getFileName();
    QString fileName;
    QVector< QPair<QString, int> > colorCount;
    QVector< QPair<QString, double> > colorProbs;
    double **matrix;
    double noise;
    double loss;
    QPair<QString, double> lostSymbol;



    void displayText();
    void displayDataText();
    void startTable();

    ImageAnalyzer IA;
    ProbabilitiesCalculator PC;
    CommunicationChannel CC;
    About aboutWindow;
};

#endif // MAINWINDOW_H
