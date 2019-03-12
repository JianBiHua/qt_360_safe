#ifndef HORSEWIDGET_H
#define HORSEWIDGET_H

#include <QWidget>
#include <QToolButton>
#include "horse2widget.h"

namespace Ui {
class HorseWidget;
}

class HorseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HorseWidget(QWidget *parent = 0);
    ~HorseWidget();

private:
    Ui::HorseWidget *ui;
    Horse2Widget * horse2Widget;

private:
    void optionToolButtons ();
    void optionToolButton (QToolButton * tb,
                           QIcon icon,
                           QString text,
                           QSize size,
                           QString property);
    void optionPushButtons () ;

signals:

private slots:
    void on_pushButton_clicked();

    void onHorse2IntoNextSlot ();
    void on_tbQuanpan_clicked();
    void on_pushButton_2_clicked();
};

#endif // HORSEWIDGET_H
