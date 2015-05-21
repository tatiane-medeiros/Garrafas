#ifndef CONTROLE_H
#define CONTROLE_H
#include<QObject>
#include<QDebug>
#include<QTimer>

class Controle : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool A READ getA WRITE setA NOTIFY AChanged)
    Q_PROPERTY(bool B READ getB WRITE setB NOTIFY BChanged)
    Q_PROPERTY(bool C READ getC WRITE setC NOTIFY CChanged)



public:
     explicit Controle(QObject *parent = 0);
    ~Controle();

    bool getA() const;    
    bool getB() const;
    bool getC() const;

signals:
    void AChanged(bool newA);
    void BChanged(bool newB);
    void CChanged(bool newC);

public slots:
    void plasticReady(bool ready);

    void liberaPlastico();
    void molde();
    void ar();

    void setA(bool value);
    void setB(bool value);
    void setC(bool value);

private:
    bool a;
    bool b;
    bool c;



};

#endif // CONTROLE_H
