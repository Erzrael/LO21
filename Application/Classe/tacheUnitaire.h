#ifndef TACHEUNITAIRE_H
#define TACHEUNITAIRE_H

#include <ExportImport/rapidxml-1.13/rapidxml.hpp>
#include "duree.h"
#include "evenement.h"


class Tache;

class TacheUnitaire : public Tache, public Evenement {
    friend class ProjetManager;

    bool preempte;

    TacheUnitaire(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline, const Duree& dur, const bool& pre = false);
    TacheUnitaire(const TacheUnitaire& t);
    TacheUnitaire& operator=(const TacheUnitaire& obj);
    ~TacheUnitaire();

public:


    /* Les Getters et Setters */
    const bool& getPreempte() const;
    bool& getPreempte();
    void setPreempte(bool value);

    //const Duree& getDuree() const;
    //Duree& getDuree();
    //void setDuree(const Duree &value);

    /* Patron Factory Methode */
    // Tache interface
    virtual TacheUnitaire* clone() const;
    virtual void xml_ajouterAttributs(rapidxml::xml_document<> & doc, rapidxml::xml_node<> & node_tache);
    // Evenement interface
    const QString &getID();
};

#endif // TACHEUNITAIRE_H
