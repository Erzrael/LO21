#include "ajoutPrecedenceWindow.h"
#include "ui_ajoutPrecedenceWindow.h"
#include "Classe/projetManager.h"
#include "Classe/projet.h"


AjoutPrecedenceWindow::AjoutPrecedenceWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutPrecedenceWindow)
{
    ui->setupUi(this);

    ProjetManager &projetmanager = ProjetManager::getInstance();
    for(vector<Projet*>::const_iterator it = projetmanager.getProjets().begin(); it != projetmanager.getProjets().end(); ++it)
        ui->Projet_Box->addItem((*it)->getId());
}

AjoutPrecedenceWindow::~AjoutPrecedenceWindow()
{
    delete ui;
}

void AjoutPrecedenceWindow::on_buttonBox_accepted()
{
    ProjetManager &projetmanager = ProjetManager::getInstance();
    Tache* Precedee = projetmanager.getTache(ui->Precedee_Box->currentText());
    Tache* Precedente = projetmanager.getTache(ui->Precedente_Box->currentText());
    if(Precedee->verifierPrecedence(*Precedente)){
        Precedee->ajouterPrecedence(*Precedente);
        QMessageBox::information(this,"Succès","La precédence a été créée.");
    } else {
        QMessageBox::warning(this,"Erreur","La precédence n'a pu être effectuée.");
    }
}

void AjoutPrecedenceWindow::on_Projet_Box_currentTextChanged(const QString )
{
    ui->Precedente_Box->clear();
    ui->Precedee_Box->clear();
    ProjetManager &projetmanager = ProjetManager::getInstance();

    Projet* P = projetmanager.getProjet(ui->Projet_Box->currentText());

    for(vector<Tache*>::const_iterator it = P->getTaches().begin(); it != P->getTaches().end(); ++it){
        ui->Precedee_Box->addItem((*it)->getIdentificateur());
    }
}

void AjoutPrecedenceWindow::on_Precedee_Box_currentTextChanged(const QString )
{
    if(ui->Precedee_Box->currentText() != ""){
        ui->Precedente_Box->clear();
        ProjetManager &projetmanager = ProjetManager::getInstance();

        Projet* P = projetmanager.getProjet(ui->Projet_Box->currentText());

        Tache* T = P->trouverTache(ui->Precedee_Box->currentText());

        for(vector<Tache*>::const_iterator it = P->getTaches().begin(); it != P->getTaches().end(); ++it){
            if(T->verifierPrecedence(**it))
                ui->Precedente_Box->addItem((*it)->getIdentificateur());
        }
    }
}
