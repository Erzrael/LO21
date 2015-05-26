#ifndef PROJETMANAGER_H
#define PROJETMANAGER_H
#include <vector>
#include "projet.h"
#include "tache.h"

class ProjetManager
{
private:
    static ProjetManager * instanceUnique;
    vector<Projet *> projets;

    //DesignPattern Singleton
    ProjetManager();
    ~ProjetManager();
    ProjetManager(const ProjetManager & foo);
    ProjetManager & operator=(const ProjetManager & foo);
public:
    class TacheIterator{
    private:
        vector<Projet *>::iterator projetIterator;
        vector<Tache *>::iterator tacheIterator;

        //Le tacheIterator est initialisé avec l'itérator du premier projet de ProjetManager
        TacheIterator(vector<Projet *> p);
        TacheIterator(vector<Projet *>::iterator it_p, vector<Tache *>::iterator it_t);
        //TacheIterator(const TacheIterator&);
//        ~TacheIterator();
        friend class ProjetManager;
    public:
        //TacheIterator& end();
//        TacheIterator& operator=(const TacheIterator&);
//        bool operator==(const TacheIterator&);
//        bool operator!=(const TacheIterator&);
        TacheIterator& operator++(int);
        bool operator==(const TacheIterator &other) const;
        bool operator!=(const TacheIterator &other) const;
        Tache* operator*() const;
    };
    static ProjetManager &getInstance();

    Projet * ajouterProjet(const QString &identificateur, const QString &ti, const QDate& dispo, const QDate& deadline);
    TacheIterator tache_begin();
    TacheIterator tache_end();

    /* Autres fonctions */
    const unsigned int nbProjets() const;
};

#endif // PROJETMANAGER_H
