#include "Classe/tache.h"
#include "Classe/projetManager.h"
#include "Classe/tacheComposite.h"
#include "editionTacheCompositeWindow.h"
#include "ui_editionTacheCompositeWindow.h"

EditionTacheCompositeWindow::EditionTacheCompositeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditionTacheCompositeWindow)
{
    ui->setupUi(this);
}

EditionTacheCompositeWindow::EditionTacheCompositeWindow(TacheComposite *T, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditionTacheCompositeWindow)
{
    ui->setupUi(this);
    ui->ID_Lab->setText(T->getIdentificateur());
    ui->Titre_Edit->setText(T->getTitre());
    ui->Dispo_Edit->setDate(T->getDisponibilite());
    ui->Echeance_Edit->setDate(T->getEcheance());
}

EditionTacheCompositeWindow::~EditionTacheCompositeWindow()
{
    delete ui;
}

void EditionTacheCompositeWindow::on_buttonBox_accepted()
{
    ProjetManager &projetmanager = ProjetManager::getInstance();

    try{
        TacheComposite* Composite = dynamic_cast<TacheComposite*>(projetmanager.getTache(ui->ID_Lab->text()));
        Composite->setTitre(ui->Titre_Edit->text());
        Composite->setDisponibilite(ui->Dispo_Edit->date());
        Composite->setEcheance(ui->Echeance_Edit->date());
        QMessageBox::information(this,"Succès","La tâche a bien été modifée");
    } catch (CalendarException e) {
        QMessageBox::warning(this,"Erreur",e.getInfo());
    }
}
