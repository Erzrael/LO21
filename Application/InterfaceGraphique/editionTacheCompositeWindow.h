#ifndef EDITIONTACHECOMPOSITE_H
#define EDITIONTACHECOMPOSITE_H

#include <QDialog>

class TacheComposite;

namespace Ui {
class EditionTacheCompositeWindow;
}

class EditionTacheCompositeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditionTacheCompositeWindow(QWidget *parent = 0);
    explicit EditionTacheCompositeWindow(TacheComposite* T, QWidget *parent = 0);
    ~EditionTacheCompositeWindow();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::EditionTacheCompositeWindow *ui;
};

#endif // EDITIONTACHECOMPOSITE_H
