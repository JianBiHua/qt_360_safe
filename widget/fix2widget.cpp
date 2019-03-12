#include "fix2widget.h"
#include "ui_fix2widget.h"

Fix2Widget::Fix2Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fix2Widget)
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
    ui->waveBall->setIcon (":/horse/images/horse/icon_fix.png", QSize(40, 40));
    ui->waveBall->startRound ();
    //
    ui->progreBar->setProgress (0.3);

    optionListWidget ();
}

Fix2Widget::~Fix2Widget()
{
    delete ui;
}

void Fix2Widget::on_pushButton_clicked()
{
    emit onFix2IntoNextSignal ();
}

void Fix2Widget::optionListWidget () {
    for (int i = 0; i < 4; i++ ) {
        QListWidgetItem *item = new QListWidgetItem;
        item->setSizeHint(QSize(900, 40));  //每次改变Item的高度

        QWidget * widget = new QWidget ;

        QWidget * icon = new QWidget (widget);
        icon->setGeometry (70, 10, 20, 20);

        QLabel * title = new QLabel (widget);
        title->setGeometry (100, 0, 80, 40);
        title->setAlignment (Qt::AlignCenter);
        title->setStyleSheet ("color: #000000; font-size:15px;");
        title->setText ("常规修复-");

        QLabel * subtitle = new QLabel (widget);
        subtitle->setGeometry (180, 0, 80, 40);
        subtitle->setAlignment (Qt::AlignCenter);
        subtitle->setStyleSheet ("color: #ababab; font-size:12px");
        subtitle->setText ("1223456789");

        ui->listWidget->addItem (item);
        ui->listWidget->setItemWidget(item, widget);
    }
}
