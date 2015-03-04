#ifndef PSO_H
#define PSO_H

#include <QList>

#include "randomc/randomc.h"
#define  STOC_BASE CRandomMersenne

typedef double (*fit)(const QList <double>&);
typedef bool (*constraint)(const QList <double>&, double *value);

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

    QList <constraint> constraints;
    fit fitFunction;

    QList <double> min;
    QList <double> max;

    double ohmega, phiP, phiG;

protected:

    double generateReal (double min, double max);
    bool verifyConstraints(const QList<double> &x, double *fit);
    double couculateFitWithContraints (const QList<double> &x);

public:

    PSO(QList <double> min, QList<double> max, fit f);
    PSO(QList <double> min, QList<double> max, fit f, QList <constraint> c);

    void genInitSolution(int n);

    virtual void updateSolution ();

};

#endif // PSO_H
