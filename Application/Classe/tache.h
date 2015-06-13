#ifndef TACHE_H
#define TACHE_H

#include <QString>
#include <QDate>
#include <vector>
#include <Classe/calendarException.h>
#include <ExportImport/rapidxml-1.13/rapidxml.hpp>


class Projet;

/*! \brief classe représentant une tâche
 *
 * Un objet tâche est forcément associé à un projet
 * Tache est une classe abstraite.
 */
class Tache {
protected:
    std::vector<Tache*> precedence; /*!< l'ensemble des précédences de cette tâche */
    QString identificateur; /*!< identifiant de cette tâche */
    QString titre; /*!< titre de cette tâche */
    QDate disponibilite; /*!< date de disponibilité de cette tâche */
    QDate echeance; /*!< échéance de cette tâche */
    std::vector<Tache*> mere; /*!< l'ensemble des tâches qui ont cette tâche en précédence */
    Tache* mere_compo; /*!< pointeur vers la tâche qui a cette tâche en composition. 0 si cette tâche n'est pas en composition */

    Tache(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline); /*!< constructeur */
    Tache(const Tache& t); /*!< opérateur de recopie */
    Tache& operator=(const Tache& obj); /*!< opérateur d'affectation */
    virtual ~Tache(); /*!< destructeur */

    friend class Projet;
public:

    /* Les Setter et Getter */
    QString& getIdentificateur(); /*!< retourne l'id de la tâche */
    const QString& getIdentificateur() const; /*!< retourne l'id de la tâche */
    /*! \brief modifier identificateur
     *
     * \param value const QString& nouvel identificateur
     * \return void
     * \exception CalendarException si le nouvel identificateur existe déjà
     */
    void setIdentificateur(const QString &value);

    QString& getTitre(); /*!< retourne le titre de la tâche */
    const QString& getTitre() const; /*!< retourne le titre de la tâche */
    void setTitre(const QString &value); /*!< modifie le titre de la tâche */

    QDate& getDisponibilite(); /*!< retourne la date de disponibilité de cette tâche */
    const QDate& getDisponibilite() const; /*!< retourne la date de disponibilité de cette tâche */
    void setDisponibilite(const QDate &value); /*!< modification de la disponibilité de cette tâche */

    QDate& getEcheance();  /*!< retourne la date d'échéance de cette tâche */
    const QDate& getEcheance() const;  /*!< retourne la date d'échéance de cette tâche */
    void setEcheance(const QDate &value); /*!< modification d'échéance de cette tâche */

    std::vector<Tache *> &getPrecedence(); /*!< retourne l'ensemble des tâches qui ont cette tâche en précédence */
    const std::vector<Tache *> &getPrecedence() const; /*!< retourne l'ensemble des tâches qui ont cette tâche en précédence */

    std::vector<Tache *> &getMere(); /*!< retourne l'ensemble des tâches qui ont cette tâche en précédence */
    const std::vector<Tache*> &getMere() const; /*!< retourne l'ensemble des tâches qui ont cette tâche en précédence */

    Tache* getMere_Compo() const; /*!< retourne le pointeur vers la tâche qui a cette tâche en composition. 0 si cette tâche n'est pas en composition */
    void setMere_Compo(Tache *value); /*!< modifie le pointeur vers la tâche qui a cette tâche en composition. 0 si cette tâche n'est pas en composition  */

    /* Autres Fonctions */
    /*! \brief ajouter une précédence
     *
     * ajoute une précédence à cette tâche
     * \param t Tache& tache précédant cette tâche
     * \return void
     * \exception CalendarException si fail
     *
     */
    void ajouterPrecedence(Tache& t);
    /*! \brief vérifie si une précédence est valide ou non
     * vérifie si cette tâche peut être précédée d'une autre tâche
     * une tâche ne peut pas avoir une tache parente en prérequis
     * \param t Tache& autre tâche
     * \return true si la précédence est valide
     * \return false sinon
     *
     */
    bool verifierPrecedence(Tache &t) const;

    /*! \brief supprime un précédence
     *
     * enlève une précédence à cette tâche
     * \param id const QString& id de la tâche qui précède cette tâche
     * \return void
     * \exception CalendarException si échec
     *
     */
    void supprimerPrecedence(const QString & id);
    unsigned int nbPrerequis() const; /*!< renvoie le nombre de prérequis à la tâche */
    Tache* getPere(); /*!< Renvoie un pointeur vers la tache père de la tâche appelante ou 0 si le père est le projet*/
    Projet* getProjet(); /*!< envoie le projet auquel appartient une tâche */

    // nécessaire pour l'import xml
    /*! \brief ajoute les attributs à un noeud XML
     *
     * fonction virtuelle pure : dans le cadre de l'import xml, ajoute les attributs de la tâche au noeud déjà existant
     * \param doc rapidxml::xml_document<>& document xml de base
     * \param node_tache rapidxml::xml_node<>& noeud xml représentant une tâche dont on doit mettre les attributs
     * \return void
     *
     */
    virtual void xml_ajouterAttributs(rapidxml::xml_document<> & doc, rapidxml::xml_node<> & node_tache) = 0;
};

#endif // TACHE_H
