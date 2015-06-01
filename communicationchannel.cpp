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

double CommunicationChannel::getTempLoss(QVector<double> receivedProbs)
{
    double loss = 0;
    int totalprobs = 0;
    for (int ytemp = 0; ytemp < this->size; ytemp++) {
        totalprobs+=receivedProbs.at(ytemp);
    }
    for (int y = 0; y < this->size; y++) {
        double temp = 0;
        int total = 0;
        for (int xtemp = 0; xtemp < this->size; xtemp++) {
            total+= this->computationalMatrix[xtemp][y];
        }

        for (int x = 0; x < this->size; x++) {
            if (this->computationalMatrix[x][y] != 0) {
                QPair<QString, double> pairtemp = this->probs.at(x);
                double value = pairtemp.second;
                double cheese = (this->computationalMatrix[x][y]/total);
                temp += (cheese * log2 (cheese));
            }
            else temp += 0;
        }
        this->symbolsLoss.replace(y, receivedProbs.at(y)/totalprobs * -temp);
        loss += receivedProbs.at(y)/totalprobs * -temp;
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

double **CommunicationChannel::getAccumulatedProbs()
{
    double **accumulated = new double*[this->size];
    for (int i = 0; i < this->size; i++) {
        accumulated[i] = new double[this->size];
        for (int e = 0; e < this->size; e++) {
            if (e == 0)
                accumulated[i][e] = this->matrix[i][e];
            else
                accumulated[i][e] = this->matrix[i][e] + accumulated[i][e-1];
        }
    }
    return accumulated;
}

int CommunicationChannel::getNextSymbol()
{
    double r=((double)rand()/(double)RAND_MAX);
    double acc = 0;
    for (int i = 0; i < this->size; i++) {
        QPair<QString, double> pair = (probs).at(i);
        acc += pair.second;
        if (r < acc)
            return i;
    }
}

int CommunicationChannel::getReceivedSymbol(int emited)
{
    double r=((double)rand()/(double)RAND_MAX);
    double acc = 0;
    for (int i = 0; i < this->size; i++) {
        acc += this->matrix[emited][i];
        if (r < acc)
            return i;
    }
}

bool CommunicationChannel::converge(double oldLoss, double newLoss)
{
    if (abs(newLoss - oldLoss)>1e-9)
        return false;
    return true;
}

void CommunicationChannel::calculateLoss()
{
    this->computationalMatrix = getComputationalMatrix();
    this->symbolsLoss.fill(0, this->size);
    QVector<double> receivedProbs;
    for (int i = 0; i < this->size; i++) {
        receivedProbs.push_back(0);
    }
    double oldLoss = 0;
    double newLoss = 0;
    int counter = 1;
    while (!converge(oldLoss, newLoss) || counter < 10000) {
        int emitedSymbol = getNextSymbol();
        int receivedSymbol = getReceivedSymbol(emitedSymbol);

        //update Y probs
        int temp = receivedProbs.at(receivedSymbol);
        receivedProbs.replace(receivedSymbol, temp+1);
        //update matrix
        double prob = this->computationalMatrix[emitedSymbol][receivedSymbol];
        this->computationalMatrix[emitedSymbol][receivedSymbol] = prob+1;
        //update loss
        oldLoss = newLoss;
        newLoss = getTempLoss(receivedProbs);
        counter++;
    }

    qDebug() << "LA PERDIDA ES DE: " << newLoss;
    qDebug() << this->symbolsLoss;
    this->loss = newLoss;
}

QPair<int, double> CommunicationChannel::getLostSymbol()
{
    QPair <int, double> max;
    max.first = -1;
    max.second = 0;
    for (int i = 0; i < this->size; i++) {
        if (max.second < this->symbolsLoss.at(i)) {
            max.first = i;
            max.second = this->symbolsLoss.at(i);
        }
    }
    return max;
}

double CommunicationChannel::getNoise()
{
    return this->noise;
}

double CommunicationChannel::getLoss()
{
    return this->loss;
}


