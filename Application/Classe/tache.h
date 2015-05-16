#ifndef TACHE_H
#define TACHE_H

#include <QString>
#include <QDate>
#include <vector>
#include <Classe/calendarException.h>

/*
 * La classe Tache est abstraite. vector demande une classe non abstraite. Précédence sera implémenter dans les classes filles.
 * La fonction afficher servira de méthode virtuelle pure à défaut d'en trouver une autre.
 *
*/
class Tache {
    std::vector<Tache*> precedence;
    QString identificateur;
    QString titre;
    QDate disponibilite;
    QDate echeance;


public:
    bool verifierPrecedence(const Tache& t) const;
    /*
     * Pour utiliser le template vector, il faut que le constructeur soit public, sinon il met une erreur.
    */
    Tache(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline);
    Tache(const Tache& t);
    Tache& operator=(const Tache& obj);
    virtual ~Tache();

    /* Les Setter et Getter */
    QString& getIdentificateur();
    const QString& getIdentificateur() const;
    void setIdentificateur(const QString &value);

    QString& getTitre();
    const QString& getTitre() const;
    void setTitre(const QString &value);

    QDate& getDisponibilite();
    const QDate& getDisponibilite() const;
    void setDisponibilite(const QDate &value);

    QDate& getEcheance();
    const QDate& getEcheance() const;
    void setEcheance(const QDate &value);

    std::vector<Tache *> &getPrecedence();
    const std::vector<Tache *> &getPrecedence() const;

    /* Patron Factory Methode */
    virtual Tache* clone() const = 0;

    /* Autres Fonctions */
    void ajouterPrecedence(Tache& t);
};

#endif // TACHE_H
