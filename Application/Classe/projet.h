#ifndef PROJET_H
#define PROJET_H
#include "tache.h"
#include "tacheComposite.h"
#include "tacheUnitaire.h"
#include "duree.h"
//#include <QDate>
#include <vector>

/*! \brief classe représentant un projet du calendrier
 * la classe gère les informations relatives à un projet.
 * L'ajout des tâches relatives à ce dernier est géré par l'instance ProjetManager (cf class ProjetManager)
 * Les instances Projet ne peuvent être construites que depuis l'instance ProjetManager.
 */
class Projet
{
private:
   QString id; /*!< id unique du projet */
   QString titre; /*!< titre du projet */
   std::vector<Tache *> taches; /*!< tableau des tâches associées à ce projet */
   QDate dateDispo; /*!< date à partir de laquelle le projet est disponible */
   QDate echeance; /*!< deadline du projet (ça fait peur, hein ?) */

   /*! \brief constructeur
    *
    * Constructeur de la classe Projet
    * Uniquement appelable depuis ProjetManager
    * \param id_p const QString ID du projet. Unique
    * \param ti const QString Titre du projet
    * \param dispo const QDate& Date de disponibilité du projet
    * \param deadline const QDate& date d'échéance du projet.
    *
    */
   Projet(const QString id_p, const QString ti, const QDate& dispo, const QDate& deadline);
   /*! \brief opérateur de recopie
    *
    * \param p const Projet&
    *
    */
   Projet(const Projet& p);
   /*! \brief operateur d'affectation
    *
    * \param obj const Projet&
    * \return Projet&
    *
    */
   Projet& operator=(const Projet& obj);
   /*! \brief destructeur
    *
    * Destructeur de la classe Projet
    */
   ~Projet();

   // influence de l'ajout sur dateDispo ?
   /*! \brief ajouter une tache
    *
    * fonction uniquement appelable via le ProjetManager
    * \param t Tache& tache passée en référence.
    * \return void
    *
    */
   void ajouterTache(Tache &t);

   friend class ProjetManager;
public:

   //Tache * ajouterTache(const QString& id, const QString& titre, const QDate& dispo, const QDate& deadline, const Duree &dur = Duree(), const bool &pre = false);


   /*! \brief trouve une tâche appartenant au projet
    *
    * \param id const QString& id de la tache à trouver.
    * \return Tache*
    * \return 0 si la tache n'est pas trouvée ou si le projet n'a pas encore de tache
    *
    */
   Tache *trouverTache(const QString& id); // Nécessetira des dynamics_cast
      /*! \brief trouve une tâche appartenant au projet
    *
    * \param id const QString& id de la tache à trouver.
    * \return const Tache*
    * \return 0 si la tache n'est pas trouvée ou si le projet n'a pas encore de tache
    *
    */
   const Tache *trouverTache(const QString& id) const;
   /*! \brief supprime une tâche
    *
    * méthode supprimant une tâche appartenant au projet
    * \param id const QString& id de la tache à suprimer.
    * \exception CalendarException si la tâche n'existe pas
    * \return void
    *
    */
   void supprimerTache(const QString& id);

   //Getters and setters
   QString & getTitre(); /*!< Retourne le titre du projet */
   const QString & getTitre() const; /*!< Retourne le titre du projet */
   /*! \brief modifier le titre
    *
    * méthode modifiant le titre du projet
    * \param value const QString& nouveau du titre du projet
    * \return void
    *
    */
   void setTitre(const QString & value);

   QDate& getDisponibilite(); /*!< retourne la date de disponibilité du projet */
   const QDate& getDisponibilite() const; /*!< retourne la date de disponibilité du projet */
   /*! \brief modifier la disponibilité
    *
    * méthode modifiant la disponibilité
    * \todo vérifier si les dates de disponibilité des tâches composant le projet sont cohérentes avec la nouvelle date.
    * \param value const QDate& nouvelle disponibilité du projet
    * \return void
    *
    */
   void setDisponibilite(const QDate &value);

   QDate& getEcheance(); /*!< retourne la date d'échéance du projet */
   const QDate& getEcheance() const; /*!< retourne la date d'échéance du projet */
   /*! \brief modifier la date d'échéance de ce projet
    *
    * \todo vérifier si les dates d'échéance des tâches composant le projet sont cohérentes avec la nouvelle date.
    * \param value const QDate& nouvelle échéance
    * \return void
    *
    */
   void setEcheance(const QDate &value);

   std::vector<Tache *> &getTaches(); /*!< retourne le tableau des tâches */
   const std::vector<Tache *> &getTaches() const; /*!< retourne le tableau des tâches */

   QString& getId(); /*!< retourne l'ID du projet */
   const QString& getId() const; /*!< retourne l'ID du projet */
   /*! \brief modifie l'ID du projet
    *
    * \exception CalendarException si un projet avec le même ID existe déjà
    * \param value const QString& nouvel ID
    * \return void
    *
    */
   void setId(const QString & value);

};

#endif // PROJET_H
