#ifndef PSOSOLUTIONTEMPLATE_H
#define PSOSOLUTIONTEMPLATE_H

#include "psosolution.h"

class PSOSolutionTemplate : public PSOSolution
{
public:
    PSOSolutionTemplate();

    virtual double objectiveFunctionValue(int dimension);
    virtual void generateRandomSolution ();
};

#endif // PSOSOLUTIONTEMPLATE_H
