#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    ui->matrixTable->setColumnCount(0);
    ui->matrixTable->setRowCount(0);
    for (int x = 0; x < colorCount.size(); x++) {
        ui->matrixTable->insertColumn(x);
        for (int y = 0; y < colorCount.size(); y++) {
            if (ui->matrixTable->rowCount() < colorCount.size())
                ui->matrixTable->insertRow(y);
            double prob = this->matrix[x][y];
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(prob));
            ui->matrixTable->setItem(y, x, item);
        }
    }
    ui->noiseBox->setText(QString::number(this->noise));
}

void MainWindow::on_startButton_clicked()
{
    IA.start(filePath);
    this->colorCount = IA.getColorCount();
    PC.calculate(this->colorCount, IA.getTotalPixels());
    this->colorProbs = PC.getProbabilities();

    //Calcular la matriz

    CC.generateMatrix(this->colorProbs);
    this->matrix = CC.getMatrix();
    CC.calculateNoise();
    qDebug() << "EL RUIDO ES DE: " << CC.getNoise();
    this->noise = CC.getNoise();
    this->startTable();





}

void MainWindow::on_aboutButton_clicked()
{
    aboutWindow.setWindowTitle("About");
    aboutWindow.show();
}
