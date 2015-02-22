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

    virtual double convertToRealNumber () = 0;

public:
    explicit PSOVectorUnit(QObject *parent = 0);

    const QVariant& get () { return value; }

    virtual void set (const QVariant& v) { value = v; }
    double getRealValue () { return realValue; }


signals:

public slots:

};

#endif // PSOVECTORUNIT_H
