#include "editionTacheCompositeWindow.h"
#include "Classe/tache.h"
#include "Classe/tacheComposite.h"
#include "ui_editionTacheCompositeWindow.h"

EditionTacheCompositeWindow::EditionTacheCompositeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditionTacheCompositeWindow)
{
    ui->setupUi(this);
}

EditionTacheCompositeWindow::EditionTacheCompositeWindow(TacheComposite &T, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditionTacheCompositeWindow)
{
    ui->setupUi(this);
}

EditionTacheCompositeWindow::~EditionTacheCompositeWindow()
{
    delete ui;
}
