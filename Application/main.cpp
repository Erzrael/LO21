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
#include "Classe/projetManager.h"

int main(void){
    /*
    ProjetManager &projetManager = ProjetManager::getInstance();
    Projet * P1 = projetManager.ajouterProjet("P1", "Essaie1", QDate(2014,5,6), QDate(2015,1,3));
    projetManager.ajouterProjet("Ptest", "arg", QDate(2015,3,27),QDate(2015,4,16));
    Projet * P2 = projetManager.ajouterProjet("P2", "Essaie2", QDate(2015,3,27),QDate(2015,4,16));
    P1->ajouterTache("T1", "Essaie1", QDate(2015,2,1), QDate(2015,3,1), Duree(3,43), true);
    P1->ajouterTache("T2","Essaie2",QDate(2015,1,15), QDate(2015,2,15));
    P2->ajouterTache("T3", "Essaie3", QDate(2015,1,15), QDate(2015,2,15), Duree(2,41));

    ProjetManager::TacheIterator it = projetManager.tache_begin();
    ProjetManager::TacheIterator it2 = projetManager.tache_end();
    while(it != projetManager.tache_end()){
       qDebug()<<(*it)->getTitre()<<"\n";
        it++;
    }

    qDebug()<<"braou"; */
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
    */

    /*
    ProjetManager &projetManager = ProjetManager::getInstance();
    Projet * P1 = projetManager.ajouterProjet("P1", "Essaie1", QDate(2014,5,6), QDate(2015,1,3));
    qDebug()<<P1->getEcheance();

    P1->ajouterTache("T1", "Essaie1", QDate(2015,2,1), QDate(2015,3,1), Duree(3,43), true);
    P1->ajouterTache("T2", "Essaie2", QDate(2015,2,15), QDate(2015,2,25));
    P1->ajouterTache("T3", "Essaie3", QDate(2015,1,15), QDate(2015,2,15), Duree(2,41));

    Tache* T1 = projetManager.getTache("T1");
    qDebug()<<T1->getDisponibilite();

    qDebug()<<"Destruction";

    projetManager.supprimerTache("T2");

    projetManager.supprimerProjet("P1");
    */
    /*
    ProjetManager &projetManager = ProjetManager::getInstance();
    Projet * P1 = projetManager.ajouterProjet("P1", "Essaie1", QDate(2014,5,6), QDate(2015,1,3));
    Projet * P2 = projetManager.ajouterProjet("P2", "Essaie2", QDate(2014,5,6), QDate(2015,1,3));
    Projet * P3 = projetManager.ajouterProjet("P3", "Essaie3", QDate(2014,5,6), QDate(2015,1,3));

    projetManager.supprimerProjet("P3");
    */
    /*
    ProjetManager &projetManager = ProjetManager::getInstance();
    Projet * P1 = projetManager.ajouterProjet("P1", "Essaie1", QDate(2014,5,6), QDate(2015,1,3));
    Tache* T1 = P1->ajouterTache("T1", "Essaie1", QDate(2015,2,1), QDate(2015,3,1), Duree(3,43), true);
    Tache* T2 = P1->ajouterTache("T2", "Essaie2", QDate(2015,2,15), QDate(2015,2,25));
    Tache* T3 = P1->ajouterTache("T3", "Essaie3", QDate(2015,1,15), QDate(2015,2,15), Duree(2,41));

    //T1->ajouterPrecedence(*T2);
    //T2->ajouterPrecedence(*T3);
    //T3->ajouterPrecedence(*T1);

    Tache* T4 = P1->ajouterTache("T4", "Essaie4", QDate(2015,2,15), QDate(2015,2,12));
    Tache* T5 = P1->ajouterTache("T5", "Essaie5", QDate(2015,1,15), QDate(2015,2,7));

    TacheComposite* composite1 = dynamic_cast<TacheComposite*>(T2);
    TacheComposite* composite2 = dynamic_cast<TacheComposite*>(T4);
    TacheComposite* composite3 = dynamic_cast<TacheComposite*>(T5);

    composite1->ajouterComposition(T4);
    composite2->ajouterComposition(composite3);
    //composite3->verifierComposition(composite1);
    composite1->ajouterComposition(T3);

    Tache* Papa = T5->getPere();

    if(Papa)
        qDebug()<<Papa->getIdentificateur();
    else
        qDebug()<<"Papa = Projet";

    //projetManager.supprimerTache("T3");
    */
    /*
    std::vector<Tache *>::iterator it = P1->getTaches().begin();

    T1->ajouterPrecedence(*T2);
    T2->ajouterPrecedence(*T3);
    T1->verifierPrecedence(*T3);
    //T1->verifierPrecedence(*T2);

    qDebug()<<T1->getDisponibilite().day()<<"\n";
    qDebug()<<T1->getDuree().getDureeEnMinutes()<<"\n";
    qDebug()<<P1->getEcheance();
    qDebug()<<P1->nbTaches()<<"\n";
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
