#include "progressbarwidget.h"
#include <QPainter>

ProgressBarWidget::ProgressBarWidget(QWidget *parent) : QWidget(parent)
{
    mColor = QColor(0x29, 0xeb, 0x42);
    mProgress = 0;
}

void ProgressBarWidget::setColor (QColor color) {
    mColor = color;
    update ();
}
void ProgressBarWidget::setProgress (float progress){
    mProgress = progress;
    update ();
}

void ProgressBarWidget::paintEvent (QPaintEvent *event) {
    QWidget::paintEvent (event);

    //
    QPainter painter(this);
    painter.setPen (QPen(Qt::transparent, 0));
    painter.setBrush (mColor);

    painter.drawRect (0, 0, width ()*mProgress, height ());
}
