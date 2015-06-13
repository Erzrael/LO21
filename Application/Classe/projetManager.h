#ifndef PROJETMANAGER_H
#define PROJETMANAGER_H
#include <vector>
#include "duree.h"

class Projet;
class Tache;

/*! \brief classe gérant les projets du PokéTache
 * ProjetManager crée les projets et les garde en mémoire. C'est également cette classe qui supervise l'ajout de tâches.
 * ProjetManager implémente le design pattern singleton
 */
class ProjetManager
{
private:
    // static ProjetManager * instanceUnique;
    vector<Projet *> projets; /*!< Tableau des différents projets */

    //DesignPattern Singleton
    ProjetManager(); /*!< constructeur (en privé) */
    ~ProjetManager(); /*!< destructeur */
    ProjetManager(const ProjetManager & foo); /*!< opérateur de recopie */
    ProjetManager & operator=(const ProjetManager & foo); /*!< opérateur d'affectation */

    /*! \brief trouver un projet
     *
     * fonction permettant de trouver un projet
     * \param id const QString& id du projet cherché
     * \return Projet* adresse du projet recherché
     * \return 0 si le projet n'existe pas
     *
     */
    Projet *trouverProjet(const QString &id) const;
    /*! \brief trouver une tache
     *
     * fonction permettant de trouver une tâche dans tous les projets du projetManager
     * \param id const QString& id de la tache recherchée
     * \return Tache* adresse de la tâche
     * \return 0 si la tache n'existe pas.
     *
     */
    Tache *trouverTache(const QString &id) const;

public:
    /*! \brief Iterator des tâches du projetManager
     * Itérator uni-directionnel permettant de parcourir l'ensemble des tâches de tous les projets du ProjetManager
     */
    class TacheIterator{
    private:
       unsigned int nb_projets; /*!< nombre de projets restant dans l'itérateur */
       vector<Projet *>::iterator projetIterator; /*!< itérator sur le tableau des projets du ProjetManager */
       vector<Tache *>::iterator tacheIterator; /*!< itérator sur le tableau des tâches du projet désigné par le projetIterator */

       //Le tacheIterator est initialisé avec l'itérator du premier projet de ProjetManager
       /*! \brief constructeur
        *
        * le tacheIterator est initialisé avec l'itérator du tableau de tâches du premier projet de p
        * \param p vector<Projet *>& tableau de projets dont on veut parcourir les tâches
        *
        */
       TacheIterator(vector<Projet *> & p);
       TacheIterator(unsigned int size, vector<Projet *>::iterator it_p, vector<Tache *>::iterator it_t); /*!< constructeur */

       friend class ProjetManager;
    public:
       TacheIterator& operator++(int); /*!< passe à la tâche suivante */
       bool operator==(const TacheIterator &other) const; /*!< test d'égalité */
       bool operator!=(const TacheIterator &other) const; /*!< test de différence */
       Tache* operator*() const; /*!< renvoie la tâche actuelle */
    };
    /*! \brief initialiser un TacheIterator
     *
     * Initialise un TacheIterator sur la première tache du premier projet de ProjetManager
     * \return TacheIterator
     *
     */
    TacheIterator tache_begin();
    /*! \brief Fin du TacheIterator
     *
     * Renvoie un TacheIterator sur la position située après la dernière tâche du dernier Projet de ProjetManager
     * \return TacheIterator
     *
     */
    TacheIterator tache_end();
    /*! \brief accès à l'instance unique du ProjetManager
     *
     * fonction statique du design pattern singleton
     * \return ProjetManager& l'instance unique du projetManager
     *
     */
    static ProjetManager &getInstance();

    /*! \brief ajouter un projet
     *
     * fonction permettant l'ajout d'un projet
     * \param identificateur const QString& identificateur du projet
     * \param ti const QString& titre du projet
     * \param dispo const QDate& date de disponibilité du projet
     * \param deadline const QDate& date d'échéance du projet
     * \return Projet* l'adresse du projet créé
     * \exception CalendarException en cas d'erreur
     *
     */
    Projet* ajouterProjet(const QString &identificateur, const QString &ti, const QDate& dispo, const QDate& deadline);
    /*! \brief ajouter une tâche à un projet
     *
     * fonction créant une tâche et l'ajoutant à un projet
     * \param id_projet const QString& id du projet dans lequel on veut ajouter la tâche
     * \param id const QString& id de la tâche à créer
     * \param titre const QString& titre de la tâche à créer
     * \param dispo const QDate& date de disponibilité de la tâche à créer
     * \param deadline const QDate& deadline de la tâche à créer
     * \param dur const Duree& (optionnel) Durée de la tâche à créer vide, la tâche créer sera composite.
     * \param pre const bool& (optionnel) true si la tache à créer est préemptable. (default) false
     * \return Tache* un pointeur vers la tâche créé
     * \exception CalendarException en cas d'erreur
     *
     */
    Tache * ajouterTache(const QString & id_projet, const QString& id, const QString& titre, const QDate& dispo, const QDate& deadline, const Duree &dur = Duree(), const bool &pre = false);
    /*! \brief vérifie l'existence d'une tâche
     *
     * \param id const QString& id de la tâche que l'on veut vérifier
     * \return bool true si la tâche existe, false sinon
     *
     */
    bool isTacheExistante(const QString& id) const;
    /*! \brief vérifie l'existence d'un projet
     *
     * \param id const QString& id du projet que l'on veut vérifier
     * \return bool true si le projet existe, false sinon
     *
     */
    bool isProjetExistant(const QString& id) const;

    /// getters
    std::vector<Projet *>& getProjets(); /*!< getter de projets */
    const std::vector<Projet *>& getProjets() const; /*!< getter de projets */

    /*! \brief récupérer une tâche
     *
     * permet de récupérer une tâche via son id
     * \param id const QString& id de la tâche à récupérer
     * \return Tache* adresse de la tâche à récupérer
     * \exception CalendarException si la tâche n'existe pas.
     *
     */
    Tache *getTache(const QString& id);
    /*! \brief récupérer une tâche
     *
     * permet de récupérer une tâche via son id
     * \param id const QString& id de la tâche à récupérer
     * \return const Tache* adresse de la tâche à récupérer
     * \exception CalendarException si la tâche n'existe pas.
     *
     */
    const Tache *getTache(const QString& id) const;
    /*! \brief récupérer un projet
     *
     * permet de récupérer un projet via son id
     * \param id const QString& id du projet à récupérer
     * \return Projet * adresse du à récupérer
     * \exception CalendarException si le projet n'existe pas.
     *
     */
    Projet *getProjet(const QString& id);
    /*! \brief récupérer un projet
     *
     * permet de récupérer un projet via son id
     * \param id const QString& id du projet à récupérer
     * \return const Projet * adresse du à récupérer
     * \exception CalendarException si le projet n'existe pas.
     *
     */
    const Projet *getProjet(const QString& id) const;
    /*! \brief supprime une tâche
     *
     * \param id const QString& id de la tâche à supprimer
     * \return void
     *
     */
    void supprimerTache(const QString& id);
    /*! \brief supprime un projet
     *
     * \param id const QString& id du projet à supprimer
     * \return void
     *
     */
    void supprimerProjet(const QString &id);
    /*! \brief Tout supprimer
     * méthode supprimant tous les projets et toutes les tâches contenues dans projets
     * \return void
     *
     */
    void supprimerTout();

    /*! \brief vérifie s'il existe une tâche dans l'ensemble des projets du ProjetManager
     *
     * \return true si le ProjetManager ne contient aucune tâche
     * \return false sinon
     *
     */
    bool empty() const;


    /* Autres fonctions */
    unsigned int nbProjets() const; /*!< renvoie le nombre de projets que possède le ProjetManager */
};

#endif // PROJETMANAGER_H
