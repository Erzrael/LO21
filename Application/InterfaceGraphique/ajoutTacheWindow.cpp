#include "ajoutTacheWindow.h"
#include "Classe/projetManager.h"
#include "Classe/projet.h"
#include "ui_ajoutTacheWindow.h"

AjoutTacheWindow::AjoutTacheWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutTacheWindow)
{
    ui->setupUi(this);
    ui->Dispo_Edit->setMinimumDate(QDate::currentDate());
    ui->Echeance_Edit->setMinimumDate(QDate::currentDate().addDays(1));
    ProjetManager &projetmanager = ProjetManager::getInstance();
    for(vector<Projet*>::const_iterator it = projetmanager.getProjets().begin(); it != projetmanager.getProjets().end(); ++it)
        ui->Projet_Box->addItem((*it)->getId());
}

AjoutTacheWindow::~AjoutTacheWindow()
{
    delete ui;
}

void AjoutTacheWindow::on_buttonBox_accepted()
{
    ProjetManager &projetmanager = ProjetManager::getInstance();
    if(ui->ID_Edit->text() == "" || ui->Titre_Edit->text() == "" ||
            (ui->Dispo_Edit->date() == ui->Echeance_Edit->date()))
        QMessageBox::warning(this,"Erreur","Certains champs sont vides ou incohérents");
    else {
        if(projetmanager.isTacheExistante(ui->ID_Edit->text())){
            QMessageBox::warning(this,"Erreur","La tâche existe déjà !");
        } else {
            projetmanager.ajouterTache(ui->Projet_Box->currentText(), ui->ID_Edit->text(), ui->Titre_Edit->text(),
                                       ui->Dispo_Edit->date(), ui->Echeance_Edit->date(),
                                       Duree(ui->Heure_Box->value(), ui->Minute_Box->value()),
                                       ui->Preemptee_Box->isChecked());
            QMessageBox::information(this,"Succès","La tâche a bien été créée !");
        }
    }
}
