#ifndef PSOVECTORUNIT_H
#define PSOVECTORUNIT_H

#include <QObject>
#include <QVariant>

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

signals:

public slots:

};

#endif // PSOVECTORUNIT_H
