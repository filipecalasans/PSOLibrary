#ifndef PSOVECTORUNIT_H
#define PSOVECTORUNIT_H

#include <QObject>
#include <QVariant>

#include "randomc/randomc.h"
#define  STOC_BASE CRandomMersenne

class PSOVectorUnit : public QObject
{
    Q_OBJECT

protected:

    QVariant value;
    double realValue;

    /* TODO: Implement set and get methods */
    double min, max;
    bool hasMin, hasMax;


    virtual double convertToRealNumber () const { return 0.0; }
    virtual QVariant convertToVariant () const { return QVariant(); }

public:
    explicit PSOVectorUnit(QObject *parent = 0);

    const QVariant& get () const { return value; }

    virtual void set (const QVariant& v) { value = v; }

    double getRealValue () const { return realValue; }

    virtual void generateRandomValue (STOC_BASE *rand);

    double getMax () { return max; }
    double getMin () { return min; }

    void setMax (double max) {
        this->max = max;
        hasMax = true;
    }

    void setMin (double min) {
        this->min = min;
         hasMin = true;
    }

    bool hasMinimum () { return hasMin; }
    bool hasMaximum () { return hasMax; }

signals:

public slots:

};

#endif // PSOVECTORUNIT_H
