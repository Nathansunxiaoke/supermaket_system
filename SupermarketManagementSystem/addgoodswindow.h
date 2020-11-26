#ifndef ADDGOODSWINDOW_H
#define ADDGOODSWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class addGoodsWindow;
}

class addGoodsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit addGoodsWindow(QWidget *parent = nullptr);
    ~addGoodsWindow();
signals:
    void addGoodsInfo(const QString& nameGoods,const QString& kindGoods,
                      int purchasingPrice,int retailPrice,
                      int quentityStock);
private slots:
    void on_addGoodsButton_clicked();

private:
    Ui::addGoodsWindow *ui;
};

#endif // ADDGOODSWINDOW_H
