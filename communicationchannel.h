#ifndef COMMUNICATIONCHANNEL_H
#define COMMUNICATIONCHANNEL_H

#include <QVector>
#include <QString>
#include <QPair>
#include <math.h>
#include <QDebug>


class CommunicationChannel
{
public:
    CommunicationChannel();
    void generateMatrix(QVector< QPair<QString, double> > probabilities);
    double **getMatrix();
    void calculateNoise();
    void calculateLoss();
    double getNoise();
    double getLoss();
    QPair<int, double> getLostSymbol();



private:
    int getNextSymbol();
    int getReceivedSymbol(int emited);
    double **getComputationalMatrix();
    double **getAccumulatedProbs();
    double getTempLoss(QVector<double> receivedProbs);
    bool converge(double oldLoss, double newLoss);

    QVector< QPair<QString, double> > probs;
    double ** computationalMatrix;
    double ** matrix;
    double noise;
    double loss;
    QVector<double> symbolsLoss;
    int size;
};

#endif // COMMUNICATIONCHANNEL_H
