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
#include "Classe/tacheComposite.h"

int main(void){

    TacheUnitaire* T1 = new TacheUnitaire("T1", "Essaie1", QDate(2015,2,1), QDate(2015,3,1), Duree(3,43), true);
    TacheComposite* T2 = new TacheComposite("T2", "Essaie2", QDate(2015,2,15), QDate(2015,2,25));
    TacheUnitaire* T4 = new TacheUnitaire("T4", "Essaie2", QDate(2015,1,15), QDate(2015,2,15), Duree(2,41));

    qDebug()<<T1->getDisponibilite().day()<<"\n";
    qDebug()<<T1->getDuree().getDureeEnHeures()<<"\n";

    T1->ajouterPrecedence(*T2);
    T2->ajouterPrecedence(*T4);
    T1->verifierPrecedence(*T4);
    //T1->verifierPrecedence(*T2);
    TacheUnitaire* T3 = new TacheUnitaire((*T1));
    /*
    T2->ajouterComposition(*T4);

    std::vector<Tache*>::iterator it = T1->getPrecedence().begin();
    std::vector<Tache*>::iterator it3 = T3->getPrecedence().begin();

    qDebug()<<"Adresse des itérators\n";

    qDebug()<<"iterator de T1 : "<<&it<<"\n";
    qDebug()<<"iterator de T3 : "<<&it3<<"\n";

    qDebug()<<"Passage à T1\n";

    if(T1->getPrecedence().empty())
        qDebug()<<"Précédence est vide.\n";
    else{
        TacheComposite* item = dynamic_cast<TacheComposite*>(*it);
        TacheUnitaire* item2 = dynamic_cast<TacheUnitaire*>(*(item->getComposition().begin()));
        qDebug()<<item2->getDuree().getHeure()<<"\n";
    }

    qDebug()<<"Passage à T3\n";

    if(T3->getPrecedence().empty())
        qDebug()<<"Précédence est vide.\n";
    else{
        TacheComposite* item = dynamic_cast<TacheComposite*>(*it);
        TacheUnitaire* item2 = dynamic_cast<TacheUnitaire*>(*(item->getComposition().begin()));
        qDebug()<<item2->getDuree().getHeure()<<"\n";
    }

    T4->setDuree(Duree(5,43));

    qDebug()<<"Passage à T1\n";

    if(T1->getPrecedence().empty())
        qDebug()<<"Précédence est vide.\n";
    else{
        TacheComposite* item = dynamic_cast<TacheComposite*>(*it);
        TacheUnitaire* item2 = dynamic_cast<TacheUnitaire*>(*(item->getComposition().begin()));
        qDebug()<<item2->getDuree().getHeure()<<"\n";
    }

    qDebug()<<"Passage à T3\n";

    if(T3->getPrecedence().empty())
        qDebug()<<"Précédence est vide.\n";
    else{
        TacheComposite* item = dynamic_cast<TacheComposite*>(*it);
        TacheUnitaire* item2 = dynamic_cast<TacheUnitaire*>(*(item->getComposition().begin()));
        qDebug()<<item2->getDuree().getHeure()<<"\n";
    }
    */
    return 0;
}
