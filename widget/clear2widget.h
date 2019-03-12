#ifndef CLEAR2WIDGET_H
#define CLEAR2WIDGET_H

#include <QWidget>

namespace Ui {
class Clear2Widget;
}

class Clear2Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Clear2Widget(QWidget *parent = 0);
    ~Clear2Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Clear2Widget *ui;

signals:
    void onClear2IntoNextSignal ();
};

#endif // CLEAR2WIDGET_H
