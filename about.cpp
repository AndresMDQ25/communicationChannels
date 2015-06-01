#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    QString textToShow = "Este programa fue realizado como trabajo de cursada para la materia Teoría de la Información por Mirko Hrubik y Andrés Chardon. \n";
    textToShow.append("\n El objetivo del programa es, dada una imagen, obtener las probabilidades asociadas a cada color en ella. \n");
    textToShow.append("\n Luego, dado un canal de transmisión de información no muy confiable, se calcula el ruido y la pérdida asociados. Finalmente, se determina cual es el símbolo con mayor pérdida.");
    ui->infoBox->setText(textToShow);
}

About::~About()
{
    delete ui;
}
