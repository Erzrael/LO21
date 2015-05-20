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
#include "Classe/projet.h"
#include "Classe/projetmanager.h"

int main(void){
    ProjetManager &projetManager = ProjetManager::getInstance();
    Projet * P1 = projetManager.ajouterProjet("p1",QDate(2014,5,6), QDate(2015,1,3));
    projetManager.ajouterProjet("haha",QDate(2014,5,6), QDate(2015,1,3));
    Projet * P2 = projetManager.ajouterProjet("p2",QDate(2015,3,12),QDate(2015,4,5));
    projetManager.ajouterProjet("aa1",QDate(2014,5,6), QDate(2015,1,3));

    projetManager.ajouterTache("p1", "T1", "Essaie1", QDate(2015,2,1), QDate(2015,3,1), Duree(3,43), true);
    projetManager.ajouterTache("p1","T2","Essai2",QDate(2015,1,15), QDate(2015,2,15), Duree(2,41));
    projetManager.ajouterTache("p2", "T3", "Essaie2", QDate(2015,1,15), QDate(2015,2,15), Duree(2,41));

    ProjetManager::TacheIterator it = projetManager.tache_begin();

    while(it != projetManager.tache_end()){
        qDebug()<<(*it)->getTitre()<<"\n";
        it++;
    }
    qDebug()<<"braou";
    /*TacheUnitaire* T1 = new TacheUnitaire("T1", "Essaie1", QDate(2015,2,1), QDate(2015,3,1), Duree(3,43), true);
    TacheComposite* T2 = new TacheComposite("T2", "Essaie2", QDate(2015,2,15), QDate(2015,2,25));
    TacheUnitaire* T4 = new TacheUnitaire("T4", "Essaie2", QDate(2015,1,15), QDate(2015,2,15), Duree(2,41));


    qDebug()<<T1->getDisponibilite().day()<<"\n";
    qDebug()<<T1->getDuree().getDureeEnHeures()<<"\n";

    T1->ajouterPrecedence(*T2);
    T2->ajouterPrecedence(*T4);
    T1->verifierPrecedence(*T4);
    //T1->verifierPrecedence(*T2);
    TacheUnitaire* T3 = new TacheUnitaire((*T1));
    Projet* P1 = new Projet(QDate(2014,5,6), QDate(2015,1,3));

    qDebug()<<P1->getEcheance();

    P1->ajouterTache(*T3);
    P1->ajouterTache(*T2);

    std::vector<Tache *>::iterator it = P1->getTaches().begin();

    qDebug()<<P1->getEcheance();
    qDebug()<<(*it)->getDisponibilite();
    */

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
