#ifndef PSO_H
#define PSO_H

#include <QList>

#include "randomc/randomc.h"
#define  STOC_BASE CRandomMersenne

typedef double (*fit)(const QList <double>&);

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

    //QList <fp> constraints; /* To be implemented */

    fit fitFunction;

    QList <double> min;
    QList <double> max;

    double ohmega, phiP, phiG;

protected:

    double generateReal (double min, double max);

public:

    PSO(QList <double> min, QList<double> max, fit f);

    void genInitSolution(int n);

    virtual void updateSolution ();

};

#endif // PSO_H
