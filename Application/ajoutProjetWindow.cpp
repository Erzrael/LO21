#include "ajoutProjetWindow.h"
#include "ui_AjoutProjetWindow.h"

AjoutProjetWindow::AjoutProjetWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutProjetWindow)
{
    ui->setupUi(this);
}

AjoutProjetWindow::~AjoutProjetWindow()
{
    delete ui;
}
