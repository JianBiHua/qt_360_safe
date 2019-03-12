#ifndef STATEWIDGET_H
#define STATEWIDGET_H

#include <QWidget>

namespace Ui {
class StateWidget;
}

class StateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StateWidget(QWidget *parent = 0);
    ~StateWidget();

private:
    Ui::StateWidget *ui;
    int mState;

signals:
    void onStateWidgetHoverSinal(StateWidget * w);
    void onStateWidgetNoHoverSinal (StateWidget * w);

public:
    void show (QString icon, QString txt, int state);
    void setState (int state) ;
    int getState ();

protected:
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent * event) ;
};

#endif // STATEWIDGET_H
