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

unsigned int TacheComposite::nbComposition() const
{
   return composition.size();
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
