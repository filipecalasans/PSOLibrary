#include <QCoreApplication>

#include <QTime>
#include <qdebug.h>

#include "pso.h"

#define PARTICLES 200
/*
 * Optimization problem example from:
 * http://www.informatica.si/PDF/32-3/10_Solving%20Engineering%20Optimization%20Problems%20with%20the%20Simple%20Constrained.pdf
 * E03: Speed Reducer design optimization
 * problem
 *
 *
 */


#include <math.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList <double> min, max;
    min << 78 << 33 << 27 << 27 << 27;
    max << 102 << 45 << 45 << 45 << 45;

    /* define constraints */
    QList <constraint> c;

    /* max and min for eache xid */
    c << [](const QList <double>& x, double *v) {
           *v = x[0] - 102.0;
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v = 78.0 - x[0];
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v = x[1] - 45.0;
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v = 33.0 - x[1];
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v = x[2] - 45.0;
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v = 27.0 - x[2];
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v = x[3] - 45.0;
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v = 27.0 - x[3];
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v = x[4] - 45.0;
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v =  27.0 - x[4];
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    //0 <= 85.334407 + 0.0056858x2x5 + 0.0006262x1x4 - 0.0022053x3x5 <= 92
    c << [](const QList <double>& x, double *v) {
           *v =  85.334407 + 0.0056858*x[1]*x[4] + 0.0006262*x[0]*x[3] - 0.0022053*x[2]*x[4] - 92.0;
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
        *v = -1.0*(85.334407 + 0.0056858*x[1]*x[4] + 0.0006262*x[0]*x[3]-0.0022053*x[2]*x[4]);
         double vaux = *v;
         *v = abs(*v);
         return (vaux <= 0);};

    //90 <= 80.51249 + 0.0071317x2x5 + 0.0029955x1x2 - 0.0021813x3^2 <= 110
    c << [](const QList <double>& x, double *v) {
        *v = 80.51249 + 0.0071317*x[1]*x[4]+0.0029955*x[0]*x[1]-0.0021813*x[2]*x[2]-110.0;
         double vaux = *v;
         *v = abs(*v);
         return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
        *v = 90 - (80.51249 + 0.0071317*x[1]*x[4] + 0.0029955*x[0]*x[1] - 0.0021813*x[2]*x[2]);
         double vaux = *v;
         *v = abs(*v);
         return (vaux <= 0);};

    //20 <= 9.300961 + 0.0047026x3x5 + 0.0012547x1x3 + 0.0019085x3x4 <= 25
    c << [](const QList <double>& x, double *v) {
        *v = 9.300961 + 0.0047026*x[2]*x[4] + 0.0012547*x[0]*x[2] + 0.0019085*x[2]*x[3] - 25.0;
         double vaux = *v;
         *v = abs(*v);
         return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
        *v = 20 - (9.300961 + 0.0047026*x[2]*x[4] + 0.0012547*x[0]*x[2] + 0.0019085*x[2]*x[3]);
         double vaux = *v;
         *v = abs(*v);
         return (vaux <= 0);};


    PSO pso(min, max, [](const QList <double>& x) {
        return 5.3578547*x[2]*x[2] + 0.8356891*x[0]*x[4] + 37.293239*x[0] - 40792.141;
    }, c);

    bool feasible;

    pso.genInitSolution(100);
    pso.minimize(8000);

    qDebug() << pso.getBestSolution();
    qDebug() << "fit:" << pso.calculateFitWithContraints(pso.getBestSolution(), &feasible);
    qDebug() << "is feasible?" << feasible;
    return a.exec();
}
