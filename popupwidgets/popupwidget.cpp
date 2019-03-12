#include "popupwidget.h"
#include <QPainter>
#include <QVBoxLayout>
#include <qdebug.h>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
#include <QGraphicsOpacityEffect>

PopupWidget::PopupWidget(QWidget *parent) : QWidget(parent)
{
    mArrowRect = QRect(30, 30, 7, 14);
    // 没有剪头
    mArrowDirection = PopupArrowDirection::LEFT;
    //
    mOldRect = rect ();
    qDebug () << "mOldRect: " << mOldRect;
}

void PopupWidget::setGeometry (const QRect & rect) {
    QWidget::setGeometry (rect);

    mOldRect = this->rect ();
}

void PopupWidget::setGeometry (int x, int y, int w, int h) {
    QWidget::setGeometry ( x, y, w, h);

     mOldRect = this->rect ();
}

// 四遍缩进两个像素,
void PopupWidget::paintEvent (QPaintEvent *event) {
    int indentation = 2;
    QWidget::paintEvent (event);

    QPainter painter(this);
    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush (QBrush(QColor(0xFF, 0xFF, 0xFF)));
    painter.setPen (QPen(QColor(0xde, 0xde, 0xde), 1));
//    painter.setPen (QPen(QColor(0xFF, 0x00, 0x00), 3));

    QPainterPath path;
    float scale = 0;

    switch (mArrowDirection) {
    case PopupArrowDirection::UP:

        scale = rect ().width ()*1.0/mOldRect.width ();

        path.moveTo (indentation, mArrowRect.height ());
        path.lineTo (mArrowRect.x ()*scale-mArrowRect.width ()/2, mArrowRect.height ());
        path.lineTo (mArrowRect.x ()*scale, indentation);
        path.lineTo (mArrowRect.x ()*scale+mArrowRect.width ()/2, mArrowRect.height ());
        path.lineTo (width ()-indentation*2, mArrowRect.height ());
        path.lineTo (width ()-indentation*2, height ()-indentation*2);
        path.lineTo (indentation, height ()-indentation*2);
        path.lineTo (indentation, mArrowRect.height ());

        break;
    case PopupArrowDirection::RIGHT:

        scale = rect ().height ()*1.0/mOldRect.height ();

        path.moveTo (indentation, indentation);
        path.lineTo (width ()-indentation*2-mArrowRect.width (), indentation);
        path.lineTo (width ()-indentation*2-mArrowRect.width (), mArrowRect.y ()*scale-mArrowRect.height ()/2);
        path.lineTo (width ()-indentation*2, mArrowRect.y ()*scale);
        path.lineTo (width ()-indentation*2-mArrowRect.width (), mArrowRect.y ()*scale+mArrowRect.height ()/2);
        path.lineTo (width ()-indentation*2-mArrowRect.width (), height ()-indentation*2);
        path.lineTo (indentation, height ()-indentation*2);
        path.lineTo (indentation, indentation);

        break;
    case PopupArrowDirection::DOWN:

        path.moveTo (indentation, indentation);
        path.lineTo (width ()-indentation*2, indentation);
        path.lineTo (width ()-indentation*2, height ()-indentation*2-mArrowRect.height ());
        path.lineTo (mArrowRect.x ()*scale+mArrowRect.width ()/2, height ()-indentation*2-mArrowRect.height ());
        path.lineTo (mArrowRect.x ()*scale, height ());
        path.lineTo (mArrowRect.x ()*scale-mArrowRect.width ()/2, height ()-indentation*2-mArrowRect.height ());
        path.lineTo (indentation, height ()-indentation*2-mArrowRect.height ());
        path.lineTo (indentation, indentation);

        break;
    case PopupArrowDirection::LEFT:

        path.moveTo (mArrowRect.width (), indentation);
        path.lineTo (width ()-indentation*2, indentation);
        path.lineTo (width ()-indentation*2, height ()-indentation*2);
        path.lineTo (mArrowRect.width (), height ()-indentation*2);
        path.lineTo (mArrowRect.width (), mArrowRect.y ()*scale+mArrowRect.height ()/2);
        path.lineTo (indentation, mArrowRect.y ()*scale);
        path.lineTo (mArrowRect.width (), mArrowRect.y ()*scale-mArrowRect.height ()/2);
        path.lineTo (mArrowRect.width (), indentation);

        break;
    default:
        break;
    }

    painter.drawPath (path);

    // 添加阴影
}

//
void PopupWidget::setArrow (PopupArrowDirection type, QRect rect) {
    mArrowDirection = type;
    mArrowRect = rect;

    //
    update ();
}

void PopupWidget::addWidget (QWidget * widget) {
    //
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(widget);
    switch (mArrowDirection) {
    case PopupArrowDirection::UP:
        layout->setGeometry (QRect(3, 3+mArrowRect.height (), width ()-6, height ()-6-mArrowRect.height ()));
        break;
    case PopupArrowDirection::RIGHT:
        layout->setGeometry (QRect(3, 3, width ()-6-mArrowRect.width (), height ()-6));
        break;
    case PopupArrowDirection::DOWN:
        layout->setGeometry (QRect(3, 3, width ()-6, height ()-6-mArrowRect.height ()));
        break;
    case PopupArrowDirection::LEFT:
        layout->setGeometry (QRect(3+mArrowRect.width (), 3, width ()-6-mArrowRect.width (), height ()-6));
        break;
    }
}

void PopupWidget::enterEvent(QEvent *event) {
    qDebug () << "enterEvent";

//    setHidden (false);
    emit onMouseEnterPopupWidget (this);

 //   QWidget::enterEvent (event);
}

void PopupWidget::leaveEvent(QEvent * event) {
    //
 qDebug () << "leaveEvent";
    emit onMouseLeavePopupWidget (this);
   // setVisible (false);
 //QWidget::leaveEvent (event);
// setHidden (true);
}

//bool first = false;
void PopupWidget::setVisible (bool visible) {
     QWidget::setVisible (visible);


//    QSequentialAnimationGroup group;
//    //QParallelAnimationGroup group;
//    group.addAnimation(anim1);
//    group.addAnimation(anim2);
//    group.start();

     // 自定义属性, 改变透明度.
     //http://blog.csdn.net/liang19890820/article/details/51882026
     //http://codego.net/208541/

    // "geometry"
    // "pos"
    QPropertyAnimation *geometryAnimation = new QPropertyAnimation(this, "geometry");
    geometryAnimation->setDuration(500);

    if (visible) {
        switch (mArrowDirection) {
        case PopupArrowDirection::UP:
            geometryAnimation->setStartValue(QRect(x ()+mArrowRect.x (), y (), mArrowRect.width (), height ()));
            break;
        case PopupArrowDirection::RIGHT:
            geometryAnimation->setStartValue(QRect(x (), y ()+mArrowRect.y (), width (), mArrowRect.height ()));
            break;
        case PopupArrowDirection::DOWN:
            geometryAnimation->setStartValue(QRect(x ()+mArrowRect.x (), y (), mArrowRect.width (), height ()));
            break;
        case PopupArrowDirection::LEFT:
            geometryAnimation->setStartValue(QRect(x (), y ()+mArrowRect.y (), width (), mArrowRect.height ()));
            break;
        }

        geometryAnimation->setEndValue(QRect(x (), y (), width (), height ()));
//    } else {
//        geometryAnimation->setStartValue(QRect(x (), y (), width (), height ()));

//        switch (mArrowDirection) {
//        case PopupArrowDirection::UP:
//            geometryAnimation->setEndValue(QRect(x ()+mArrowRect.x (), y (), 0, height ()));
//            break;
//        case PopupArrowDirection::RIGHT:
//            geometryAnimation->setEndValue(QRect(x (), y ()+mArrowRect.y (), width (), 0));
//            break;
//        case PopupArrowDirection::DOWN:
//            geometryAnimation->setEndValue(QRect(x ()+mArrowRect.x (), y (), 0, width ()));
//            break;
//        case PopupArrowDirection::LEFT:
//            geometryAnimation->setEndValue(QRect(x (), y ()+mArrowRect.y (), width (), 0));
//            break;
//        }
//    }

    geometryAnimation->setEasingCurve(QEasingCurve::OutBounce);
    connect (geometryAnimation, SIGNAL(valueChanged(QVariant)), this, SLOT(onGeometryAnimationValueChanged(QVariant)));
    //geometryAnimation->start ();

    QPropertyAnimation *alphaAnimation = new QPropertyAnimation();
    alphaAnimation->setTargetObject(this);
    alphaAnimation->setPropertyName("alpha");
    alphaAnimation->setDuration(500);
    alphaAnimation->setKeyValueAt(0, 0);
    alphaAnimation->setKeyValueAt(1, 255);

    // 改变窗体透明度, 似乎没效果., 可能改变不了QWidget,只能改QWindowWidget
        QPropertyAnimation *pAnimation = new QPropertyAnimation(this, "windowOpacity");
        pAnimation->setDuration(500);
        pAnimation->setKeyValueAt(0, 0);
        pAnimation->setKeyValueAt(1, 1);
//        pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
//    pAnimation->setLoopCount(-1);  //永远运行，直到stop

    // 同时修改颜色和透明度
    // 串行动画 QSequentialAnimationGroup group;
    // 并行动画
    QParallelAnimationGroup * group = new QParallelAnimationGroup(this);
    group->addAnimation(geometryAnimation);
    group->addAnimation(alphaAnimation);
    group->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

void PopupWidget::onGeometryAnimationValueChanged(QVariant v) {
   // mCurrentRect = v.toRect ();
    update ();
}

int PopupWidget::alpha() const
{
    return mAlpha;
}

void PopupWidget::setAlpha(const int alpha)
{
    // 修改控件透明度
    QGraphicsOpacityEffect * opacityEffect=new QGraphicsOpacityEffect;
    opacityEffect->setOpacity (alpha*1.0/255);
    this->setGraphicsEffect(opacityEffect);
}



//void PopupWidget::onShakeWindow()
//{
//    QPropertyAnimation *pAnimation = new QPropertyAnimation(this, "pos");
//    pAnimation->setDuration(500);
//    pAnimation->setLoopCount(2);
//    pAnimation->setKeyValueAt(0, QPoint(geometry().x() - 3, geometry().y() - 3));
//    pAnimation->setKeyValueAt(0.1, QPoint(geometry().x() + 6, geometry().y() + 6));
//    pAnimation->setKeyValueAt(0.2, QPoint(geometry().x() - 6, geometry().y() + 6));
//    pAnimation->setKeyValueAt(0.3, QPoint(geometry().x() + 6, geometry().y() - 6));
//    pAnimation->setKeyValueAt(0.4, QPoint(geometry().x() - 6, geometry().y() - 6));
//    pAnimation->setKeyValueAt(0.5, QPoint(geometry().x() + 6, geometry().y() + 6));
//    pAnimation->setKeyValueAt(0.6, QPoint(geometry().x() - 6, geometry().y() + 6));
//    pAnimation->setKeyValueAt(0.7, QPoint(geometry().x() + 6, geometry().y() - 6));
//    pAnimation->setKeyValueAt(0.8, QPoint(geometry().x() - 6, geometry().y() - 6));
//    pAnimation->setKeyValueAt(0.9, QPoint(geometry().x() + 6, geometry().y() + 6));
//    pAnimation->setKeyValueAt(1, QPoint(geometry().x() - 3, geometry().y() - 3));
//    pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
//}

//void PopupWidget::onDropWindow()
//{
//    QPropertyAnimation *pAnimation = new QPropertyAnimation(this, "geometry");

//    QDesktopWidget *pDesktopWidget = QApplication::desktop();
//    int x = (pDesktopWidget->availableGeometry().width() - width()) / 2;
//    int y = (pDesktopWidget->availableGeometry().height() - height()) / 2;

//    pAnimation->setDuration(1000);
//    pAnimation->setStartValue(QRect(x, 0, width(), height()));
//    pAnimation->setEndValue(QRect(x, y, width(), height()));
//    pAnimation->setEasingCurve(QEasingCurve::OutElastic);
//    pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
//}
