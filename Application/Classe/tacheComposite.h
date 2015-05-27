#ifndef TACHECOMPOSITE_H
#define TACHECOMPOSITE_H

class Tache;

class TacheComposite : public Tache {
    friend class ProjetManager;

    std::vector<Tache*> composition;

    TacheComposite(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline);
    TacheComposite(const TacheComposite& t);
    TacheComposite& operator=(const TacheComposite& obj);

public:

    ~TacheComposite();

    /* Les Getters et Setters */
    std::vector<Tache *> &getComposition();
    const std::vector<Tache *> &getComposition() const;

    /* Patron Factory Methode */
    virtual TacheComposite* clone() const;

    /* Autres Fonctions */
    void ajouterComposition(Tache &t);
    unsigned int nbComposition() const;
};

#endif // TACHECOMPOSITE_H
