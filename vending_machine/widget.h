#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    int money{0};
    void changeMoney(int diff);

private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbcoffee_clicked();

    void on_pbTea_clicked();

    void on_pbcola_clicked();

    void on_pbReset_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
