#include "pso.h"

#include <QTime>
#include <qdebug.h>
#include <QList>
#include <qmath.h>

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

/*
 * Return true if the result is feasible.
 *
 */
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

void PSO::applyMutationOperator(int indx)
{
    /* Mutation operator:
     * if R=0, xid = xid + delta(t, UB - xid)
     * if R=1, xid = xid - delta(t, xid - LB)
     *
     * UB = Upper Bound, LB = Lowe Bound of particle dimension value
     * R is a randomly generated bit - probability of 50/50
     *
     * delta(t, y) = y * (1 - r^(1 - (t/T)^b)
     *
     * r = random number in the interval [0.1] from a uniform distribution.
     * T = Maximum number of interations
     * b = tunable parameter, in this case 5.
     *
     */

    const int b = 5;
    int R, dim = position[indx].size();
    double y, delta, r = rand->Random();

    for (int i=0; i<dim; i++) {
        double xid = position[indx].at(i);
        R = rand->Random() > 0.5 ? 1 : 0;
        y = R == 1 ? xid - min[i] : max[i] - xid;
        delta = y * (1 - qPow(r, (1 - qPow((indx+1)/interations, (double)b))));
        xid = R == 1 ? xid - delta : xid + delta;
        position[indx].removeAt(i);
        position[indx].insert(i, xid);
    }
}


double PSO::calculateFitWithContraints(const QList <double>&x, bool *feasible)
{
    double fitAux;
    *feasible = false;
    /* verify constraints here */
    if(verifyConstraints(x, &fitAux)) {
       fitAux = (*fitFunction)(x);
       *feasible = true;
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
    bool feasible;
    for(int j=0; j<n; j++) {
        QList <double> sol;
        QList <double> velocity;
        for(int i=0; i<dimension; i++) {
            double r = generateReal(min[i], max[i]);
            sol.append(r);
            double v = generateReal(0, 100);
            velocity.append(v);
        }
        double fitAux = calculateFitWithContraints(sol, &feasible);
        position << sol;
        lBest << sol;
        vel << velocity;
        if(gBest.isEmpty()) {
            gBest = (sol);
        }
        else {
            if(fitAux < calculateFitWithContraints(gBest, &feasible)) {
                gBest = (sol);
            }
        }
    }
    qDebug() << "Min Fit: " << calculateFitWithContraints(gBest, &feasible);
}

void PSO::updateSolution(int indx, bool replacement)
{
    bool feasible;
    QList <double> p = position[indx], lb = lBest[indx];
    QList <double> v, vprev = vel[indx];
    for(int i=0; i<p.size(); i++) {
        v << (ohmega*vprev[i] + rand->Random()*phiG*(gBest[i] - p[i]) + rand->Random()*phiP*(lb[i] - p[i]));
        p[i] = p[i] + v[i];
    }

    double fitValue = calculateFitWithContraints(p, &feasible);

    if( fitValue < calculateFitWithContraints(lb, &feasible)) {
        lBest.removeAt(indx);
        lBest.insert(indx, p);
    }

    if (fitValue < calculateFitWithContraints(gBest, &feasible)) {
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
    /*for (int i=0; i<(position.size()*0.1); i++) {
        applyMutationOperator(i);
    }*/
}

void PSO::minimize(int interations)
{
    this->interations = interations;

    for(int i=0; i<interations; i++) {
        //qDebug() << "Running interation:" << i+1;
        updateAllSolutions();
    }
}

const QList<double> &PSO::getBestSolution()
{
    return gBest;
}


