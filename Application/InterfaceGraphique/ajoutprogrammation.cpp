#include "ajoutprogrammation.h"
#include "ui_ajoutprogrammation.h"

ajoutProgrammation::ajoutProgrammation(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::ajoutProgrammation)
{
   ui->setupUi(this);
}

ajoutProgrammation::~ajoutProgrammation()
{
   delete ui;
}
