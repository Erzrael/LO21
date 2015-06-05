#ifndef TACHEEDITIONWINDOW_H
#define TACHEEDITIONWINDOW_H

#include <QDialog>

namespace Ui {
class TacheEditionWindow;
}

class TacheEditionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TacheEditionWindow(QWidget *parent = 0);
    ~TacheEditionWindow();

private:
    Ui::TacheEditionWindow *ui;
};

#endif // TACHEEDITIONWINDOW_H
