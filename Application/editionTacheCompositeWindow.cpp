#include "editionTacheCompositeWindow.h"
#include "ui_editionTacheCompositeWindow.h"

EditionTacheCompositeWindow::EditionTacheCompositeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditionTacheCompositeWindow)
{
    ui->setupUi(this);
}

EditionTacheCompositeWindow::~EditionTacheCompositeWindow()
{
    delete ui;
}
