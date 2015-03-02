#ifndef PSO_H
#define PSO_H

#include <QList>

#include "psovectorunit.h"

#include "psounitdouble.h"
#include "psosolution.h"


#include "randomc/randomc.h"
#define  STOC_BASE CRandomMersenne

typedef bool (*fp)(double);

class PSO
{

//private:

public: //test only

    int dimension;
    STOC_BASE *rand;

    QList <QList <double> > position;
    QList <QList <double> > lBest;
    QList <QList<double> > vel;

    QList <double> gBest;

    QList <fp> constraints; /* To be implemented */

    QList <double> min;
    QList <double> max;

    double ohmega, phiP, phiG;

protected:

    double generateReal (double min, double max);

public:

    PSO(QList <double> min, QList<double> max);

    void genInitSolution(int n);

    virtual void updateSolution ();
    PSOSolution* minimize (int minError, int maxInteractions);
    PSOSolution* maximize (int minError, int maxInteractions);


};

#endif // PSO_H
