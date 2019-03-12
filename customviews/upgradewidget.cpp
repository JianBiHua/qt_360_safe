#include "upgradewidget.h"
#include <QPainterPath>
#include <QPainter>
#include <QtCore/qmath.h>

UpgradeWidget::UpgradeWidget(QWidget *parent) : QWidget(parent)
{
    //
    mRadian = 90;
    mMode = UpgradeMode::scan;

    timer = new QTimer;
    connect (timer, SIGNAL(timeout()), this, SLOT(on_timer_out()));
    start ();
}

void UpgradeWidget::start () {
    timer->start (20);
}

void UpgradeWidget::stop () {

}

void UpgradeWidget::on_timer_out() {
    if (mRadian - 5 > 0) {
        mRadian -= 5;
    } else {
        mRadian = 360;
    }
    update ();
}

void UpgradeWidget::paintEvent (QPaintEvent *event) {
    QWidget::paintEvent (event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);


    painter.save ();

    //9389d7
    painter.setPen(QPen(Qt::transparent, 0));
    painter.setBrush (QColor(0x93, 0x89, 0xd7));
    painter.drawEllipse (2, 2, width ()-4, height ()-4);
    painter.restore ();

    painter.setPen(QPen(Qt::white, 4));
    // 外圈
    painter.drawEllipse (2, 2, width ()-4, height ()-4);

    painter.setPen(QPen(QColor(0xFF, 0xFF, 0xFF, 0x8F), 1));
    // 内圈3
    painter.drawEllipse (6, 6, width ()-12, height ()-12);

    int w = (width ())/5;
    // 内圈2
    painter.drawEllipse (w, w, width ()-w*2, height ()-w*2);
    // 内圈1
    painter.drawEllipse (w*2, w*2, width ()-w*4, height ()-w*4);
    // 显示十子线
    painter.drawLine (QPoint(0, height ()/2), QPoint(width (), height ()/2));
    painter.drawLine (QPoint(width ()/2, 0), QPoint(width ()/2, height ()));

    if (mMode == UpgradeMode::scan) {
        // 显示模式1
        drawScanMode ();
    } else if (mMode == UpgradeMode::download) {
        drawDownLoadMode ();
    } else if (mMode == UpgradeMode::finished){
        drawFinishedMode ();
    }
}

QPoint UpgradeWidget::getPoint (int arg, int w) {
    int x   =   width ()/2  +  w  *   qCos((360-arg)   *   3.14   /180   ) ;
    int y   =   height ()/2  +   w  *   qSin ((360-arg)   *   3.14   /180   ) ;
    return QPoint(x, y);
}

void UpgradeWidget::drawScanMode () {
    int w = (width ())/5;
    QPainter painter(this);

    QConicalGradient conicalGradient2(width()/2, height()/2, mRadian);
    conicalGradient2.setColorAt(0, QColor(0xFF, 0xFF, 0xFF, 0x7F));
    conicalGradient2.setColorAt(0.3, QColor(0xFF, 0xFF, 0xFF, 0x3F));
    conicalGradient2.setColorAt(0.7, QColor(0, 0, 0, 0));
    conicalGradient2.setColorAt(1.0, QColor(0, 0, 0, 0));

    painter.save();
    painter.setPen(QPen(QBrush(conicalGradient2), w));
    painter.drawEllipse(w/2+6, w/2+6, width ()-w-12, height ()-w-12);
    painter.restore();

    // 外面的圆
    painter.save();
    painter.setPen(QPen(QBrush(conicalGradient2), 10));
    painter.drawEllipse(w/2, w/2, width ()-w, height ()-w);
    painter.restore();

    // 最里面的圆
    painter.save();
    painter.setPen(QPen(Qt::white, 5));
    painter.drawEllipse(width ()/2-6, width ()/2-6, 12, 12);
    painter.restore ();

    // 画线
    painter.setPen(QPen(Qt::white, 3));
    painter.drawLine (getPoint (mRadian, 6),
                      getPoint (mRadian, height ()/2-8));
}

void UpgradeWidget::drawDownLoadMode () {

}

void UpgradeWidget::drawFinishedMode () {
    //
    QPainter painter(this);


}
