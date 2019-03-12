#ifndef HOVERTOOLBUTTON_H
#define HOVERTOOLBUTTON_H

#include <QWidget>
#include <QToolButton>

class HoverToolButton : public QToolButton
{
    Q_OBJECT
public:
    explicit HoverToolButton(QWidget *parent = 0);

signals:

public slots:

protected:
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent * event) ;

signals:
    void onHoverToolButtonHoverSinal(HoverToolButton * w);
    void onHoverToolButtonNoHoverSinal (HoverToolButton * w);

};

#endif // HOVERTOOLBUTTON_H
