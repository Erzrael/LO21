#include "supprimerPrecedenceWindow.h"
#include "ui_supprimerPrecedenceWindow.h"
#include "Classe/projetManager.h"
#include "Classe/projet.h"
#include "Classe/tache.h"

SupprimerPrecedenceWindow::SupprimerPrecedenceWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupprimerPrecedenceWindow)
{
    ui->setupUi(this);
    ProjetManager &projetmanager = ProjetManager::getInstance();
    for(vector<Projet*>::const_iterator it = projetmanager.getProjets().begin(); it != projetmanager.getProjets().end(); ++it)
        ui->Projet_Box->addItem((*it)->getId());
}

SupprimerPrecedenceWindow::~SupprimerPrecedenceWindow()
{
    delete ui;
}

void SupprimerPrecedenceWindow::on_Projet_Box_currentTextChanged(const QString)
{
    ui->Precedee_Box->clear();
    ui->Precedente_Box->clear();
    ProjetManager &projetmanager = ProjetManager::getInstance();

    Projet* P = projetmanager.getProjet(ui->Projet_Box->currentText());

    for(vector<Tache*>::const_iterator it = P->getTaches().begin(); it != P->getTaches().end(); ++it){
        if(!((*it)->getPrecedence().empty()))
            ui->Precedee_Box->addItem((*it)->getIdentificateur());
    }
}

void SupprimerPrecedenceWindow::on_Precedee_Box_currentTextChanged(const QString)
{
    if(ui->Precedee_Box->currentText() != ""){
        ui->Precedente_Box->clear();
        ProjetManager &projetmanager = ProjetManager::getInstance();

        Projet* P = projetmanager.getProjet(ui->Projet_Box->currentText());

        Tache* T = P->trouverTache(ui->Precedee_Box->currentText());

        for(vector<Tache*>::const_iterator it = T->getPrecedence().begin(); it != T->getPrecedence().end(); ++it)
            ui->Precedente_Box->addItem((*it)->getIdentificateur());
    }
}

void SupprimerPrecedenceWindow::on_buttonBox_accepted()
{
    ProjetManager &projetmanager = ProjetManager::getInstance();

    Projet* P = projetmanager.getProjet(ui->Projet_Box->currentText());

    Tache* T = P->trouverTache(ui->Precedee_Box->currentText());

    try{
        T->supprimerPrecedence(ui->Precedente_Box->currentText());
        QMessageBox::information(this,"Succès","La precédence a bien été supprimée");
    } catch (CalendarException e) {
        QMessageBox::warning(this,"Erreur",e.getInfo());
    }
}
