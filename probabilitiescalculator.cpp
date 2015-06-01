#include "probabilitiescalculator.h"

ProbabilitiesCalculator::ProbabilitiesCalculator()
{
}

void ProbabilitiesCalculator::calculate(const QVector< QPair<QString, int> > &colorCount, int total)
{
    this->probs.clear();
    for (int e = 0; e < colorCount.size(); e++) {
        QString first = colorCount.at(e).first;
        double second = (double)(colorCount.at(e).second)/total;
        this->probs.push_back(qMakePair(first, second));
    }
}

QVector< QPair<QString, double> > ProbabilitiesCalculator::getProbabilities()
{
    return probs;
}



