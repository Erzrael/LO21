#ifndef TACHECOMPOSITE_H
#define TACHECOMPOSITE_H
#include <vector>
#include <QDate>
#include <QString>
#include <ExportImport/rapidxml-1.13/rapidxml.hpp>

class Tache;

class TacheComposite : public Tache {
    friend class ProjetManager;

    std::vector<Tache*> composition;

    TacheComposite(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline);
    TacheComposite(const TacheComposite& t);
    TacheComposite& operator=(const TacheComposite& obj);
    ~TacheComposite();

public:


    /* Les Getters et Setters */
    std::vector<Tache *> &getComposition();
    const std::vector<Tache *> &getComposition() const;

    /* Autres Fonctions */
    void ajouterComposition(Tache &t);
    unsigned int nbComposition() const;

    virtual void xml_ajouterAttributs(rapidxml::xml_document<> & doc, rapidxml::xml_node<> & node_tache);
};

#endif // TACHECOMPOSITE_H
