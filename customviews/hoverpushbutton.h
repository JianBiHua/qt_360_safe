#ifndef HOVERPUSHBUTTON_H
#define HOVERPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QPaintEvent>
#include <QEvent>

class HoverPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit HoverPushButton(QWidget *parent = 0);

signals:
public slots:
protected:
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent * event) ;

signals:
    void onHoverPushButtonHoverSinal(HoverPushButton * w );
    void onHoverPushButtonNoHoverSinal (HoverPushButton * w );

};

#endif // HOVERPUSHBUTTON_H
