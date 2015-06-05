#include "choixTacheWindow.h"
#include "ui_choixTacheWindow.h"
#include "tacheEditionWindow.h"
#include "editionTacheCompositeWindow.h"

ChoixTacheWindow::ChoixTacheWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChoixTacheWindow)
{
    ui->setupUi(this);
}

ChoixTacheWindow::~ChoixTacheWindow()
{
    delete ui;
}

void ChoixTacheWindow::on_Ok_Button_clicked()
{
    EditionTacheCompositeWindow edition_tache_composite_window;
    edition_tache_composite_window.setModal(true);
    edition_tache_composite_window.exec();
}
