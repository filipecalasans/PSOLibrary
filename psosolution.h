#ifndef PSOSOLUTION_H
#define PSOSOLUTION_H

#include "psovectorunit.h"
#include <QList>


class PSOSolution
{

private:

    QList<PSOVectorUnit*> vectorOfRn;

public:

    PSOSolution();

    PSOVectorUnit *operator <<(PSOVectorUnit *v);
};

#endif // PSOSOLUTION_H
