#ifndef COMMUNICATIONCHANNEL_H
#define COMMUNICATIONCHANNEL_H

#include <QVector>
#include <QString>
#include <QPair>
#include <math.h>


class CommunicationChannel
{
public:
    CommunicationChannel();
    void generateMatrix(QVector< QPair<QString, double> > probabilities);
    double **getMatrix();
    void calculateNoise();
    double getNoise();
    QPair<int, int> asd;



private:
    QVector< QPair<QString, double> > probs;
    double ** matrix;
    double noise;
    int size;
};

#endif // COMMUNICATIONCHANNEL_H
