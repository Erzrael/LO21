#ifndef SUPPRIMERPRECEDENCEWINDOW_H
#define SUPPRIMERPRECEDENCEWINDOW_H

#include <QDialog>

namespace Ui {
class SupprimerPrecedenceWindow;
}

class SupprimerPrecedenceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SupprimerPrecedenceWindow(QWidget *parent = 0);
    ~SupprimerPrecedenceWindow();

private slots:
    void on_Projet_Box_currentTextChanged(const QString);

    void on_Precedee_Box_currentTextChanged(const QString);

    void on_buttonBox_accepted();

private:
    Ui::SupprimerPrecedenceWindow *ui;
};

#endif // SUPPRIMERPRECEDENCEWINDOW_H
