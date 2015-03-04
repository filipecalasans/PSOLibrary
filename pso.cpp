#include "pso.h"

#include <QTime>
#include <qdebug.h>
#include <QList>

#include "randomc/mersenne.cpp"

double PSO::generateReal(double min, double max)
{
    double r=0.0;

    if(min * max < 0) {
        r = rand->IRandomX(min, max);
    }
    else {
        r = rand->Random() * (max - min);

        if (min < 0 || max < 0)
            r *= -1;
    }
    return r;
}

bool PSO::verifyConstraints(const QList<double>& x, double *fit)
{
    bool result = true;
    double v = 0.0, temp;
    for (int i=0; i<constraints.size(); i++) {
        if (!(*constraints[i])(x, &temp))
            result = false;
        v += temp;
    }
    *fit = v;
    return result;
}

double PSO::couculateFitWithContraints(const QList <double>&x)
{
    double fitAux;
    /* verify constraints here */
    if(verifyConstraints(x, &fitAux)) {
       fitAux = (*fitFunction)(x);
    }
    return fitAux;
}

PSO::PSO(QList<double> min, QList<double> max, fit f)
{
    dimension = min.size();
    qDebug() << "Min:" << min;
    qDebug() << "Max:" << max;
    this->min = min;
    this->max = max;
    rand = new STOC_BASE(QTime::currentTime().msec());
    fitFunction = f;
}

PSO::PSO(QList<double> min, QList<double> max, fit f, QList<constraint> c)
{
    dimension = min.size();
    qDebug() << "Min:" << min;
    qDebug() << "Max:" << max;
    this->min = min;
    this->max = max;
    rand = new STOC_BASE(QTime::currentTime().msec());
    fitFunction = f;
    constraints = c;
}

void PSO::genInitSolution(int n)
{

    for(int j=0; j<n; j++) {
        QList <double> sol;
        for(int i=0; i<dimension; i++) {
            double r = generateReal(min[i], max[i]);
            sol.append(r);
        }
        double fitAux = couculateFitWithContraints(sol);
        position << sol;
        lBest << sol;
        if(gBest.isEmpty()) {
            gBest = (sol);
            qDebug() << "Min Fit: " << (*fitFunction)(sol);
        }
        else {
            if(fitAux < (*fitFunction)(gBest)) {
                gBest = (sol);
                qDebug() << "Min Fit: " << (*fitFunction)(sol);
            }
        }
    }
}

void PSO::updateSolution()
{

}


