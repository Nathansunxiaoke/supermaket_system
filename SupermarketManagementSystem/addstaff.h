#ifndef ADDSTAFF_H
#define ADDSTAFF_H

#include <QWidget>

namespace Ui {
class addStaff;
}

class addStaff : public QWidget
{
    Q_OBJECT

public:
    explicit addStaff(QWidget *parent = nullptr);
    ~addStaff();

signals:
    void addStaffInfo(const QString& account,const QString& passwd);
private slots:
    void on_addButton_clicked();

private:
    Ui::addStaff *ui;
};

#endif // ADDSTAFF_H
