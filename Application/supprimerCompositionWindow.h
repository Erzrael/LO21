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

private:
    Ui::SupprimerCompositionWindow *ui;
};

#endif // SUPPRIMERCOMPOSITIONWINDOW_H
