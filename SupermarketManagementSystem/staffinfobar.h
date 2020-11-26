#ifndef STAFFINFOBAR_H
#define STAFFINFOBAR_H

#include <QWidget>

namespace Ui {
class staffInfoBar;
}

class staffInfoBar : public QWidget
{
    Q_OBJECT

public:
    explicit staffInfoBar(QWidget *parent = nullptr);
    ~staffInfoBar();

private:
    Ui::staffInfoBar *ui;
};

#endif // STAFFINFOBAR_H
