#include "Classe/projetManager.h"
#include "Classe/projet.h"
#include "editionProjetWindow.h"
#include "ui_editionProjetWindow.h"

EditionProjetWindow::EditionProjetWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditionProjetWindow)
{
    ui->setupUi(this);
}

EditionProjetWindow::EditionProjetWindow(Projet* P, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditionProjetWindow)
{
    ui->setupUi(this);
    ui->ID_Lab->setText(P->getId());
    ui->Titre_Edit->setText(P->getTitre());
    ui->Dispo_Edit->setDate(P->getDisponibilite());
    ui->Echeance_Edit->setDate(P->getEcheance());
}

EditionProjetWindow::~EditionProjetWindow()
{
    delete ui;
}

void EditionProjetWindow::on_buttonBox_accepted()
{
    ProjetManager &projetmanager = ProjetManager::getInstance();

    try{
        Projet* P = projetmanager.getProjet(ui->ID_Lab->text());
        P->setTitre(ui->Titre_Edit->text());
        P->setDisponibilite(ui->Dispo_Edit->date());
        QMessageBox::information(this,"Succès","La tâche a bien été modifée");
    } catch (CalendarException e) {
        QMessageBox::warning(this,"Erreur",e.getInfo());
    }
}
