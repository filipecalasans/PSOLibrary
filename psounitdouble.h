#ifndef PSOUNITDOUBLE_H
#define PSOUNITDOUBLE_H

#include "psovectorunit.h"

class PSOUnitDouble : public PSOVectorUnit
{
public:

    PSOUnitDouble(QObject *parent = 0);

    virtual void set (const QVariant& v);
    virtual double convertToRealNumber() const;
    virtual QVariant convertToVariant() const;

    virtual void generateRandomValue (STOC_BASE *rand);

};

#endif // PSOUNITDOUBLE_H
