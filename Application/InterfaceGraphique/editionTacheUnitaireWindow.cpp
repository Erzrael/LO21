#include "editionTacheUnitaireWindow.h"
#include "Classe/tache.h"
#include "Classe/tacheUnitaire.h"
#include "ui_editionTacheUnitaireWindow.h"

EditionTacheUnitaireWindow::EditionTacheUnitaireWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditionTacheUnitaireWindow)
{
    ui->setupUi(this);
}

EditionTacheUnitaireWindow::EditionTacheUnitaireWindow(TacheUnitaire& T, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditionTacheUnitaireWindow)
{
    ui->setupUi(this);
}

EditionTacheUnitaireWindow::~EditionTacheUnitaireWindow()
{
    delete ui;
}
