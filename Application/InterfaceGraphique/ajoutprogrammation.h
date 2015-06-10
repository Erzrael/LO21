#ifndef AJOUTPROGRAMMATION_H
#define AJOUTPROGRAMMATION_H

#include <QDialog>

namespace Ui {
   class ajoutProgrammation;
}

class ajoutProgrammation : public QDialog
{
   Q_OBJECT

public:
   explicit ajoutProgrammation(QWidget *parent = 0);
   ~ajoutProgrammation();

private:
   Ui::ajoutProgrammation *ui;
};

#endif // AJOUTPROGRAMMATION_H
