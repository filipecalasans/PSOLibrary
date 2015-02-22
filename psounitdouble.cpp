#include "psounitdouble.h"

#include <QVariant>

PSOUnitDouble::PSOUnitDouble(QObject *parent) : PSOVectorUnit(parent)
{
}

void PSOUnitDouble::set(const QVariant &v)
{
    value = v;
    realValue = convertToRealNumber();
}

double PSOUnitDouble::convertToRealNumber()
{
    value.toDouble();
}
