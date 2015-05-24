#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QPixmap>
#include "imageanalyzer.h"
#include "communicationchannel.h"
#include "about.h"


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

    void on_extendButton_clicked();

    void on_compressButton_clicked();

    void on_decompressButton_clicked();

private:
    Ui::MainWindow *ui;
    QString filePath;
    QString getFileName();
    QString fileName;
    QVector<QString> colors;



    void displayText();
    void displayDataText();
    void startTable();

    ImageAnalyzer IA;
    About aboutWindow;
};

#endif // MAINWINDOW_H
