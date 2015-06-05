#ifndef AJOUTTACHEUNITAIREWINDOW_H
#define AJOUTTACHEUNITAIREWINDOW_H

#include <QDialog>

namespace Ui {
class AjoutTacheUnitaireWindow;
}

class AjoutTacheUnitaireWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutTacheUnitaireWindow(QWidget *parent = 0);
    ~AjoutTacheUnitaireWindow();

private:
    Ui::AjoutTacheUnitaireWindow *ui;
};

#endif // AJOUTTACHEUNITAIREWINDOW_H
