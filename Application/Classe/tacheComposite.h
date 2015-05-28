#ifndef TACHECOMPOSITE_H
#define TACHECOMPOSITE_H

class Tache;

class TacheComposite : public Tache {
    friend class ProjetManager;

    std::vector<Tache*> composition;
    TacheComposite* mere_compo;

    TacheComposite(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline);
    TacheComposite(const TacheComposite& t);
    TacheComposite& operator=(const TacheComposite& obj);
    ~TacheComposite();

public:


    /* Les Getters et Setters */
    std::vector<Tache *> &getComposition();
    const std::vector<Tache *> &getComposition() const;

    TacheComposite* getMere_Compo() const;
    void setMere_Compo(TacheComposite *value);

    /* Patron Factory Methode */
    virtual TacheComposite* clone() const;

    /* Autres Fonctions */
    void ajouterComposition(Tache *t);
    bool verifierComposition(const TacheComposite *t) const;
    unsigned int nbComposition() const;
};

#endif // TACHECOMPOSITE_H
