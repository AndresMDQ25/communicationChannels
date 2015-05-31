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
        double temp = 0;
        for (int y = 0; y < this->size; y++) {
            temp += (this->matrix[x][y] * log2 (this->matrix[x][y]));
        }
        QPair<QString, double> pair = (probs).at(x);
        noise += pair.second * -temp;
    }
    this->noise = noise;
}

double CommunicationChannel::getTempLoss()
{
    double loss = 0;
    for (int y = 0; y < this->size; y++) {
        double temp = 0;
        for (int x = 0; x < this->size; x++) {
            temp += (this->computationalMatix[x][y] * log2 (this->computationalMatrix[x][y]));
        }
        loss += probY.at(y) * -temp;
    }
    return loss;
}

double **CommunicationChannel::getComputationalMatrix()
{
    double **finalMatrix = new double*[this->size];
    for (int i = 0; i < this->size; i++) {
        finalMatrix[i] = new double[this->size];
        for (int e = 0; e < this->size; e++) {
            finalMatrix[i][e] = 0;
        }
    }
    return finalMatrix;



}

int CommunicationChannels::getNextSymbol()
{
    int r = rand();


    for (int i = 0; i < this->size; i++) {
        QPair<QString, double> pair = (probs).at(i);
        if (r > pair.second)
            return i;
    }
}

void CommuncationChannel::calculateLoss()
{
    this->computationalMatrix = generateComputationalMatrix();
    double oldLoss = 0;
    double newLoss = 0;
    while (newLoss - oldLoss < 0.003) {
        int emitedSymbol = getNextSymbol();
        int receivedSymbol = getReceivedSymbol(emitedSymbol);

    }
    //emitir simbolo
    //recibir simbolo
    //actualizar probs de Y
    //actualizar matriz(x, y)
    //perdida = perdida(matriz)
    //
}

double CommunicationChannel::getNoise()
{
    return this->noise;
}

