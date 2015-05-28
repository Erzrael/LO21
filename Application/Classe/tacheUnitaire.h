#ifndef TACHEUNITAIRE_H
#define TACHEUNITAIRE_H

#include "duree.h"

class Tache;

class TacheUnitaire : public Tache {
    friend class ProjetManager;

    bool preempte;
    Duree duree;

    TacheUnitaire(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline, const Duree& dur, const bool& pre = false);
    TacheUnitaire(const TacheUnitaire& t);
    TacheUnitaire& operator=(const TacheUnitaire& obj);
    ~TacheUnitaire();

public:


    /* Les Getters et Setters */
    const bool& getPreempte() const;
    bool& getPreempte();
    void setPreempte(bool value);

    const Duree& getDuree() const;
    Duree& getDuree();
    void setDuree(const Duree &value);

    /* Patron Factory Methode */
    virtual TacheUnitaire* clone() const;
};

#endif // TACHEUNITAIRE_H
