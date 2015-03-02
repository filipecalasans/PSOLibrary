#include <QCoreApplication>

#include <QTime>
#include <qdebug.h>

#include "pso.h"

#define PARTICLES 200

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList <double> min, max;
    min << 3.0 << 2.0 << 0.0;
    max << 150.0 << 24.5 << 18.786;

    PSO pso(min, max);

    pso.genInitSolution(10);

    for(int i=0; i<pso.position.size(); i++) {
        qDebug() << QString("pos[%1]").arg(i) << pso.position.at(i);
    }

    return a.exec();
}
