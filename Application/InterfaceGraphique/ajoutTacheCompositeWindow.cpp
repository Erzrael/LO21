#include "ajoutTacheCompositeWindow.h"
#include "ui_ajoutTacheCompositeWindow.h"

AjoutTacheCompositeWindow::AjoutTacheCompositeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutTacheCompositeWindow)
{
    ui->setupUi(this);
}

AjoutTacheCompositeWindow::~AjoutTacheCompositeWindow()
{
    delete ui;
}
