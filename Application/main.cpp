/*
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
*/
#include "Classe/tache.h"
#include "Classe/tacheUnitaire.h"

int main(void){

    TacheUnitaire* T1 = new TacheUnitaire("T1", "Essaie1", QDate(2015,2,1), QDate(2015,3,1), Duree(3,43), true);
    TacheUnitaire* T2 = new TacheUnitaire("T2", "Essaie2", QDate(2015,2,15), QDate(2015,2,15), Duree(2,41));


    qDebug()<<T1->getDisponibilite().day()<<"\n";
    qDebug()<<T1->getDuree().getDureeEnHeures()<<"\n";

    T1->ajouterPrecedence(T2);

    TacheUnitaire* T3 = new TacheUnitaire((*T1));

    std::vector<Tache*>::iterator it = T1->getPrecedence().begin();
    std::vector<Tache*>::iterator it3 = T3->getPrecedence().begin();

    if(T1->getPrecedence().empty())
        qDebug()<<"Précédence est vide.\n";
    else{
        TacheUnitaire* item = dynamic_cast<TacheUnitaire*>(*it);
        qDebug()<<item->getDuree().getHeure()<<"\n";
    }

    T2->setDuree(Duree(5,43));

    if(T1->getPrecedence().empty())
        qDebug()<<"Précédence est vide.\n";
    else{
        TacheUnitaire* item = dynamic_cast<TacheUnitaire*>(*it);
        qDebug()<<item->getDuree().getHeure()<<"\n";
    }

    /*
    qDebug()<<&it<<"\n";
    qDebug()<<&it3<<"\n";
    */

    return 0;
}
