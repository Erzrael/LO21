#include "tache.h"
#include "tacheUnitaire.h"

TacheUnitaire::TacheUnitaire(const QString &id, const QString &t, const QDate &dispo, const QDate &deadline, const Duree &dur, const bool &pre):
    Tache(id, t, dispo, deadline), Evenement(dur), preempte(pre){
    if(!pre)
        if(Duree(12,0) < dur)
            throw CalendarException("Erreur - TacheUnitaire - Durée > 12h et préempté");
    qDebug()<<"Création d'un objet Tache Unitaire\n";
}

TacheUnitaire::TacheUnitaire(const TacheUnitaire& t):Tache(t), Evenement(t.getDuree()){
    this->setPreempte(t.getPreempte());
}


TacheUnitaire& TacheUnitaire::operator=(const TacheUnitaire& obj){
    if(this != &obj)
    {
        this->setDisponibilite(obj.getDisponibilite());
        this->setEcheance(obj.getEcheance());
        this->setIdentificateur(obj.getIdentificateur());
        this->setTitre(obj.getTitre());
        this->precedence = obj.getPrecedence();
        this->setMere(obj.getMere());
        this->setDuree(obj.getDuree());
        this->setPreempte(obj.getPreempte());
    }
    return *this;
}

TacheUnitaire::~TacheUnitaire(){
    qDebug()<<"Destruction d'un objet Tache Unitaire\n";
}

bool& TacheUnitaire::getPreempte()
{
    return preempte;
}

const bool& TacheUnitaire::getPreempte() const
{
    return preempte;
}

void TacheUnitaire::setPreempte(bool value)
{
    preempte = value;
}

/*const Duree& TacheUnitaire::getDuree() const
{
    return duree;
}

Duree& TacheUnitaire::getDuree()
{
    return duree;
}

void TacheUnitaire::setDuree(const Duree &value)
{
    if(!this->getPreempte())
        if(Duree(12,0) < value)
            throw CalendarException("Erreur - Tache Unitaire - setDuree > 12h et préempté");
    duree = value;
}*/

TacheUnitaire *TacheUnitaire::clone() const
{
    return new TacheUnitaire(*this);
}
