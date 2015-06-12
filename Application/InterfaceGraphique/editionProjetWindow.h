#ifndef EDITIONPROJETWINDOW_H
#define EDITIONPROJETWINDOW_H

#include <QDialog>

class Projet;

namespace Ui {
class EditionProjetWindow;
}

class EditionProjetWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditionProjetWindow(QWidget *parent = 0);
    explicit EditionProjetWindow(Projet* P, QWidget *parent = 0);
    ~EditionProjetWindow();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::EditionProjetWindow *ui;
};

#endif // EDITIONPROJETWINDOW_H
