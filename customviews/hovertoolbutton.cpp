#include "hovertoolbutton.h"

HoverToolButton::HoverToolButton(QWidget *parent) : QToolButton(parent)
{
}

void HoverToolButton::enterEvent(QEvent *event) {
    emit onHoverToolButtonHoverSinal (this);
}

void HoverToolButton::leaveEvent(QEvent * event) {
    emit onHoverToolButtonNoHoverSinal (this);
}
