#include <QCoreApplication>

#include <QTime>
#include <qdebug.h>

#include "psosolutiontemplate.h"
#include "psounitdouble.h"

#include "randomc/randomc.h"

#include "randomc/mersenne.cpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    PSOSolutionTemplate solution;
    PSOVectorUnit *x0 = new PSOUnitDouble(0.0, 100.0),
                  *x1 = new PSOUnitDouble(0.0, 50.0),
                  *x2 = new PSOUnitDouble(0.0, 25.0);

    STOC_BASE rand1(QTime::currentTime().msec());

    x0->generateRandomValue(&rand1);
    x1->generateRandomValue(&rand1);
    x2->generateRandomValue(&rand1);

    solution << x0;
    solution << x1;
    solution << x2;

    for(int i=0; i<solution.dimension(); i++) {
        qDebug() << "x" << i << ":" << solution.getElement(i)->getRealValue();
    }
    return a.exec();
}
