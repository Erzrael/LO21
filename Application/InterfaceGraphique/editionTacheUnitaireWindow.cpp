#include "editionTacheUnitaireWindow.h"
#include "Classe/projetManager.h"
#include "ui_editionTacheUnitaireWindow.h"

EditionTacheUnitaireWindow::EditionTacheUnitaireWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditionTacheUnitaireWindow)
{
    ui->setupUi(this);
}

EditionTacheUnitaireWindow::EditionTacheUnitaireWindow(TacheUnitaire *T, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditionTacheUnitaireWindow)
{
    ui->setupUi(this);
    ui->ID_Lab->setText(T->getIdentificateur());
    ui->Titre_Edit->setText(T->getTitre());
    ui->Dispo_Edit->setDate(T->getDisponibilite());
    ui->Echeance_Edit->setDate(T->getEcheance());
    ui->Preempte_Box->setChecked(T->getPreempte());
    ui->Heure_Box->setValue(T->getDuree().getHeure());
    ui->Minute_Box->setValue(T->getDuree().getMinute());
}

EditionTacheUnitaireWindow::~EditionTacheUnitaireWindow()
{
    delete ui;
}

void EditionTacheUnitaireWindow::on_buttonBox_accepted()
{
    ProjetManager &projetmanager = ProjetManager::getInstance();

    TacheUnitaire* Unitaire = dynamic_cast<TacheUnitaire*>(projetmanager.getTache(ui->ID_Lab->text()));
    Unitaire->setTitre(ui->Titre_Edit->text());
    Unitaire->setDisponibilite(ui->Dispo_Edit->date());
    Unitaire->setEcheance(ui->Echeance_Edit->date());
    Unitaire->setPreempte(ui->Preempte_Box->isChecked());
    Unitaire->setDuree(Duree(ui->Heure_Box->value(), ui->Minute_Box->value()));
    QMessageBox::information(this,"Succès","La tâche a bien été modifée");
}
