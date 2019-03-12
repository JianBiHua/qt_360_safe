#ifndef FIX2WIDGET_H
#define FIX2WIDGET_H

#include <QWidget>

namespace Ui {
class Fix2Widget;
}

class Fix2Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Fix2Widget(QWidget *parent = 0);
    ~Fix2Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Fix2Widget *ui;

signals:
    void onFix2IntoNextSignal ();

private:
    void optionListWidget ();
};

#endif // FIX2WIDGET_H
