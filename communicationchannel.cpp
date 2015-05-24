#include "communicationchannel.h"

CommunicationChannel::CommunicationChannel()
{

}

void CommunicationChannel::generateMatrix(QVector<QPair<QString, double> > probabilities)
{
    this->probs = probabilities;
    this->size = probabilities.size();
    this->matrix = new double*[this->size];
    for (int i = 0; i < this->size; i++) {
        this->matrix[i] = new double[this->size];
    }
    double sameColorProb = 0.3;
        //prob. when sent color == received color
    double anotherColorProb = (1 - sameColorProb) / (this->size - 1);
        //prob. when sent color != received color

    for (int x = 0; x < this->size; x++) {
        for (int y = 0; y < this->size; y++) {
            if (x == y)
                this->matrix[x][y] = sameColorProb;
            else
                this->matrix[x][y] = anotherColorProb;
        }
    }


}

double **CommunicationChannel::getMatrix()
{
    return this->matrix;
}

void CommunicationChannel::calculateNoise()
{
    double noise = 0;
    for (int x = 0; x < this->size; x++) {
        double temp;
        for (int y = 0; y < this->size; y++) {
            temp -= (this->matrix[x][y] * log2 (this->matrix[x][y]));
        }
        QPair<QString, double> pair = (probs).at(x);
        noise += pair.second * temp;
    }
    this->noise = noise;
}

double CommunicationChannel::getNoise()
{
    return this->noise;
}

