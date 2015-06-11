#ifndef SUPPRIMERCOMPOSITIONWINDOW_H
#define SUPPRIMERCOMPOSITIONWINDOW_H

#include <QDialog>

namespace Ui {
class SupprimerCompositionWindow;
}

class SupprimerCompositionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SupprimerCompositionWindow(QWidget *parent = 0);
    ~SupprimerCompositionWindow();

private slots:
    void on_Tache_Box_currentTextChanged(const QString &arg1);

    void on_Composante_Box_currentTextChanged(const QString &arg1);

private:
    Ui::SupprimerCompositionWindow *ui;
};

#endif // SUPPRIMERCOMPOSITIONWINDOW_H
