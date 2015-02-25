#include "psounitdouble.h"

#include <QVariant>

PSOUnitDouble::PSOUnitDouble(double min, double max, QObject *parent) :
    PSOVectorUnit(parent)
{
    this->max = max;
    this->min = min;
    hasMin = true;
    hasMax = true;
}

void PSOUnitDouble::set(const QVariant &v)
{
    value = v;
    realValue = convertToRealNumber();
}

double PSOUnitDouble::convertToRealNumber() const
{
    return value.toDouble();
}

QVariant PSOUnitDouble::convertToVariant() const
{
    return QVariant(realValue);
}

void PSOUnitDouble::generateRandomValue(STOC_BASE *rand)
{
    double minAux = 0.0, maxAux= 1E+30;
    if(hasMinimum())
        minAux = min;
    if(hasMaximum())
        maxAux = max;

    double r;

    if(minAux * maxAux < 0) {
        r = rand->IRandomX(minAux, maxAux);
    }
    else {
        r = rand->Random() * (maxAux - minAux);

        if (minAux < 0 || maxAux < 0)
            r *= -1;
    }
    set(QVariant(r));
}
