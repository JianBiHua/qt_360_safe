#include "horse2widget.h"
#include "ui_horse2widget.h"
#include <qDebug>
#include <QTime>

Horse2Widget::Horse2Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Horse2Widget)
{
    ui->setupUi(this);

    //
    //ui->background->setStyleSheet ("QWidget#background{background-color: rgba(255, 255, 255, 230);}");
    ui->bottom->setStyleSheet ("QWidget#bottom{background-color: #FFFFFF;}");
    ui->top->setStyleSheet ("QWidget#top{background-color: #f1f9f1;}");
    ui->pushButton->setStyleSheet ("background-color: transparent;border-radius: 16px;color: #4cb702;font-size: 15px;border: 1px solid #4cb702;");
    ui->title->setStyleSheet ("color: #444444;font-size: 25px;");
    ui->subtitle->setStyleSheet ("color: #9b9999;font-size: 16px;");
    //
    ui->waveBall->setWaveMode (WaveBallMode::noWaveMode);
    ui->waveBall->setProgress (1);
    ui->waveBall->showScores (false);
    ui->waveBall->setIcon (":/horse/images/horse/icon_horse.png", QSize(40, 40));
    ui->waveBall->startRound ();
    //

    //
    reset ();

    scanTimer = new QTimer;
    connect (scanTimer, SIGNAL(timeout()), this, SLOT(onScanTimerOut()));
}

void Horse2Widget::reset () {
    randTimerDis = 0;
    timerTick = 0;
    optionScanWidgets ();
    ui->progreBar->setProgress (0);
}

void Horse2Widget::start () {
    mScanIndex = 0;
    scanTimer->start (1000*1);

    ui->scan_1->setScanState (ScanState::scan);
    mCurrentScanWidget = ui->scan_1;
}

void Horse2Widget::stop () {
    scanTimer->stop ();
}

void Horse2Widget::onScanTimerOut() {
    timerTick++;
   ui->timer->setText (QString().sprintf("已用时: %02d:%02d:%02d", timerTick/3600, (timerTick%3600)/60, timerTick%60));

    if (randTimerDis > 0 ) {
        randTimerDis--;
        return ;
    }

    QTime t= QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    // 随机生成一个时间间隔
    randTimerDis = qrand()%5 + 2;

    mCurrentScanWidget->setScanState (ScanState::finished);
    if (mScanIndex == 0) {
        mCurrentScanWidget = ui->scan_2;
    } else if (mScanIndex == 1) {
        mCurrentScanWidget = ui->scan_3;
    } else if (mScanIndex == 2) {
        mCurrentScanWidget = ui->scan_4;
    } else if (mScanIndex == 3) {
       mCurrentScanWidget = ui->scan_5;
    } else if (mScanIndex == 4) {
        mCurrentScanWidget = ui->scan_6;
    } else if (mScanIndex == 5) {
        mCurrentScanWidget = ui->scan_7;
    } else if (mScanIndex == 6) {
        mCurrentScanWidget = ui->scan_8;
    } else if (mScanIndex == 7) {
        mCurrentScanWidget = ui->scan_9;
    } else if (mScanIndex == 8) {
        mCurrentScanWidget = ui->scan_10;
    } else {
        mCurrentScanWidget = NULL;
    }
    if (mCurrentScanWidget != NULL) {
        mCurrentScanWidget->setScanState (ScanState::scan);
    }

    mScanIndex++;

    //
    ui->progreBar->setProgress (mScanIndex*1.0/10);
    qDebug () << "mScanIndex: " << mScanIndex;

    // 扫描完成.
    if (mCurrentScanWidget == NULL) {
        stop ();
    }
}

Horse2Widget::~Horse2Widget()
{
    delete ui;
}

void Horse2Widget::on_pushButton_clicked()
{
    emit onHorse2IntoNextSignal();
}

void Horse2Widget::optionScanWidgets () {
   ui->scan_1->setTitle ("顽固木马");
   ui->scan_1->setIcon (":/other/images/other/icon_liulanqi.png");
   ui->scan_2->setTitle ("顽固木马");
   ui->scan_2->setIcon (":/other/images/other/icon_liulanqi.png");
   ui->scan_3->setTitle ("顽固木马");
   ui->scan_3->setIcon (":/other/images/other/icon_liulanqi.png");
   ui->scan_4->setTitle ("顽固木马");
   ui->scan_4->setIcon (":/other/images/other/icon_liulanqi.png");
   ui->scan_5->setTitle ("顽固木马");
   ui->scan_5->setIcon (":/other/images/other/icon_liulanqi.png");
   ui->scan_6->setTitle ("顽固木马");
   ui->scan_6->setIcon (":/other/images/other/icon_liulanqi.png");
   ui->scan_7->setTitle ("顽固木马");
   ui->scan_7->setIcon (":/other/images/other/icon_liulanqi.png");
   ui->scan_8->setTitle ("顽固木马");
   ui->scan_8->setIcon (":/other/images/other/icon_liulanqi.png");
   ui->scan_9->setTitle ("顽固木马");
   ui->scan_9->setIcon (":/other/images/other/icon_liulanqi.png");
   ui->scan_10->setTitle ("顽固木马");
   ui->scan_10->setIcon (":/other/images/other/icon_liulanqi.png");
}

void Horse2Widget::optionScanWidget(ScanWidget * widget) {

}
