#include "supprimerTacheWindow.h"
#include "ui_supprimerTacheWindows.h"

SupprimerTacheWindow::SupprimerTacheWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupprimerTacheWindow)
{
    ui->setupUi(this);
}

SupprimerTacheWindow::~SupprimerTacheWindow()
{
    delete ui;
}
