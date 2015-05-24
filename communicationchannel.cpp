#include "communicationchannel.h"

CommunicationChannel::CommunicationChannel()
{

}

void CommunicationChannel::generateMatrix(QVector<QString> colors)
{
    this->matrix = new double*[colors.size()];
    for (int i = 0; i < colors.size(); i++) {
        this->matrix[i] = new double[colors.size()];
    }


}

