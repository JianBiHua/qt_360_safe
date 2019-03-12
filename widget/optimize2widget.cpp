#include "optimize2widget.h"
#include "ui_optimize2widget.h"

Optimize2Widget::Optimize2Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Optimize2Widget)
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
    ui->waveBall->setIcon (":/horse/images/horse/icon_optimize.png", QSize(40, 40));
    ui->waveBall->startRound ();
    //
    ui->progreBar->setProgress (0.3);
}

Optimize2Widget::~Optimize2Widget()
{
    delete ui;
}

void Optimize2Widget::on_pushButton_clicked()
{
    emit onOptimize2IntoNextSignal ();
}
