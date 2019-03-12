#include "hoverpushbutton.h"

HoverPushButton::HoverPushButton(QWidget *parent) : QPushButton(parent)
{

}

void HoverPushButton::enterEvent(QEvent *event) {
    emit onHoverPushButtonHoverSinal (this);
}

void HoverPushButton::leaveEvent(QEvent * event) {
    emit onHoverPushButtonNoHoverSinal (this);
}
