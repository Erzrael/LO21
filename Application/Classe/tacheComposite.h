/*! \file
 * \brief contient la déclaration de la classe TacheComposite
 *
 *
 */
#ifndef TACHECOMPOSITE_H
#define TACHECOMPOSITE_H
#include <vector>
#include <QDate>
#include <QString>
#include <ExportImport/rapidxml-1.13/rapidxml.hpp>

class Tache;

/*! \brief classe représentant une tâche composite
 * Hérite de Tache.
 * Une tâche composite est composée de différentes tâches.
 */
class TacheComposite : public Tache {
    friend class ProjetManager;

    std::vector<Tache*> composition; /*!< liste des tâches composant cette Tache Composite */

    TacheComposite(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline); /*!< constructeur */
    TacheComposite(const TacheComposite& t); /*!< opérateur de recopie */
    TacheComposite& operator=(const TacheComposite& obj); /*!< opérateur d'affectation */
    /*! \brief destructeur
     *
     * les tâches composant la tâche composite seront également détruites
     */
    ~TacheComposite();

public:
    /* Les Getters et Setters */
    std::vector<Tache *> &getComposition(); /*!< retourne la liste des tâches composant cette Tache Composite */
    const std::vector<Tache *> &getComposition() const; /*!< retourne liste des tâches composant cette Tache Composite */

    /*! \brief ajoute une composition à cette tache
     *
     * \param t Tache& tâche qui sera ajoutée
     * \return void
     * \exception CalendarException si échec
     *
     */
    void ajouterComposition(Tache &t);
    /*! \brief vérifie si une composition est valide ou non
     *
     * vérifie si cette tâche peut accepter la tâche en paramètre en composition
     * \param t Tache&
     * \return true si la composition est valide
     * \return false sinon
     *
     */
    bool verifierComposition(Tache &t) const;
    unsigned int nbComposition() const; /*!< retourne le nombre de composition */
    /*! \brief supprime une composition à cette tâche
     *
     * \param id const QString& id de la composition que l'on veut supprimer
     * \return void
     * \exception CalendarException si échec.
     */
    void supprimerComposition(const QString & id);

    virtual void xml_ajouterAttributs(rapidxml::xml_document<> & doc, rapidxml::xml_node<> & node_tache);
};

#endif // TACHECOMPOSITE_H
