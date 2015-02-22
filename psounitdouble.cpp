#include "psounitdouble.h"

#include <QVariant>

PSOUnitDouble::PSOUnitDouble(QObject *parent) :
    PSOVectorUnit(parent)
{
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

}
