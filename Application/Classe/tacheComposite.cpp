#include "tache.h"
#include "tacheComposite.h"
#include "projetManager.h"
#include "ExportImport/import_xml.h"

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
        this->precedence = obj.getPrecedence();
        this->mere = obj.getMere();
        this->composition = obj.getComposition();
        this->setMere_Compo(obj.getMere_Compo());
    }
    return *this;
}

TacheComposite::~TacheComposite(){
    qDebug()<<"Destruction d'un objet Tache Composite\n";
}

std::vector<Tache *> &TacheComposite::getComposition()
{
    return composition;
}

const std::vector<Tache *> &TacheComposite::getComposition() const
{
    return composition;
}

void TacheComposite::ajouterComposition(Tache& t)
{
    if(this->verifierComposition(t)){
        this->getComposition().push_back(&t);
        t.setMere_Compo(this);
        qDebug()<<"Ajout composition réussi \n";
    }else{
        qDebug()<<"Ajout composition failed \n";
        throw CalendarException("Une tache ne peut pas avoir une tache parente en composition");
    }
}

bool TacheComposite::verifierComposition(Tache &t) const
{
    // On vérifie que l'on ajoute pas une même tâche en composition d'elle-même
    if(this == &t){
        qDebug()<<"tache identique";
        return false;
    }
    // On vérifie que les échéances concordent
    if(t.getEcheance() > this->getEcheance()){
        qDebug()<<"échéances incorrectes";
        return false;
    }
    // On vérifie si la tâche est déjà en composition
    if(t.getMere_Compo() != 0){
        qDebug()<<"tache est déjà en composition";
        return false;
    } else {
        // Sinon on vérifie l'absence de cycles
        Tache* tache_mere = this->getMere_Compo();
            while(tache_mere != 0)
            {
                if(tache_mere == &t)
                    return false;

                tache_mere = tache_mere->getMere_Compo();
            }
    }

    // Si tous les tests sont validés, c'est bon
    return true;
}

unsigned int TacheComposite::nbComposition() const
{
    return composition.size();
}

void TacheComposite::supprimerComposition(const QString &id)
{
    std::vector<Tache*>::iterator iterator_composition = this->getComposition().begin();

    while(iterator_composition != this->getComposition().end() && (*iterator_composition)->getIdentificateur() != id){
        ++iterator_composition;
    }

    if(iterator_composition != this->getComposition().end()){
        (*iterator_composition)->setMere_Compo(0);
        this->getComposition().erase(iterator_composition);
    } else
        throw CalendarException("La composition n'a pas été supprimée.");
}

void TacheComposite::xml_ajouterAttributs(rapidxml::xml_document<> & doc, rapidxml::xml_node<> & node_tache)
{
   using namespace rapidxml;
   xml_attribute<> * attribute = doc.allocate_attribute("type", "c");
   node_tache.append_attribute(attribute);

   xml_node<> * node_projet = node_tache.parent();
   if(!node_projet) {
      throw CalendarException("TacheComposite xml_ajouterAttributs : node_projet nul");
   }

   for ( vector<Tache *>::iterator compo_iterator = composition.begin() ; compo_iterator != composition.end() ; ++ compo_iterator ) {
      char * node_name = doc.allocate_string( convertQString( (*compo_iterator)->getIdentificateur() ) );
      xml_node<> * compo = doc.allocate_node(node_element, "composition", node_name);
      node_projet->append_node(compo);

      node_name = doc.allocate_string( convertQString(identificateur) );
      xml_attribute<> * attr = doc.allocate_attribute("tache", node_name);
      compo->append_attribute(attr);
   }
}
