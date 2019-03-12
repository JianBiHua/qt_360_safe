#include "scanwidget.h"
#include "ui_scanwidget.h"
#include <qdebug.h>
#include <QBitmap>
#include <qpixmap.h>
#include <QPainter>

ScanCT::ScanCT(QWidget *parent) :
    QWidget(parent)
{
    mSleepTimes = 0;
    bToLeft = false;
    mRex = -15;
    timer = new QTimer;
    connect (timer, SIGNAL(timeout()), this, SLOT(onTimerOver()));
}

void ScanCT::onTimerOver() {
    if (mSleepTimes > 0) {
        mSleepTimes--;
        return ;
    }
    if (bToLeft) {
        if (mRex - 1 > -15) {
            mRex-=1;
        } else {
            bToLeft = false;
            mSleepTimes = 20;
        }
    } else {
        if (mRex + 1 < width ()) {
            mRex += 1;
        } else {
            bToLeft = true;
        }
    }

    update ();
}

void ScanCT::paintEvent (QPaintEvent *event) {
    QWidget::paintEvent (event);
    if (mSleepTimes > 0) {
        return ;
    }

    QRect rect(mRex, 0, 15, height ());
    QLinearGradient linear(QPointF(rect.x (), rect.height ()/2),
                           QPointF(rect.right (), rect.height ()/2));

    if (bToLeft) {
        linear.setColorAt(0, QColor(0x43, 0xaf, 0xff, 0xFF));
        linear.setColorAt (0.3, QColor(0x43, 0xaf, 0xff, 0x9F));
        linear.setColorAt(1, QColor(0, 0, 0, 0));
    } else {
        linear.setColorAt(1, QColor(0x43, 0xaf, 0xff, 0xFF));
        linear.setColorAt (0.3, QColor(0x43, 0xaf, 0xff, 0x9F));
        linear.setColorAt(0, QColor(0, 0, 0, 0));
    }

    //
    QPainter painter(this);
    painter.setPen (Qt::transparent);
    painter.setBrush (linear);
    painter.drawRect (rect);
}

void ScanCT::start () {
    mSleepTimes = 0;
    timer->start (20);
}

void ScanCT::stop () {
    timer->stop ();
    mSleepTimes = 20;
    update ();
}

ScanWidget::ScanWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScanWidget)
{
    ui->setupUi(this);

    //
    mState = ScanState::waitScan;
    ui->subtitle->setText ("等待扫描");
    ui->subtitle->setAlignment (Qt::AlignCenter);
    ui->title->setAlignment (Qt::AlignCenter);
    ui->subtitle->setStyleSheet ("color: #ababab; font-size: 12px");
    ui->title->setStyleSheet ("color: #ababab; font-size: 14px");
}

ScanWidget::~ScanWidget()
{
    delete ui;
}

void ScanWidget::setScanState (ScanState state) {
    mState = state;

    update ();
}

void ScanWidget::setTitle (QString title) {
    ui->title->setText (title);
}

void ScanWidget::setIcon (QString icon){
        if (icon.length () == 0) {
            return ;
        }

    mIcon = icon;
    ui->icon->setStyleSheet ("background-color: #ababab");
    QPixmap pixmap(icon);
    QBitmap bitmap = pixmap.mask ();
    ui->icon->setMask(bitmap);
}

//灰ababab  蓝43afff 绿07c354
void ScanWidget::update () {
    QWidget::update ();

    //
    switch (mState) {
        case ScanState::waitScan:
        ui->icon->setStyleSheet ("background-color: #ababab");
        ui->subtitle->setStyleSheet ("color: #ababab");
        ui->subtitle->setText ("等待扫描");
        break;
    case ScanState::scan:
        ui->icon->setStyleSheet ("background-color: #43afff");
        ui->subtitle->setStyleSheet ("color: #43afff");
        ui->subtitle->setText ("正在扫描...");
        ui->scan->start ();
        break;
    case ScanState::finished:
        ui->scan->stop ();
        ui->icon->setStyleSheet ("background-color: #07c354");
        ui->subtitle->setStyleSheet ("color: #FFFFFF;background-color: #07c354;border-radius: 10px;");
        ui->subtitle->setText ("安全");
        break;
    }
}

