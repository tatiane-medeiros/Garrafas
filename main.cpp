#include <QtCore/QCoreApplication>
#include "Controle.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Controle c;
    c.plasticReady(true);
    
    return a.exec();
}
