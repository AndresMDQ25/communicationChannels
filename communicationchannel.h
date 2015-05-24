#ifndef COMMUNICATIONCHANNEL_H
#define COMMUNICATIONCHANNEL_H

#include <QVector>


class CommunicationChannel
{
public:
    CommunicationChannel();
    void generateMatrix(QVector<QString> colors);
private:
    double ** matrix;
};

#endif // COMMUNICATIONCHANNEL_H
