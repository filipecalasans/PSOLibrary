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

void PSO::applyReplacemntParticles()
{




}

double PSO::calculateFitWithContraints(const QList <double>&x)
{
    double fitAux;
    /* verify constraints here */
    if(verifyConstraints(x, &fitAux)) {
       fitAux = (*fitFunction)(x);
       qDebug() << "Feaseble";
    }
    return fitAux;
}

PSO::PSO(QList<double> min, QList<double> max, fit f)
{
    dimension = min.size();
    this->min = min;
    this->max = max;
    rand = new STOC_BASE(QTime::currentTime().msec());
    fitFunction = f;
    ohmega= rand->Random();
    phiG = 1.8;
    phiP = 1.8;
}

PSO::PSO(QList<double> min, QList<double> max, fit f, QList<constraint> c)
{
    dimension = min.size();
    this->min = min;
    this->max = max;
    rand = new STOC_BASE(QTime::currentTime().msec());
    fitFunction = f;
    constraints = c;
    ohmega= rand->Random();
    phiG = 1.8;
    phiP = 1.8;
}

void PSO::genInitSolution(int n)
{
    rp = (int)0.4 * n;

    for(int j=0; j<n; j++) {
        QList <double> sol;
        QList <double> velocity;
        for(int i=0; i<dimension; i++) {
            double r = generateReal(min[i], max[i]);
            sol.append(r);
            double v = generateReal(0, 100);
            velocity.append(v);
        }
        double fitAux = calculateFitWithContraints(sol);
        position << sol;
        lBest << sol;
        vel << velocity;
        if(gBest.isEmpty()) {
            gBest = (sol);
        }
        else {
            if(fitAux < calculateFitWithContraints(gBest)) {
                gBest = (sol);
            }
        }
    }
    qDebug() << "Min Fit: " << calculateFitWithContraints(gBest);
}

void PSO::updateSolution(int indx, bool replacement)
{
    QList <double> p = position[indx], lb = lBest[indx];
    QList <double> v, vprev = vel[indx];
    for(int i=0; i<p.size(); i++) {
        v << (ohmega*vprev[i] + rand->Random()*phiG*(gBest[i] - p[i]) + rand->Random()*phiP*(lb[i] - p[i]));
        p[i] = p[i] + v[i];
    }

    double fitValue = calculateFitWithContraints(p);

    if( fitValue < calculateFitWithContraints(lb)) {
        lBest.removeAt(indx);
        lBest.insert(indx, p);
    }

    if (fitValue < calculateFitWithContraints(gBest)) {
        gBest = p;
    }

    position.removeAt(indx);
    position.insert(indx, p);
    vel.removeAt(indx);
    vel.insert(indx, v);
}

void PSO::updateAllSolutions()
{
    for (int i=0; i<position.size(); i++) {
        updateSolution(i);
    }
}

void PSO::minimize(int interations)
{
    for(int i=0; i<interations; i++) {
        //qDebug() << "Running interation:" << i+1;
        updateAllSolutions();
    }
}

const QList<double> &PSO::getBestSolution()
{
    return gBest;
}


