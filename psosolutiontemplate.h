#ifndef PSOSOLUTIONTEMPLATE_H
#define PSOSOLUTIONTEMPLATE_H

#include "psosolution.h"

/*
 * Template class that implements area optimization
 * Users can use this class as tamplete on further optimization problems.
 *
 */

class PSOSolutionTemplate : public PSOSolution
{
public:
    PSOSolutionTemplate();

    virtual double objectiveFunctionValue ();

};

#endif // PSOSOLUTIONTEMPLATE_H
