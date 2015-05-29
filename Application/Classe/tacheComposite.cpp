#include "tache.h"
#include "tacheComposite.h"
#include "projetManager.h"

TacheComposite::TacheComposite(const QString &id, const QString &t, const QDate &dispo, const QDate &deadline):
    Tache(id, t, dispo, deadline), mere_compo(0){
    qDebug()<<"Création d'un objet Tache Composite";
}

TacheComposite::TacheComposite(const TacheComposite& t):Tache(t){
    this->composition = t.getComposition();
    this->setMere_Compo(t.getMere_Compo());
}


TacheComposite& TacheComposite::operator=(const TacheComposite& obj){
    if(this != &obj)
    {
        this->setDisponibilite(obj.getDisponibilite());
        this->setEcheance(obj.getEcheance());
        this->setIdentificateur(obj.getIdentificateur());
        this->setTitre(obj.getTitre());
        this->precedence = obj.getPrecedence();
        this->setMere(obj.getMere());
        this->composition = obj.getComposition();
        this->setMere_Compo(obj.getMere_Compo());
    }
    return *this;
}

/*
 * Si on est dans le cas suivant, cela plante :
 *  On a trois tâches : T1, T2 et T3
 *  T1 est composé de T2, elle-même composé de T3
 *  Alors, lors de la destruction lors de la fermeture de l'application :
 *  T3 est détruit, puis T2. Comme T2 est composé d'une tâche, le destructeur de cette tâche est appelée.
 *  Hors cette tâche est T3 et est déjà détruite. => Segmentation Fault
 *
 * Pour résoudre le problème, il faut que j'ai un moyen de supprimer tous les vecteurs pointant vers un objet en cours de destruction
 * Deuxième solution : savoir quand une case du vector est vide ou non
 * Troisième solution : concaténer le vector avant la destruction (en supposant que les cases vides de vector soient enlevés
*/

TacheComposite::~TacheComposite(){
    qDebug()<<"Destruction d'un objet Tache Composite\n";

    /* appeler supprimer tâche de projet (donc refaire un supprimer tâche depuis projet) et Revoir fonction supprimer tâche
        Refaire la même chose pour supprimer projet
        C'est moche, mais je ne sais pas comment faire autrement...*//*
    while(!composition.empty()){

        Tache* t = composition.back();
        if(t->getIdentificateur() != "")
            delete composition.back();
        composition.pop_back();
     } */ /*
    Projet* P = this->getProjet();
    while(!composition.empty()){
        Tache* t = composition.back();
        P->supprimerTache(t->getIdentificateur());
     } */
}

std::vector<Tache *> &TacheComposite::getComposition()
{
    return composition;
}

const std::vector<Tache *> &TacheComposite::getComposition() const
{
    return composition;
}

TacheComposite *TacheComposite::getMere_Compo() const
{
    return mere_compo;
}

void TacheComposite::setMere_Compo(TacheComposite *value)
{
    mere_compo = value;
}

TacheComposite *TacheComposite::clone() const
{
    return new TacheComposite(*this);
}
// Refaire en surchargeant la fonction avec des tacheComposite, tacheUnitaire
void TacheComposite::ajouterComposition(Tache* t)
{
    TacheComposite* composite = dynamic_cast<TacheComposite*>(t);
    if(composite != 0){
        if(this->verifierComposition(composite)){
            this->getComposition().push_back(composite);
            composite->setMere_Compo(this);
            qDebug()<<"Ajout composition réussi \n";
        }else{
            qDebug()<<"Ajout composition failed \n";
            throw CalendarException("Une tache ne peut pas avoir une tache parente en composition");
        }
    } else if(t->getEcheance() <= this->getEcheance()) { // On est dans le cas d'une tâche unitaire
        this->getComposition().push_back(t);
        qDebug()<<"Ajout composition réussi \n";
    } else
        throw CalendarException("Une tâche composition ne peut avoir de tâches se finissant après elle");
}

bool TacheComposite::verifierComposition(const TacheComposite *t) const
{
    if(this == t){
        qDebug()<<"Je retourne faux";
        return false;
    } else if(t->getEcheance() > this->getEcheance()){
        qDebug()<<"Je retourne faux";
        return false;
    } else {
        TacheComposite* tache_mere = this->getMere_Compo();
            while(tache_mere != 0)
            {
                if(tache_mere == t)
                    return false;

                tache_mere = tache_mere->getMere_Compo();
            }
            return true;
    }
}

unsigned int TacheComposite::nbComposition() const
{
    return composition.size();
}
