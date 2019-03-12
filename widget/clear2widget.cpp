#include "clear2widget.h"
#include "ui_clear2widget.h"

Clear2Widget::Clear2Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Clear2Widget)
{
    ui->setupUi(this);

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
    ui->waveBall->setIcon (":/horse/images/horse/icon_clear.png", QSize(40, 40));
    ui->waveBall->startRound ();
    //
    ui->progreBar->setProgress (0.3);
}

Clear2Widget::~Clear2Widget()
{
    delete ui;
}

void Clear2Widget::on_pushButton_clicked()
{
    emit onClear2IntoNextSignal ();
}
