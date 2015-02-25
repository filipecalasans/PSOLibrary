#include "psosolutiontemplate.h"

PSOSolutionTemplate::PSOSolutionTemplate()
{
    
}

double PSOSolutionTemplate::objectiveFunctionValue()
{
    /*
     * TODO: Implement here the objective function related to your problem.
     * User also must define problem`s contraints here.
     */

    /* Maximize value A = xy, Constraint: 2x + y = 2400 */

    double A = vectorRn[0]->getRealValue() * vectorRn[1]->getRealValue();

    // Constraint: 2x + y = 2400
    if(2*vectorRn[0]->getRealValue() + vectorRn[1]->getRealValue() != 2400)
        return 0.0;

    return A;
}

