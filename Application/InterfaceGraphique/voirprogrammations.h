#ifndef VOIRPROGRAMMATIONS_H
#define VOIRPROGRAMMATIONS_H

#include <QDialog>
#include <QDate>
#include <QTime>

namespace Ui {
   class VoirProgrammations;
}

class VoirProgrammations : public QDialog
{
   Q_OBJECT

public:
   explicit VoirProgrammations(QWidget *parent = 0, QDate date = QDate(), QTime h_debut = QTime());
   ~VoirProgrammations();
private slots:
   void on_ajouterProg_clicked();
   void on_suppr_clicked();
private:
   void load_tab();

   Ui::VoirProgrammations *ui;
   QDate date;
   QTime time;
};

#endif // VOIRPROGRAMMATIONS_H
