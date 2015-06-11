#include <ExportImport/import_xml.h>

// #include <ExportImport/rapidxml-1.13/rapidxml.hpp>
#include <ExportImport/rapidxml-1.13/rapidxml_print.hpp>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <qdebug.h>
#include <Classe/duree.h>
#include <Classe/projetManager.h>
#include "Classe/projet.h"
#include <Classe/agenda.h>

//#include <ExportImport/exportimport.h>

using namespace rapidxml;

ExportImport_XML::ExportImport_XML(QString filename) : ExportImport(filename), format(QString("yyyy-MM-dd")), format_time(QString("hh:mm:ss")) {}

char *convertQString(QString string)
{
   QByteArray ba = string.toLatin1();
   return ba.data();
}

void ExportImport_XML::load()
{

   qDebug() << "Debut de l'Import en XML de " << filename << "...";

   xml_document<> doc;

//   QByteArray ba = filename.toLatin1();
//   const char * file_name = ba.data();
   const char * file_name = convertQString(filename);

   FILE * file = fopen(file_name, "r");
   if (file == NULL) {
      throw CalendarException("Erreur dans l\'ouverture du fichier");
   }
   // Read the xml file into a vector
   vector<char> buffer;
   char c;
   do {
     c = fgetc (file);
     buffer.push_back(c);
   } while (c != EOF);
   //qDebug() << "size of connasse = " << buffer.size() << buffer[0] ;
   buffer.pop_back();
   buffer.push_back('\0');

   // Parse the buffer using the xml file parsing library into doc
   try {
      doc.parse<0>(&buffer[0]);
   } catch (parse_error &e) {
      qDebug() << "what :" << e.what();
      // qDebug() << "where :" << e.where();
   }


   xml_node<> * root = doc.first_node();
   if( !root) {
      throw CalendarException("parser vide");
   }


   // ajout des projets
   for(xml_node<> * projet = root->first_node("projet") ; projet ; projet = projet->next_sibling("projet") ) {
      QString * id = new QString(projet->first_attribute("id")->value());
      QString * titre = new QString (projet->first_attribute("titre")->value());
      QDate * dispo = new QDate( QDate::fromString( projet->first_attribute("dispo")->value(), format) );
      QDate * echeance = new QDate( QDate::fromString( projet->first_attribute("echeance")->value(), format) );

      projetManager.ajouterProjet(*id, *titre, *dispo, *echeance);
      qDebug() << "ajout d'un projet (" << *id << ", " << *titre << ", " << *dispo << ", " << *echeance << ");" ;

      // On insère les taches du projet
      for(xml_node<> * tache = projet->first_node("tache") ; tache ; tache = tache->next_sibling("tache") ) {
         QString *id_t = new QString(tache->first_attribute("id")->value());
         QString *titre_t = new QString(tache->first_attribute("titre")->value());
         QDate *dispo_t = new QDate( QDate::fromString( tache->first_attribute("dispo")->value(), format) );
         QDate *echeance_t = new QDate( QDate::fromString( tache->first_attribute("echeance")->value(), format) );

         if( *( tache->first_attribute("type")->value() ) == 'c') { // si on a affaire à une tache composite
            projetManager.ajouterTache(*id, *id_t, *titre_t, *dispo_t, *echeance_t);
            qDebug() << "ajouterTacheComposite(" << *id << ", " << *id_t << ", " << *titre_t << ", " << *dispo_t << ", " << *echeance_t<< ");" ;
         } else {
            Duree * duree = new Duree( tache->first_attribute("duree")->value() ) ;
            bool pre = false;
            if ( tache->first_attribute("pre") ) {
               pre = true;
            }
            projetManager.ajouterTache(*id, *id_t, *titre_t, *dispo_t, *echeance_t, *duree, pre);
            qDebug() << "ajouterTacheUnitaire(" << *id << ", " << *id_t << ", " << *titre_t << ", " << *dispo_t << ", " << *echeance_t << ", " << duree->getDureeEnMinutes() << ", " << pre << ");" ;
         }
      }

      // insertion des precedences
      for(xml_node<> * precedence = projet->first_node("precedence") ; precedence ; precedence = precedence->next_sibling("precedence") ) {
         Tache * tache_p  = projetManager.getTache( precedence->first_attribute()->value() ) ;
         qDebug() << "ajout Précédence pour la tache " << tache_p->getIdentificateur() ;
         tache_p->ajouterPrecedence( *(projetManager.getTache( precedence->value())) );
      }
      // insertion des compositions
      for(xml_node<> * composition = projet->first_node("composition") ; composition ; composition = composition->next_sibling("composition") ) {
         TacheComposite * tache_c  = static_cast<TacheComposite *>(projetManager.getTache( composition->first_attribute()->value() ) ) ;
         qDebug() << "ajout Composition pour la tache " << tache_c->getIdentificateur() ;
         tache_c->ajouterComposition( *(projetManager.getTache( composition->value() )));
      }
   }
   // insertion des programmations
   for ( xml_node<> * prog = root->first_node("programmation") ; prog ; prog = prog->next_sibling("programmation") ) {
      TacheUnitaire * tache_u = static_cast<TacheUnitaire *>( projetManager.getTache( prog->value() ) ) ;
      QDate *date = new QDate( QDate::fromString( prog->first_attribute("date")->value(), format) );
      QTime *debut = new QTime ( QTime::fromString( prog->first_attribute("debut")->value(), format_time) );
      QTime *fin = new QTime ( QTime::fromString( prog->first_attribute("fin")->value(), format_time) );

      agenda.ajouterProgrammation( *tache_u, *date, *debut, *fin);
   }


   qDebug()<< "Fin de l'Import en XML !";
   fclose(file);
}

void ExportImport_XML::save()
{
   qDebug() << "Debut de l'Export en XML de " << filename << "...";

   xml_document<> doc;
   xml_node<> * root = doc.allocate_node(node_element, "root");
   doc.append_node(root);
   char *node_name = NULL;

   vector<Projet *> & projets = projetManager.getProjets();
   for (vector<Projet *>::iterator projet_iterator = projets.begin() ; projet_iterator != projets.end() ; ++ projet_iterator) {
      Projet & projet = **projet_iterator;
//      xml_node<> *node = doc.allocate_node(node_element, "a", "Google");
//      doc.append_node(node);
//      xml_attribute<> *attr = doc.allocate_attribute("href", "google.com");
//      node->append_attribute(attr);

      //création du noeud projet
      xml_node<> * node_projet = doc.allocate_node(node_element, "projet");
      root->append_node(node_projet);
      //ajout de ses attributs
      node_name = doc.allocate_string(convertQString( projet.getId() ));
      xml_attribute<> *attribute = doc.allocate_attribute("id", node_name);
      node_projet->append_attribute(attribute);

      node_name = doc.allocate_string( convertQString( projet.getId() ) );
      attribute = doc.allocate_attribute("titre", node_name);
      node_projet->append_attribute(attribute);

      node_name = doc.allocate_string( convertQString( projet.getDisponibilite().toString(format) ) );
      attribute = doc.allocate_attribute("dispo", node_name);
      node_projet->append_attribute(attribute);

      node_name = doc.allocate_string( convertQString( projet.getEcheance().toString(format) ) );
      attribute = doc.allocate_attribute("echeance", node_name);
      node_projet->append_attribute(attribute);

      // on va parcourir les tâches et les ajouter une à une
      vector <Tache *> & taches = (*projet_iterator)->getTaches();
      for (vector< Tache *>::iterator tache_iterator = taches.begin() ; tache_iterator != taches.end() ; ++ tache_iterator) {
         Tache & tache = **tache_iterator;
         //creation du noeud tache
         xml_node<> * node_tache = doc.allocate_node(node_element, "tache");
         node_projet->append_node(node_tache);
         // ajout des attributs
         node_name = doc.allocate_string( convertQString( tache.getIdentificateur() ) );
         attribute = doc.allocate_attribute("id", node_name);
         node_tache->append_attribute(attribute);

         node_name = doc.allocate_string( convertQString( tache.getTitre() ) );
         attribute = doc.allocate_attribute("titre", node_name);
         node_tache->append_attribute(attribute);

         node_name = doc.allocate_string( convertQString( tache.getDisponibilite().toString(format) ) );
         attribute = doc.allocate_attribute("dispo", node_name);
         node_tache->append_attribute(attribute);

         node_name = doc.allocate_string( convertQString( tache.getEcheance().toString(format) ) );
         attribute = doc.allocate_attribute("echeance", node_name );
         node_tache->append_attribute(attribute);

         // ajouts des compositions si tache composite, ajout des attributs pour une tache unitaire
         tache.xml_ajouterAttributs(doc, *node_tache);

         // ajout des précédences
         for ( vector<Tache *>::iterator pre_iterator = tache.getPrecedence().begin() ; pre_iterator != tache.getPrecedence().end() ; ++ pre_iterator ) {
            node_name = doc.allocate_string( convertQString( (*pre_iterator)->getIdentificateur() ) );
            xml_node<> * pre = doc.allocate_node(node_element, "precedence", node_name);
            node_projet->append_node(pre);
            node_name = doc.allocate_string( convertQString( tache.getIdentificateur() ) );
            attribute = doc.allocate_attribute("tache", node_name);
            pre->append_attribute(attribute);
         }
      }
   }

   list<Programmation *> & programmations = agenda.getProgrammation();
   // ajout des noeuds de programmation
   for ( list<Programmation *>::iterator prog_iterator = programmations.begin() ; prog_iterator != programmations.end() ; ++ prog_iterator ) {
      Programmation & prog = **prog_iterator;
      node_name = doc.allocate_string(convertQString( prog.getEvenement()->getID() ) );
      xml_node<> * node_prog = doc.allocate_node(node_element, "programmation", node_name);
      root->append_node(node_prog);

      node_name = doc.allocate_string(convertQString( prog.getDate().toString(format) )  );
      xml_attribute<> * attribute = doc.allocate_attribute("date", node_name );
      node_prog->append_attribute(attribute);

      node_name = doc.allocate_string( convertQString( prog.getDebut().toString() ) );
      attribute = doc.allocate_attribute("debut",  node_name );
      node_prog->append_attribute(attribute);

      node_name = doc.allocate_string( convertQString( prog.getFin().toString() ) );
      attribute = doc.allocate_attribute("fin", node_name );
      node_prog->append_attribute(attribute);
   }

   // Print to stream using operator << (for debug)
   //   std::cout << doc;

   //on imprime le document dans une chaine de charactère
   std::string s;
   print(std::back_inserter(s), doc, 0);
   qDebug() << "taille de s : " << s.size();

   //on imprime la chaine dans le fichier
   const char * file_name = convertQString(filename);
   FILE * file = fopen(file_name, "w");

   fputs( "<?xml version=\"1.0\" encoding=\"iso-8859-14\"?>" , file);
   fputc( '\n' , file);
   if (file == NULL) {
      throw CalendarException("Import XML : Erreur dans l\'ouverture du fichier");
   }

   for (unsigned int i = 0 ; i < s.size() ; i ++) {
      fputc(s[i], file);
      //qDebug() << s[i];
   }

   qDebug()<< "Fin de l'Export en XML !";
   fclose(file);
}
