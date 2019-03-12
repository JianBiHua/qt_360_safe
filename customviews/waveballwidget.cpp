#include "waveballwidget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QtCore/qmath.h>
#include <qdebug.h>
#include <QTime>

WaveBallWidget::WaveBallWidget(QWidget *parent) :
    QWidget(parent) {

    // 保证正方形
    int w = size ().width ()>size ().height ()?size ().height ():size ().width ();
    resize (w, w);

    offset = 0;
    progress = 0.8;
    roundAlen = 135;
    //  默认显示外边框
    bShowRound = true;
    // 默认波形模式
    mWaveBallMode = WaveBallMode::waveMode;
    // 显示分数
    bScores = true;

    timer = new QTimer;
    connect (timer, SIGNAL(timeout()), this, SLOT(on_timer_out()));
    startWave ();

    roundTimer = new QTimer;
    connect (roundTimer, SIGNAL(timeout()), this, SLOT(on_roundTimer_out()));
    //startRound ();
}

WaveBallWidget::~WaveBallWidget()
{
}

void WaveBallWidget::setProgress (float p) {
    progress = p;
    if (progress > 1) {
        progress = 1;
    } else if (progress < 0) {
        progress = 0;
    }

    update ();
}

//
void WaveBallWidget::startWave () {
    timer->start (20);
}

void WaveBallWidget::stopWave () {
    timer->stop ();
}

void WaveBallWidget::on_timer_out() {
    if (offset > -width ()) {
        offset-= 3;
    } else {
        offset = 0;
    }
    update ();
}

//
void WaveBallWidget::startRound () {
    bShowBubble = true;
    roundTimer->start (20);
}

void WaveBallWidget::stopRound () {
    roundTimer->stop ();
    //
    bShowBubble = false;
    roundAlen = 135;
    // 清除气泡数组
    bubbles.clear ();
    update ();
}

void WaveBallWidget::on_roundTimer_out() {
    if (roundAlen -5 > 0) {
        roundAlen -= 5;
    } else {
        roundAlen = 360;
    }
    // 气泡运动
    for (int i = 0; i < bubbles.size (); i++) {
        Bubble * b = bubbles.at (i);
        if (waveMode == WaveBallMode::noWaveMode)  {
            if (b->point.y ()- b->speed > 20) {
               b->point.setY (b->point.y () - b->speed);
            } else {
                bubbles.remove (i);
                i--;
            }
        } else {
            if (b->point.y ()- b->speed > height ()*(1-progress)) {
               b->point.setY (b->point.y () - b->speed);
            } else {
                bubbles.remove (i);
                i--;
            }
        }
    }
    // 随机添加一个气泡
    if (bubbles.size () < 5) {
        bubbles.append (getRandBubble ());
    }
    update ();
}

//7cfb7c----64eaa0
// https://segmentfault.com/a/1190000000721127
void WaveBallWidget::paintEvent (QPaintEvent *event) {
    QWidget::paintEvent (event);

    if(mWaveBallMode == WaveBallMode::noWaveMode) {
        drawFullWaveBall ();
    } else {
        if (progress*0.9 >= 1) {
            drawFullWaveBall ();
        } else if (progress*0.9 > 0) {
            drawWaveBallBg ();
            drawWaveBall ();
        }
    }

    if (bShowRound) {
        drawRound ();
    }

    //
    if (bScores) {
        drawScores ();
    }

    // 显示气泡
    if (bShowBubble) {
        drawBubble ();
    }

    if (bShowImage) {
        drawImage ();
    }
}

QPoint WaveBallWidget::getPoint (int arg, int w) {
    int x   =   width ()/2  +  w  *   qCos((360-arg)   *   3.14   /180   ) ;
    int y   =   height ()/2  +   w  *   qSin ((360-arg)   *   3.14   /180   ) ;
    return QPoint(x, y);
}

void WaveBallWidget::drawFullWaveBall () {
    QPainter painter(this);

    painter.setPen(QPen(Qt::transparent, 0));//设置画笔形式
    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::transparent);//设置画笔形式
    painter.setBrush (getLinearGradient (false));
    painter.drawEllipse (QRect(6, 6, width ()-12, height ()-12));
}


void WaveBallWidget::drawWaveBallBg () {
    QPainter painter(this);
    QPainterPath mPath;

    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::transparent, 0));//设置画笔形式
    // 设置渐变色
    painter.setBrush (getLinearGradient (true));

    int u = height ()/2;
    int y = 2*u*(1-progress);

    // 波形球
    int waveH = 10;
    mPath.moveTo (offset+0, y);
    mPath.quadTo(offset+u/2, y+waveH, offset+u, y);
    mPath.quadTo(offset+u/2+u, y-waveH, offset+u+u, y);
    mPath.quadTo(offset+u/2+2*u, y+waveH, offset+u+2*u, y);
    mPath.quadTo(offset+u/2+u+2*u, y-waveH, offset+u+u+2*u, y);
    mPath.quadTo(offset+u/2+u+3*u, y+waveH, offset+u+u+3*u, y);
    mPath.lineTo (offset+u+u+3*u, 2*u);
    mPath.lineTo (0, 2*u);
    mPath.lineTo (0, 0);

    //mPath.arcTo (QRect(5, 5, width ()-10, height ()-10), 180-10, 180+20);
    QPainterPath mPath2;
    mPath2.addEllipse (QRect(6, 6, width ()-12, height ()-12));
    painter.setClipPath (mPath);
    painter.drawPath (mPath2);
}

void WaveBallWidget::drawWaveBall () {
    QPainter painter(this);
    QPainterPath mPath;
    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(QPen(Qt::transparent, 0));//设置画笔形式
    // 设置渐变色
    painter.setBrush (getLinearGradient (false));

    int u = height ()/2;
    int y = 2*u*(1-progress);

    // 波形球
    int waveH = 10;
    mPath.moveTo (offset+0, y);
    mPath.quadTo(offset+u/2, y-waveH, offset+u, y);
    mPath.quadTo(offset+u/2+u, y+waveH, offset+u+u, y);
    mPath.quadTo(offset+u/2+2*u, y-waveH, offset+u+2*u, y);
    mPath.quadTo(offset+u/2+u+2*u, y+waveH, offset+u+u+2*u, y);
    mPath.quadTo(offset+u/2+u+3*u, y-waveH, offset+u+u+3*u, y);
    mPath.lineTo (offset+u+u+3*u, 2*u);
    mPath.lineTo (0, 2*u);
    mPath.lineTo (0, 0);

    //mPath.arcTo (QRect(5, 5, width ()-10, height ()-10), 180-10, 180+20);
    QPainterPath mPath2;
    mPath2.addEllipse (QRect(6, 6, width ()-12, height ()-12));
    painter.setClipPath (mPath);
    painter.drawPath (mPath2);
}

void WaveBallWidget::drawRound () {
    // 外边的圆
    QPainter painter2(this);
    // 反走样
    painter2.setRenderHint(QPainter::Antialiasing, true);
    // 橙色: FFBE21
    // 绿色: 31EF1A
    painter2.setPen(QPen(getPenColor (), 2));//设置画笔形式
    painter2.drawArc (QRect(2, 2, size().width ()-4, size().height ()-4), roundAlen * 16, 315*16);

    painter2.setPen(Qt::transparent);//设置画笔形式
    painter2.setBrush (getPenColor ());
    painter2.drawEllipse (getPoint (roundAlen, (width ()-4)/2), 4, 4);
}

QColor WaveBallWidget::getPenColor () {
    if (progress < 0.3) {
        return QColor(0xff, 0x84, 0x38);
    } else if (progress < 0.6) {
        return QColor(0xff, 0xBE, 0x21);
    }

    return QColor(0x31, 0xef, 0x1a);
}

QLinearGradient WaveBallWidget::getLinearGradient (bool isBackColor) {
    QLinearGradient linear(QPointF(size().width ()/2, size().height ()), QPointF(size().width ()/2, 0));
    if (progress < 0.3) {
        // 红色 1 ff684e 0.3 ff7356  0 ff9e7c
        //橙色: 1 fb934d 0.8 ff8a40  0.3 ffae5c 0 ff3173
        linear.setColorAt(0, QColor(0xFF, 0x9E, 0x7c, isBackColor?0x7F:0xFF));
        linear.setColorAt (0.3, QColor(0xFF, 0x73, 0x56, isBackColor?0x7F:0xFF));
        linear.setColorAt(1, QColor(0xFF, 0x68, 0x4E, isBackColor?0x7F:0xFF));
    } else if (progress < 0.6) {
        // 红色 1 ff684e 0.3 ff7356  0 ff9e7c
        //橙色: 1 fb934d 0.8 ff8a40  0.3 ffae5c 0 ff3173
        linear.setColorAt(0, QColor(0xFF, 0xC1, 0x73, isBackColor?0x7F:0xFF));
        linear.setColorAt (0.2, QColor(0xFF, 0xAE, 0x5C, isBackColor?0x7F:0xFF));
        linear.setColorAt (0.8, QColor(0xFF, 0x8A, 0x40, isBackColor?0x7F:0xFF));
        linear.setColorAt(1, QColor(0xFB, 0x93, 0x4A, isBackColor?0x7F:0xFF));
    } else {
        // 红色 1 ff684e 0.3 ff7356  0 ff9e7c
        //橙色: 1 fb934d 0.8 ff8a40  0.3 ffae5c 0 ff3173
        linear.setColorAt(0, QColor(0x7c, 0xfb, 0x7c, isBackColor?0x7F:0xFF));
        linear.setColorAt (0.2, QColor(0x53, 0xe9, 0x6e, isBackColor?0x7F:0xFF));
        linear.setColorAt (0.8, QColor(0x35, 0xe3, 0x85, isBackColor?0x7F:0xFF));
        linear.setColorAt(1, QColor(0x72, 0xec, 0xa7, isBackColor?0x7F:0xFF));
    }

    return linear;
}

void WaveBallWidget::drawScores () {

       // 显示分数
      QFont font("宋体", width ()/3);//设置字体的类型，大小，加粗，斜体
      QPainter painter(this);
      painter.setFont(font);//添加字体
      painter.setPen(QColor(Qt::white));

      // 显示分
      QFont fontF("宋体", width ()/6);//设置字体的类型，大小，加粗，斜体
      QPainter painterF(this);
      painterF.setFont(fontF);//添加字体
      painterF.setPen(QColor(Qt::white));

      int max = height ()*(progress);

      QString scores = QString("%1").arg (progress*100);
      QFontMetrics fm = painter.fontMetrics();
      int w = fm.width (scores);
      int h = fm.ascent()+fm.descent ();
      QSize txtSize = QSize(w, h);
      QFontMetrics  fmF = painterF.fontMetrics();
      w = fmF.width ("分");
      h = fmF.ascent()+fmF.descent ();
      QSize fenSize = QSize(w, h);


      int left = (width ()-(txtSize.width () + fenSize.width ()))/2;
      int top;
      if (mWaveBallMode == WaveBallMode::waveMode) {
        top = max>txtSize.height ()?(height ()*(1-progress)+(max-txtSize.height ())/2):(height ()-txtSize.height ()-10);
      } else {
        top = (height ()-txtSize.height ())/2;
      }

      // 显示文字
      QRect rect = QRect (left,
                          top,
                          txtSize.width (),
                          txtSize.height ());
      painter.drawText(rect,Qt::AlignLeft, scores);
      QRect rectF = QRect (left+txtSize.width (),
                           top+(txtSize.height ()-fenSize.height ()-fm.descent ()),
                           fenSize.width (),
                           fenSize.height ());
      painterF.drawText(rectF,Qt::AlignLeft, "分");
}

void WaveBallWidget::drawBubble () {
    QPainter painter(this);
    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen (Qt::transparent);
    painter.setBrush (QColor (0xFF, 0xFF, 0xFF, 0x5F));

    // 显示气泡
    for (int i = 0; i < bubbles.size (); i++) {
        Bubble * b = bubbles.at (i);
        painter.drawEllipse (b->point.x (), b->point.y(), b->width, b->width);
    }
}

void WaveBallWidget::drawImage () {
    if (mImagePath.length () == 0) {
        return ;
    }

    //
    QPainter painter(this);
    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);
    //
    painter.drawImage (QRect((width ()-mImageSize.width ())/2,
                             (height ()-mImageSize.height ())/2,
                             mImageSize.width (), mImageSize.height ()), QImage(mImagePath));
}

Bubble*  WaveBallWidget::getRandBubble () {
    int bubbleWidth = 10;
    int unit = (bubbleWidth+4);
    // 一行最多显示的个数
    int maxRow = (height ()*2/3)/unit;
    int rx = (width ()*1/3)/2+unit/2;
    int ry = height ()*2/3+30;

    // 随机生产
    QTime t= QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    //
    QPoint point = QPoint (rx+(qrand()%maxRow)*unit, ry);
    // 最小速度为1
    float speed = qrand()%5 + (qrand()%10)*0.1+0.3;
    return new Bubble(this, point, bubbleWidth, speed);
}

// 显示边框圆
void WaveBallWidget::showRound (bool isShow) {
    bShowRound = isShow;
    if (!bShowRound) {
        stopRound ();
    }
    update ();
}

// 显示文字
void WaveBallWidget::showScores (bool s) {
    bScores = s;
    update ();
}

void WaveBallWidget::setWaveMode (WaveBallMode mode){
    mWaveBallMode = mode;
    update ();
}

void WaveBallWidget::setIcon (QString icon, QSize size) {
    bShowImage = true;
    mImagePath = icon;
    mImageSize = size;
}
