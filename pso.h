#ifndef PSO_H
#define PSO_H

#include <QList>
#include <QPair>

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

    int interations;
    /* number of replacement particles */
    int rp;

    /* number of reinitialization generations number */
    int rgenerations;


    /*******************************/
    QList < QPair<int, double> > replacementAux;


protected:

    double generateReal (double min, double max);
    bool verifyConstraints(const QList<double> &x, double *fit);
    void applyReplacemntParticles ();
    void applyMutationOperator (int indx);

public:

    PSO(QList <double> min, QList<double> max, fit f);
    PSO(QList <double> min, QList<double> max, fit f, QList <constraint> c);

    void genInitSolution(int n);

    virtual void updateSolution (int indx, bool replacement = false);
    virtual void updateAllSolutions ();

    virtual void minimize(int interations = 1000);

    const QList<double>& getBestSolution ();
    double calculateFitWithContraints (const QList<double> &x, bool *feasible);
};

#endif // PSO_H
