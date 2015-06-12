/*! \file
 * \brief Fichier contenant la déclaration de la classe Agenda
 * Un agenda gère des Programmations.
 *
 *
 */


#ifndef AGENDA_H
#define AGENDA_H
#include "programmation.h"
#include "QDate"
#include <list>

class TacheUnitaire;
class TachePreemptable;

/*! \class Agenda
 * \brief une classe gérant une liste de programmation
 *
 * Cette classe implémente le design Pattern Singleton, on peut obtenir l'instance unique d'Agenda par la fonction publique getInstance()
 *
 */

class Agenda
{
   friend class ExportImport_XML;

private:
    /*!< la liste des programmations, utilisant la librairie STL */
   list<Programmation*> programmations ;

   // design pattern singleton
   Agenda();
   ~Agenda();
   Agenda(const Agenda & foo);
   Agenda & operator=(const Agenda & foo);

   /*! \brief Permet l'ajout de la programmation d'un évènement
    *
    * \todo modifier
    * \param t const TacheUnitaire&
    * \param d const QDate&
    * \param debut const QTime&
    * \param fin const QTime&
    * \return void
    *
    */
   void ajouterProgrammation(const Evenement & t, const QDate & d, const QTime & debut, const QTime & fin);

public:
//   class IteratorJournee{
//   private:
//      QDate journee;
//      list<Programmation *>::iterator it_programmation;
//      list<Programmation *>::iterator end;
//
//      IteratorJournee(QDate j, list<Programmation *> & p);
//      IteratorJournee(QDate j, list<Programmation *>::iterator it_programmation, list<Programmation *>::iterator end);
//      friend class Agenda;
//   public:
//      IteratorJournee& operator++(int);
//      bool operator==(const IteratorJournee &other) const;
//      bool operator!=(const IteratorJournee &other) const;
//      Programmation* operator*() const;
//   };
//   IteratorJournee itJ_begin(QDate journee);
//   IteratorJournee itJ_end(QDate journee);

   static Agenda &getInstance();

   void supprimerProgrammation(const QDate &d, const QTime &h);
   void supprimerProgrammation(const TacheUnitaire &t);

   /*! \brief Permet l'ajout de la programmation d'un evenement classique
    *
    * \param nomDeLEventClassique const QString & Nom de l'Event à ajouter
    * \param d const QDate& Date à laquelle l'event est programmée
    * \param h const QTime& Heure à laquelle l'event est programmée
    * \param duree const Duree Durée de la programmation.
    * \return void
    *
    */
   void ajouterProgrammation(const QString &nomDeLEventClassique, const QDate &d, const QTime& h, const Duree duree);
   /*! \brief Permet l'ajout de la programmation d'une tâche préemptable
    *
    * \param t const TachePreemptable& Tâche à ajouter
    * \param d const QDate& Date à laquelle la tâche est programmée
    * \param h const QTime& Heure à laquelle la tâche est programmée
    * \param duree const Duree Durée de la programmation.
    * \return void
    *
    */
   void ajouterProgrammation(const TachePreemptable & t, const QDate& d, const QTime& h, const Duree duree);
   /*! \brief Permet l'ajout de la programmation d'une tâche unitaire (préemptable ou non).
    * La durée de la programmation sera systématiquement la durée de la tâche
    *
    * \param t const TacheUnitaire& Tâche à ajouter
    * \param d const QDate& Date à laquelle la tâche est programmée
    * \param h const QTime& Heure à laquelle la tâche est programmée
    * \return void
    *
    */
   void ajouterProgrammation(const TacheUnitaire & t, const QDate& d, const QTime& h);

   /*! \brief permet de déterminer si une programmation que l'on veut créer se chevauche avec une programmation déjà existante
    *
    * \param d const QDate& date de la programmation que l'on veut créer
    * \param debut const QTime& heure de début de la programmation que l'on veut créer
    * \param fin const QTime& heure de fin de la programmation que l'on veut créer
    * \param position list<Programmation *>::iterator position de la programmation déjà existante
    * \return bool true s'il y a chevauchement
    * \return bool false s'il n'y a pas chevauchement
    *
    */
   bool chevauche(const QDate& d, const QTime& debut, const QTime & fin, list<Programmation *>::iterator position);
   /*! \brief trouve toutes les Programmations de la tâche passée en paramètre
    *
    * \param t const TacheUnitaire& tâche dont on veut trouver les programmations
    * \return vector<Programmation *>& tableau des programmations. Tableau vide (vector::size() == 0)
    *
    */
   vector<Programmation *> & trouverProgrammation(const TacheUnitaire & t)const;

   void supprimerTout();

   unsigned int chevaucheHoraire(const QDate & date, const QTime &debut, const QTime & fin);
   vector<const Programmation *> & tabChevaucheHoraire(const QDate & date, const QTime &debut, const QTime & fin);

   std::list<Programmation *> & getProgrammation();
   const std::list<Programmation *> & getProgrammation() const;

};

#endif // AGENDA_H
