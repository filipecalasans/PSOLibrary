#include "psovectorunit.h"

PSOVectorUnit::PSOVectorUnit(QObject *parent) :
    QObject(parent)
{
    realValue = 0.0;
    hasMin = hasMax = false;
}

