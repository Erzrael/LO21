#ifndef SUPPRIMERPROJETWINDOW_H
#define SUPPRIMERPROJETWINDOW_H

#include <QDialog>

namespace Ui {
class SupprimerProjetWindow;
}

class SupprimerProjetWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SupprimerProjetWindow(QWidget *parent = 0);
    ~SupprimerProjetWindow();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SupprimerProjetWindow *ui;
};

#endif // SUPPRIMERPROJETWINDOW_H
