/*! \file
 * \brief contient la description des classes Evenement et EvenementClassique
 *
 *
 */

#ifndef EVENEMENT_H
#define EVENEMENT_H

#include "QTime"
#include "duree.h"


/*! \brief classe évènement
 * Classe programmable dans l'agenda.
 * La classe est virtuelle pure.
 */
class Evenement
{
protected:
   Duree duree; /*!< DUrée de l'évènement */

   /*! \brief constructeur
    *
    * Constructeur de la classe Evènement
    * \param d Duree Durée de l'évènement.
    *
    */
   Evenement(Duree d);

   /*! \brief Destructeur
    *
    * Destructeur d'un objet Evènement
    */
   virtual ~Evenement();
public:
   /*! \brief Récupération de l'ID
    *
    * Retourne l'identificateur de l'évènement (obligatoirement à définir dans les classes filles)
    * \return virtual const QString&
    *
    */
   virtual const QString & getID() const = 0;
   /*! \brief récupération de la durée de l'évènement
    *
    * \return Duree durée de cet évènement
    *
    */
   Duree getDuree() const;
   /*! \brief Modification de la durée de l'évènement.
    *
    * Méthode modifiant la durée de cet évènement. Toutes les programmations associées à cet évènement seront alors supprimées.
    * \param value const Duree& Nouvelle durée de l'évènement
    * \return void
    *
    */
   void setDuree(const Duree & value);

   /*! \brief Action réalisée quand une programmation associée à l'évènement est supprimée.
    *
    * Par défaut : supprime l'évènement. Peut-être redéfinie dans les classes filles.
    * \return void
    *
    */
   virtual void suppressionProgrammation();

};

/*! \brief Evènement classique
 * Classe représentant un évènement "classique" avec pour seul attribut un nom.
 */
class EvenementClassique : public Evenement {
protected:
   QString nom; /*!< Nom de l'évènement classique */

   /*! \brief Constructeur
    *
    * COnstructeur d'un évènement classique
    * \param d Duree Durée de l'évènement
    * \param nom QString Nom de l'évènement
    *
    */
   EvenementClassique(Duree d, QString nom);
   friend class Agenda;
public:
   // Evenement interface
   /*! \brief Récupération de l'identifiant d'un évènement classique
    *
    * \return const QString& le nom de l'évènement
    *
    */
   const QString &getID() const;
};

#endif // EVENEMENT_H
