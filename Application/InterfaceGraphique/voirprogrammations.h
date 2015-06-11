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

private:
   Ui::VoirProgrammations *ui;
};

#endif // VOIRPROGRAMMATIONS_H
