#ifndef TACHEUNITAIRE_H
#define TACHEUNITAIRE_H

#include "tache.h"
#include "duree.h"

class TacheUnitaire : public Tache {

    bool preempte;
    Duree duree;

public:

    TacheUnitaire(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline, const Duree& dur, const bool& pre = false);
    TacheUnitaire(const TacheUnitaire& t);
    TacheUnitaire& operator=(const TacheUnitaire& obj);
    ~TacheUnitaire();

    /* Les Getters et Setters */

    const bool& getPreempte() const;
    bool& getPreempte();
    void setPreempte(bool value);

    const Duree& getDuree() const;
    Duree& getDuree();
    void setDuree(const Duree &value);

    /* Autres Fonctions */

    void afficher() const;

};

#endif // TACHEUNITAIRE_H
