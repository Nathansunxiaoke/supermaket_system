#ifndef STAFFITEM_H
#define STAFFITEM_H

#include <QWidget>
#include <QInputDialog>

namespace Ui {
class staffitem;
}

class staffitem : public QWidget
{
    Q_OBJECT

public:
    explicit staffitem(QWidget *parent = nullptr);
    ~staffitem();

    /* 设置自定义条目信息 */
    void setstaffinfo(const QString& number,const QString& account,const QString& passwd);
private slots:
    void on_changeButton_clicked();
private:
    Ui::staffitem *ui;
};

#endif // STAFFITEM_H
