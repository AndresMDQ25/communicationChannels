#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->compressButton->setDisabled(true);
    ui->extendButton->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selectFileButton_clicked()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::AnyFile);
    //dialog.setNameFilter("Image");
    int result = dialog.exec();
    if (result)
        filePath = dialog.selectedFiles().first();
    else
        filePath = "";
    fileName = getFileName();
    this->displayText();
}

QString MainWindow::getFileName()
{
    QChar a = '/'; //if normal OS
    int index = filePath.lastIndexOf(a);
    if (index == -1){ //if Windows
        a = '\\';
        index = filePath.lastIndexOf(a);
    }
    int n = filePath.size()-index-1;
    return filePath.right(n);
}

void MainWindow::displayText()
{
    ui->fileNameBox->setText(fileName);
}

void MainWindow::startTable()
{
    /*ui->solutionTable->setColumnCount(0);
    for (int j = 0; j < orderOneSymbols.size(); j++) {
        ui->solutionTable->insertColumn(j);
        QString orderOneSymbolstring;
        orderOneSymbolstring.append("{");
        for (int i = 0; i < orderOneSymbols.at(j).getColors().size(); i++) {
            if (i != 0) {
                orderOneSymbolstring.append(", ");
            }
            orderOneSymbolstring.append(orderOneSymbols.at(j).getColors().at(i));
        }
        orderOneSymbolstring.append("}");
        QTableWidgetItem *item = new QTableWidgetItem(orderOneSymbolstring);
        ui->solutionTable->setItem(0, j,item);
        QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(orderOneSymbols.at(j).getProbability()));
        ui->solutionTable->setItem(1, j, item2);
        QTableWidgetItem *item3 = new QTableWidgetItem(orderOneSymbols.at(j).getHuffmanCode());
        ui->solutionTable->setItem(2, j, item3);
    }*/
}

void MainWindow::on_startButton_clicked()
{
    IA.start(filePath);
    this->colors = IA.getColors();
    //Calcular la matriz
    this->startTable();
}

void MainWindow::on_aboutButton_clicked()
{
    aboutWindow.setWindowTitle("About");
    aboutWindow.show();
}
