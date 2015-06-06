#ifndef EDITIONTACHEUNITAIREWINDOW_H
#define EDITIONTACHEUNITAIREWINDOW_H

#include <QDialog>

class TacheUnitaire;

namespace Ui {
class EditionTacheUnitaireWindow;
}

class EditionTacheUnitaireWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditionTacheUnitaireWindow(QWidget *parent = 0);
    EditionTacheUnitaireWindow(TacheUnitaire &T, QWidget *parent = 0);
    ~EditionTacheUnitaireWindow();

private:
    Ui::EditionTacheUnitaireWindow *ui;
};

#endif // EDITIONTACHEUNITAIREWINDOW_H
