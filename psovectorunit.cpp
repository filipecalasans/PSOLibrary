#include "psovectorunit.h"



PSOVectorUnit::PSOVectorUnit(QObject *parent) :
    QObject(parent)
{
    realValue = 0.0;
    hasMin = hasMax = false;
}

void PSOVectorUnit::generateRandomValue(STOC_BASE *rand)

{

}

