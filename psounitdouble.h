#ifndef PSOUNITDOUBLE_H
#define PSOUNITDOUBLE_H

#include "psovectorunit.h"

class PSOUnitDouble : public PSOVectorUnit
{
public:
    PSOUnitDouble(QObject *parent = 0);

    virtual void set(const QVariant& v);
    virtual double convertToRealNumber();

};

#endif // PSOUNITDOUBLE_H
