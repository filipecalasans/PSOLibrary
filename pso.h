#ifndef PSO_H
#define PSO_H

#include "psovectorunit.h"

#include "psosolution.h"

class PSO
{

private:

    QList <PSOSolution *> solutions;
    QList <PSOSolution *> bLocalSolution;
    QList <double> velocities;

    PSOSolution *gBesSolution;

    double omega, phiG, phiP;

public:
    PSO();
};

#endif // PSO_H
