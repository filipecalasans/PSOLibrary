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
    min << 2.6 << 0.7 << 17 << 7.3 << 7.8 << 2.9 << 5.0;
    max << 3.6 << 0.8 << 28 << 8.3 << 8.3 << 3.9 << 5.5;

    /* define constraints */
    QList <constraint> c;

    /* max and min for eache xid */
    c << [](const QList <double>& x, double *v) {
           *v = x[0] - 3.6;
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v = 2.6 - x[0];
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v = x[1] - 0.8;
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v = 0.7 - x[1];
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v = x[2] - 28;
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v = 17 - x[2];
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v = x[3] - 8.3;
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v = 7.3 - x[3];
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v = x[4] - 8.3 ;
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v =  7.8 - x[4];
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};


    c << [](const QList <double>& x, double *v) {
           *v = x[5] - 3.9 ;
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v = 2.9 - x[5];
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};


    c << [](const QList <double>& x, double *v) {
           *v = x[6] - 5.5 ;
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
           *v = 5.0 - x[6];
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};


    c << [](const QList <double>& x, double *v) {
           *v = (27.0/(x[0]*pow(x[1],2)*x[2]) - 1);
            double vaux = *v;
            *v = abs(*v);
            return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
        *v = (397.5/(x[0]*pow(x[1],2)*pow(x[2],2))-1);
         double vaux = *v;
         *v = abs(*v);
         return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
        *v = ((1.93*pow(x[3], 3))/(x[1]*x[2]*pow(x[5],4)) - 1);
         double vaux = *v;
         *v = abs(*v);
         return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
        *v = ((1.93*pow(x[4], 3))/(x[1]*x[2]*pow(x[6],4)) - 1);
         double vaux = *v;
         *v = abs(*v);
         return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
        *v = (1.0/(110.0*pow(x[5],3)))* sqrt(pow(745.0*x[3]/(x[1]*x[2]),2)+16.9E+6) - 1;
         double vaux = *v;
         *v = abs(*v);
         return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
        *v = (1.0/(85.0*pow(x[6],3)))* sqrt(pow(745.0*x[4]/(x[1]*x[2]),2)+157.5E+6) - 1;
         double vaux = *v;
         *v = abs(*v);
         return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
        *v = (x[1]*x[2])/40.0 - 1;
         double vaux = *v;
         *v = abs(*v);
         return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
        *v = (5.0*x[1]/x[0] - 1);
         double vaux = *v;
         *v = abs(*v);
         return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
        *v = (1.5*x[5] + 1.9)/x[3] -1;
         double vaux = *v;
         *v = abs(*v);
         return (vaux <= 0);};

    c << [](const QList <double>& x, double *v) {
        *v = (1.1*x[6] + 1.9)/x[4] -1;
         double vaux = *v;
         *v = abs(*v);
         return (vaux <= 0);};


    PSO pso(min, max, [](const QList <double>& x) {
        return 0.7854*x[0]*x[1]*x[1]*(3.3333*x[2]*x[2] + 14.9334*x[2] - 43.0934) -
                1.508*x[0]*(x[5]*x[5] + x[6]*x[6]) + 7.4777*(x[5]*x[5]*x[5] + x[6]*x[6]*x[6]) +
                0.7854*(x[3]*x[5]*x[5] + x[4]*x[6]*x[6]);
    }, c);


    pso.genInitSolution(100);
    pso.minimize(0.0, 3000);

    qDebug() << pso.getBestSolution();
    qDebug() << "fit:" << pso.calculateFitWithContraints(pso.getBestSolution());
    return a.exec();
}
