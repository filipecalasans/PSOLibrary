#include "pso.h"

#include "psovectorunit.h"

#include "psosolutiontemplate.h"

#include <QTime>
#include "randomc/mersenne.cpp"
#include <qdebug.h>
#include <QList>

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

PSO::PSO(QList<double> min, QList<double> max)
{
    dimension = min.size();
    qDebug() << dimension;
    qDebug() << "Min:" << min;
    qDebug() << "Max:" << max;
    this->min = min;
    this->max = max;
    rand = new STOC_BASE(QTime::currentTime().msec());
}

void PSO::genInitSolution(int n)
{

    for(int j=0; j<n; j++) {
        QList <double> *sol = new QList<double>();
        for(int i=0; i<dimension; i++) {
            double r = generateReal(min[i], max[i]);
            sol->append(r);
        }
        position << (*sol);
    }
}

void PSO::updateSolution()
{

}
