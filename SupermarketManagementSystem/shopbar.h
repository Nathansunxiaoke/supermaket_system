#ifndef SHOPBAR_H
#define SHOPBAR_H

#include <QWidget>

namespace Ui {
class shopBar;
}

class shopBar : public QWidget
{
    Q_OBJECT

public:
    explicit shopBar(QWidget *parent = nullptr);
    ~shopBar();

private:
    Ui::shopBar *ui;
};

#endif // SHOPBAR_H
