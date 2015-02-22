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
    ~PSOSolution ();

    PSOVectorUnit *operator <<(PSOVectorUnit *v);
    int dimension ();

    PSOVectorUnit *getElement(int indx);
    void *removeElement (int indx);

};

#endif // PSOSOLUTION_H
