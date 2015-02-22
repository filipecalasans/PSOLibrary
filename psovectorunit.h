#ifndef PSOVECTORUNIT_H
#define PSOVECTORUNIT_H

#include <QObject>

class PSOVectorUnit : public QObject
{
    Q_OBJECT

private:

    QVariant value;
    double realValue;

public:
    explicit PSOVectorUnit(QObject *parent = 0);

    const QVariant& get () { return value; }

    virtual void set (const QVariant& v) { value = v; }
    virtual double convertToRealNumber () = 0;

signals:

public slots:

};

#endif // PSOVECTORUNIT_H
