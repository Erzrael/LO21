#ifndef AJOUTPROGRAMMATION_H
#define AJOUTPROGRAMMATION_H

#include <QDialog>
#include <QDate>
#include <QTime>

namespace Ui {
   class ajoutProgrammation;
}

class ajoutProgrammation : public QDialog
{
   Q_OBJECT

public:
   explicit ajoutProgrammation(QWidget *parent = 0, QDate date = QDate(), QTime h_debut = QTime());

   ~ajoutProgrammation();

private slots:
   void on_cancel_ok_accepted();

private:
   Ui::ajoutProgrammation *ui;
};

#endif // AJOUTPROGRAMMATION_H
