#include "supprimerTacheWindow.h"
#include "ui_supprimerTacheWindows.h"
#include "Classe/projetManager.h"
#include "Classe/projet.h"

SupprimerTacheWindow::SupprimerTacheWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupprimerTacheWindow)
{
    ui->setupUi(this);
    ProjetManager &projetmanager = ProjetManager::getInstance();
    for(vector<Projet*>::const_iterator it = projetmanager.getProjets().begin(); it != projetmanager.getProjets().end(); ++it)
        ui->Projet_Box->addItem((*it)->getId());
}

SupprimerTacheWindow::~SupprimerTacheWindow()
{
    delete ui;
}

void SupprimerTacheWindow::on_Projet_Box_currentTextChanged(const QString )
{
    ui->Tache_Box->clear();
    ProjetManager &projetmanager = ProjetManager::getInstance();

    Projet* P = projetmanager.getProjet(ui->Projet_Box->currentText());

    for(vector<Tache*>::const_iterator it = P->getTaches().begin(); it != P->getTaches().end(); ++it){
        ui->Tache_Box->addItem((*it)->getIdentificateur());
    }
}

void SupprimerTacheWindow::on_buttonBox_accepted()
{
    ProjetManager &projetmanager = ProjetManager::getInstance();

    Projet* P = projetmanager.getProjet(ui->Projet_Box->currentText());

    try{
        P->supprimerTache(ui->Tache_Box->currentText());
        QMessageBox::information(this,"Succès","La tache a bien été supprimé");
    } catch (CalendarException e) {
        QMessageBox::warning(this,"Erreur",e.getInfo());
    }
}
