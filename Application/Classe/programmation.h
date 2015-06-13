#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H
#include "tache.h"
#include "evenement.h"

/*! \brief Programamtion d'un évènement
 * Représente la programamtion d'un évènement.
 * Une instance Programmation ne peut exister en dehors d'un Agenda.
 */
class Programmation
{
   const Evenement* evenement; /*!< Pointeur vers l'évènement programmé */

   QDate date; /*!< date à laquel l'évènement est programmé */
   QTime debut; /*!< heure de début */
   QTime fin; /*!< heure de fin */
   /*! \brief constructeur
    *
    * constructeur d'une programmation
    * \param t const Evenement& Référence à l'évènement que l'on veut programmer
    * \param d const QDate& Date de la programmation
    * \param t_debut const QTime& heure de début de la programmation
    * \param t_fin const QTime& heure de fin de la programmation
    *
    */
   Programmation( const Evenement & t, const QDate& d, const QTime& t_debut, const QTime& t_fin);

   /*! \brief destructeur
    *
    * detructeur d'une programmation
    */
   ~Programmation();

   friend class Agenda;
public:

   /*! \brief Getter de evenement
    *
    * \return const Evenement* l'évènement associé à la tache.
    *
    */
   const Evenement* getEvenement() const;

   /*! \brief Getter de date
    *
    * \return QDate Date à laquelle de la programmation
    *
    */
   QDate getDate() const;
   /*! \brief Récupération de la durée
    *
    * \return Duree Durée de la programmation
    *
    */
   Duree getDuree() const;
   /*! \brief Getter de début
    *
    * \return QTime heure de début de la programmation
    *
    */
   QTime getDebut() const;
   /*! \brief getter de fin
    *
    * \return QTime heure de fin de la programmation
    *
    */
   QTime getFin() const;
};

#endif // PROGRAMMATION_H
