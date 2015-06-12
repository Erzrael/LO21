#include "tache.h"
#include "tacheUnitaire.h"
#include "evenement.h"

TacheUnitaire::TacheUnitaire(const QString &id, const QString &t, const QDate &dispo, const QDate &deadline, const Duree &dur):
    Tache(id, t, dispo, deadline), Evenement(dur){
    qDebug()<<"Création d'un objet Tache Unitaire\n";
}

//TacheUnitaire::TacheUnitaire(const TacheUnitaire& t):Tache(t), Evenement(t.getDuree()){
//    this->setPreempte(t.getPreempte());
//}


//TacheUnitaire& TacheUnitaire::operator=(const TacheUnitaire& obj){
//    if(this != &obj)
//    {
//        this->setDisponibilite(obj.getDisponibilite());
//        this->setEcheance(obj.getEcheance());
//        this->setIdentificateur(obj.getIdentificateur());
//        this->setTitre(obj.getTitre());
//        this->precedence = obj.getPrecedence();
//        this->setMere(obj.getMere());
//        this->setDuree(obj.getDuree());
//        this->setPreempte(obj.getPreempte());
//    }
//    return *this;
//}

TacheUnitaire::~TacheUnitaire(){
   qDebug()<<"Destruction d'un objet Tache Unitaire\n";
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


void TacheUnitaire::xml_ajouterAttributs(rapidxml::xml_document<> & doc, rapidxml::xml_node<> & node_tache)
{
   using namespace rapidxml;
   xml_attribute<> * attribute = doc.allocate_attribute("type", "u");
   node_tache.append_attribute(attribute);
   if(getPreempte() == true) {
      attribute = doc.allocate_attribute("pre", "true");
      node_tache.append_attribute(attribute);
   }
   char * node_name = doc.allocate_string( duree.toChar() );
   attribute = doc.allocate_attribute( "duree", node_name );
   node_tache.append_attribute(attribute);
}

const QString &TacheUnitaire::getID() const
{
   return getIdentificateur();
}

void TacheUnitaire::suppressionProgrammation() {}
