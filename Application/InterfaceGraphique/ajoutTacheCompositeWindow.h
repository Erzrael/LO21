#ifndef AJOUTTACHECOMPOSITEWINDOW_H
#define AJOUTTACHECOMPOSITEWINDOW_H

#include <QDialog>

namespace Ui {
class AjoutTacheCompositeWindow;
}

class AjoutTacheCompositeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutTacheCompositeWindow(QWidget *parent = 0);
    ~AjoutTacheCompositeWindow();

private:
    Ui::AjoutTacheCompositeWindow *ui;
};

#endif // AJOUTTACHECOMPOSITEWINDOW_H
