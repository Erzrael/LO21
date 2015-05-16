#ifndef TACHECOMPOSITE_H
#define TACHECOMPOSITE_H

#include "tache.h"

class TacheComposite : public Tache {

    std::vector<Tache*> composition;

public:

    TacheComposite(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline);
    TacheComposite(const TacheComposite& t);
    TacheComposite& operator=(const TacheComposite& obj);
    ~TacheComposite();

    /* Les Getters et Setters */

    std::vector<Tache *> &getComposition();
    const std::vector<Tache *> &getComposition() const;

    /* Autres Fonctions */

    void ajouterComposition(Tache *t);
    void afficher() const;

};

#endif // TACHECOMPOSITE_H
