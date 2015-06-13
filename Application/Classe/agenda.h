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

   /*! \brief Constructeur
    *
    * Constructeur de la classe Agenda
    */
   Agenda();
   /*! \brief Destructeur
    *
    * Destructeur de la classe Agenda
    */
   ~Agenda();
   /*! \brief Opérateur de recopie
    *
    * Opérateur de recopie de la classe Agenda
    * \param foo const Agenda&
    *
    */
   Agenda(const Agenda & foo);
   /*! \brief Opérateur d'affectation
    *
    * Opérateur d'affectation de la classe agenda
    * \param foo const Agenda&
    * \return Agenda&
    *
    */
   Agenda & operator=(const Agenda & foo);

   /*! \brief Permet l'ajout de la programmation d'un évènement
    *
    * \param t const TacheUnitaire&
    * \param d const QDate&
    * \param debut const QTime&
    * \param fin const QTime&
    * \return void
    *
    */
   void ajouterProgrammation(const Evenement & t, const QDate & d, const QTime & debut, const QTime & fin);

public:

   /*! \brief accès à l'instance unique d'Agenda
    * Permet l'accès à l'instance unique d'Agenda
    * fonction statique du design patern Singleton.
    * \return Agenda& l'instance unique
    *
    */
   static Agenda &getInstance();

   /*! \brief suppression d'une Programmation unique
    * Permet la suppression d'une Programmation unique
    * Si cette programmation est en lien avec un évènement qui n'est pas une tâche, alors ce dernier sera détruit.
    * \param d const QDate& Date de la programmation à supprimer
    * \param h const QTime& Heure de la programmation à supprimer
    * \return void
    *
    */
   void supprimerProgrammation(const QDate &d, const QTime &h);
   /*! \brief suppression de toutes les programamtions en lien avec une Tache Unitaire
    * Permet la suppression de toutes les programamtions en lien avec une Tache Unitaire
    * \param t const TacheUnitaire& Tache Unitaire dont on veut appeler
    * \return void
    *
    */
   void supprimerProgrammation(const Evenement & t);

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
   vector<Programmation *> & trouverProgrammation(const Evenement & t)const;

   /*! \brief Supprimer toutes les programmations
    *
    * Supprime toutes les programmations comprises dans l'agenda.
    * \return void
    *
    */
   void supprimerTout();

   /*! \brief Nombre de tâches sur un horaire
    *
    * Fonction qui permet de déterminer le nombre de Programmations qui sont programmées sur une période donnée.
    * \param date const QDate& Date de cette période
    * \param debut const QTime& Début de cette période
    * \param fin const QTime& Fin de cette période
    * \return unsigned int Le nombre de Programmations chevauchant cette période.
    *
    */
   unsigned int chevaucheHoraire(const QDate & date, const QTime &debut, const QTime & fin);
   /*! \brief Tableau des tâches chevauchant un horaire
    *
    * Fonction qui permet d'obtenir toutes les programmations qui sont programmées sur une période donnée.
    * \param date const QDate& Date de cette période
    * \param debut const QTime& Début de cette période
    * \param fin const QTime& Fin de cette période
    * \return vector<const Programmation *>& Tableau de toutes les programmations chevauchant cette période.
    *
    */
   vector<const Programmation *> & tabChevaucheHoraire(const QDate & date, const QTime &debut, const QTime & fin);

   /*! \brief Récupère les Programmations
    *
    * Fonction accesseur permettant d'accéder aux programmations de l'agenda.
    * \return std::list<Programmation *>&
    *
    */
   std::list<Programmation *> & getProgrammation();
   /*! \brief Récupère les Programmations
    *
    * Fonction accesseur permettant d'accéder aux programmations de l'agenda.
    * \return std::list<Programmation *>&
    *
    */
   const std::list<Programmation *> & getProgrammation() const;

};

#endif // AGENDA_H
