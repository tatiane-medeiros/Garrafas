#include "Controle.h"

Controle::Controle(QObject *parent) : QObject(parent)
{
    a = false;
    b = true;
    c = false;
}

Controle::~Controle()
{ }


void Controle::setA(bool value)
{
    if(value != a){
     this->a = value;
     emit getA();
    }

}
bool Controle::getA() const
{
    if(a) qDebug()<< "A abre";
    else qDebug()<< "A fecha";
    return a;
}
void Controle::setB(bool value)
{
    if(value != b){
     this->b = value;
     emit getB();
    }
}

bool Controle::getB() const
{
    if(b) qDebug()<< "B fecha";
    else qDebug()<< "B abre";
    return b;
}

void Controle::setC(bool value)
{
    if(value != c){
     this->c = value;
     emit getC();
    }
}

bool Controle::getC() const
{

    if(c) qDebug()<< "C fecha";
    else qDebug()<< "C abre";
    return c;
}


void Controle::plasticReady(bool ready)
{
    if(ready){

         liberaPlastico();
    }
}

void Controle::liberaPlastico()
{
   qDebug("plastico liberado");
    setA(true);
    //setB(true);
    QTimer::singleShot(5000,this,SLOT(molde()));

}

void Controle::molde()
{
        setA(false);
        setB(false);
        setC(true);
        QTimer::singleShot(500,this,SLOT(ar()));

}

void Controle::ar()
{

        setB(true);
        QTimer::singleShot(4000,this,SLOT(liberaPlastico()));
        setC(false);
        qDebug("Garrafa pronta.");

}





