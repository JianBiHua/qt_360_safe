#ifndef OPTIMIZE2WIDGET_H
#define OPTIMIZE2WIDGET_H

#include <QWidget>

namespace Ui {
class Optimize2Widget;
}

class Optimize2Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Optimize2Widget(QWidget *parent = 0);
    ~Optimize2Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Optimize2Widget *ui;

signals:
    void onOptimize2IntoNextSignal ();
};

#endif // OPTIMIZE2WIDGET_H
