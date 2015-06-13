#include "tache.h"
#include "tacheUnitaire.h"
#include "evenement.h"
#include "agenda.h"

TacheUnitaire::TacheUnitaire(const QString &id, const QString &t, const QDate &dispo, const QDate &deadline, const Duree &dur):
    Tache(id, t, dispo, deadline), Evenement(dur){
    qDebug()<<"Création d'un objet Tache Unitaire\n";
}

TacheUnitaire::~TacheUnitaire(){
   Agenda::getInstance().supprimerProgrammation(*this);
   qDebug()<<"Destruction d'un objet Tache Unitaire\n";

}


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
