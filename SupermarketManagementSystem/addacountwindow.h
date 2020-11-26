#ifndef ADDACOUNTWINDOW_H
#define ADDACOUNTWINDOW_H

#include <QMainWindow>

namespace Ui {
class addAcountWindow;
}

class addAcountWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit addAcountWindow(QWidget *parent = nullptr);
    ~addAcountWindow();
signals:
    void addStaffInfo(const QString& account,const QString& passwd);
private slots:
    void on_addButton_clicked();

private:
    Ui::addAcountWindow *ui;
};

#endif // ADDACOUNTWINDOW_H
