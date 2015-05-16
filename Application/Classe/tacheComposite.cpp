#include "tacheComposite.h"

TacheComposite::TacheComposite(const QString &id, const QString &t, const QDate &dispo, const QDate &deadline):
    Tache(id, t, dispo, deadline){
    qDebug()<<"Création d'un objet Tache Composite";
}

TacheComposite::TacheComposite(const TacheComposite& t):Tache(t){
    this->composition = t.getComposition();
}


TacheComposite& TacheComposite::operator=(const TacheComposite& obj){
    if(this != &obj)
    {
        this->setDisponibilite(obj.getDisponibilite());
        this->setEcheance(obj.getEcheance());
        this->setIdentificateur(obj.getIdentificateur());
        this->setTitre(obj.getTitre());
        this->composition = obj.getComposition();
    }
    return *this;
}

TacheComposite::~TacheComposite(){
    qDebug()<<"Destruction d'un objet Tache Unitaire\n";
}

std::vector<Tache *> &TacheComposite::getComposition()
{
    return composition;
}

const std::vector<Tache *> &TacheComposite::getComposition() const
{
    return composition;
}

void TacheComposite::ajouterComposition(Tache *t)
{
    if(t->getEcheance() < this->getEcheance()){
        this->getPrecedence().reserve(5);
        this->getPrecedence().push_back(t);
        qDebug()<<"Ajout précédence réussi \n";
    }else{
        qDebug()<<"Ajout précédence failed \n";
    }
}

void TacheComposite::afficher() const {

}
