#ifndef PSOSOLUTION_H
#define PSOSOLUTION_H

#include "psovectorunit.h"
#include <QList>

class PSOSolution
{

protected:

    QList<PSOVectorUnit*> vectorRn;

public:

    PSOSolution();
    ~PSOSolution ();

    PSOVectorUnit *operator <<(PSOVectorUnit *v);
    int dimension ();

    PSOVectorUnit *getElement(int indx);
    void removeElement (int indx);

    virtual double objectiveFunctionValue () = 0;
    //virtual void generateRandomSolution (int dimension);
};

#endif // PSOSOLUTION_H
