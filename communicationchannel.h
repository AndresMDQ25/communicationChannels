#ifndef COMMUNICATIONCHANNEL_H
#define COMMUNICATIONCHANNEL_H


class CommunicationChannel
{
public:
    CommunicationChannel();
    void generateMatrix(Vector<QString> colors);
private:
    double matrix[][];
};

#endif // COMMUNICATIONCHANNEL_H
