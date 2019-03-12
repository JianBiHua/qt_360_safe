#include "checkwidget.h"
#include <QPainter>

CheckWidget::CheckWidget(QWidget *parent) : QWidget(parent)
{
    mCurrentAln = 90;
    mImageSpread = 0;
    bCheckFinisehd = false;
    mImagePath = "";
    timer = new QTimer ();
    connect (timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));
}

void CheckWidget::start () {
    timer->start (20);
}

void CheckWidget::stop () {
    if (timer->isActive ()) {
        timer->stop ();
    }
    bCheckFinisehd = true;
    mImageSpread = 1.0;
    update ();
}

void CheckWidget::setImageSpraed (float s) {
    mImageSpread = s;
    update ();
}

void CheckWidget::onTimerOut() {
    if (mImageSpread < 1) {
        mImageSpread += 0.01;
    } else {
        mImageSpread = 1;
    }
    if (mCurrentAln - 10 > 0) {
        mCurrentAln -= 10;
    } else {
        mCurrentAln = 360;
    }

    update ();
}

void CheckWidget::paintEvent (QPaintEvent *event) {
    QWidget::paintEvent (event);
    QPainter painter(this);
    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);

    if (!bCheckFinisehd) {
        QConicalGradient conicalGradient(width()/2, height()/2, mCurrentAln);
        conicalGradient.setColorAt(0, QColor(0x21, 0xc6, 0x50, 0xFF));
        conicalGradient.setColorAt(0.3, QColor(0x21, 0xc6, 0x50, 0x3F));
        conicalGradient.setColorAt(0.5, QColor(0x21, 0xc6, 0x50, 0x0F));
        conicalGradient.setColorAt(1.0, QColor(0, 0, 0, 0));

        painter.save ();
        painter.setPen (QPen(QBrush(conicalGradient), 2));
        painter.drawEllipse (2, 2, width ()-4, height ()-4);
        painter.restore ();

        QConicalGradient conicalGradient2(width()/2, height()/2, mCurrentAln+180);
        conicalGradient2.setColorAt(0, QColor(0x21, 0xc6, 0x50, 0xFF));
        conicalGradient2.setColorAt(0.3, QColor(0x21, 0xc6, 0x50, 0x3F));
        conicalGradient2.setColorAt(0.5, QColor(0x21, 0xc6, 0x50, 0x0F));
        conicalGradient2.setColorAt(1.0, QColor(0, 0, 0, 0));

        painter.save ();
        painter.setPen (QPen(QBrush(conicalGradient2), 2));
        painter.drawEllipse (2, 2, width ()-4, height ()-4);
        painter.restore ();
    }

    //
    if (mImagePath.length () > 0) {
        QImage image(mImagePath);
        QSize size (image.width ()*mImageSpread, image.height ()*mImageSpread);
        painter.drawImage (QRect((width ()-4-size.width ())/2,
                                 (height ()-4-size.height ())/2,
                                 size.width (), size.height ()),
                           QImage(mImagePath));
    }
}

void CheckWidget::setIcon (QString icon) {
    mImagePath = icon;
    update ();
}
