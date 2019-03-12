#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H

#include <QWidget>
#include <QToolButton>
#include "customviews/statewidget.h"
#include "home2widget.h"

namespace Ui {
class HomeWidget;
}

class HomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HomeWidget(QWidget *parent = 0);
    ~HomeWidget();

private:
    Ui::HomeWidget *ui;
    Home2Widget * home2Widget;

private:
    void optionStateWidgets ();
    void optionToolButtons () ;
    void optionToolButton (QToolButton * tb, QIcon icon, QString text);

private slots:

    void onStateWidgetHoverSlot(StateWidget*s) ;

    void onStateWidgetNoHoverSlot(StateWidget*s);

    void on_pushButton_clicked();

    void onHome2IntoNextSlot();
};

#endif // HOMEWIDGET_H
