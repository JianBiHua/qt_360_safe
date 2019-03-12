#include "horsewidget.h"
#include "ui_horsewidget.h"

HorseWidget::HorseWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HorseWidget)
{
    ui->setupUi(this);

    //
    ui->background->setStyleSheet ("background-color: #FFFFFF;");
    //
    ui->pushButton->setStyleSheet ("background-color: #16da6c;border-radius: 30px;color: #FFFFFF;font-size: 25px;");
    ui->title->setStyleSheet ("color: #444444;font-size: 25px;");
    ui->subtitle->setStyleSheet ("color: #9b9999;font-size: 16px;");
    //
    ui->wallBallWidget->setProgress (0.1);
    ui->wallBallWidget->setWaveMode (WaveBallMode::noWaveMode);
    ui->wallBallWidget->showScores (false);
    ui->wallBallWidget->setIcon (":/horse/images/horse/icon_horse.png", QSize(80, 80));

    optionToolButtons ();
    optionPushButtons ();

    //
    horse2Widget = new Horse2Widget(this);
    horse2Widget->setVisible (false);
    connect (horse2Widget, SIGNAL(onHorse2IntoNextSignal()), this, SLOT(onHorse2IntoNextSlot()));
}

HorseWidget::~HorseWidget()
{
    delete ui;
}

void HorseWidget::optionPushButtons () {
    ui->pushButton_2->setStyleSheet ("border-image: url(:/horse/images/horse/icon_pb_bg_1.png)");
    ui->pushButton_3->setStyleSheet ("border-image: url(:/horse/images/horse/icon_pb_bg_2.png)");
    ui->pushButton_4->setStyleSheet ("border-image: url(:/horse/images/horse/icon_pb_bg_3.png)");
    ui->pushButton_5->setStyleSheet ("border-image: url(:/horse/images/horse/icon_pb_bg_4.png)");
    ui->pushButton_6->setStyleSheet ("border-image: url(:/horse/images/horse/icon_pb_bg_5.png)");
}

void HorseWidget::optionToolButtons () {

    //
    optionToolButton (ui->tbQuanpan,
                      QIcon(":/horse/images/horse/icon_quanpansaomiao.png"),
                      "全盘查杀",
                      QSize(34, 32),
                      "horsewidget_toolbutton_1") ;
    optionToolButton (ui->tbAnweizhi,
                      QIcon(":/horse/images/horse/icon_anweizhi.png"),
                      "按位置查杀",
                      QSize(34, 32),
                      "horsewidget_toolbutton_1") ;

    //
    optionToolButton (ui->tbXinrenqu,
                      QIcon(":/horse/images/horse/icon_xinrenqu.png"),
                      "信任区",
                      QSize(32, 32),
                      "horsewidget_toolbutton_2") ;
    optionToolButton (ui->tbHuifuqu, QIcon(":/horse/images/horse/icon_huifuqu.png"),
                      "恢复区",
                      QSize(32, 32),
                      "horsewidget_toolbutton_2") ;
    optionToolButton (ui->tbShangbanqu, QIcon(":/horse/images/horse/icon_shangbaoqu.png"),
                      "上报区", QSize(32, 32),
                      "horsewidget_toolbutton_2") ;

    //
    optionToolButton (ui->tbXitong, QIcon(":/horse/images/horse/icon_icon_1.png"),
                      "系统急救箱",
                      QSize(32, 32),
                      "horsewidget_toolbutton_3") ;
    optionToolButton (ui->tbShouji, QIcon(":/horse/images/horse/icon_icon_2.png"),
                      "手机急救箱",
                      QSize(32, 32),
                      "horsewidget_toolbutton_3") ;
    optionToolButton (ui->tbWinPE, QIcon(":/horse/images/horse/icon_icon_3.png"),
                      "WinPE版",
                      QSize(32, 32),
                      "horsewidget_toolbutton_3") ;
}

void HorseWidget::optionToolButton (QToolButton * tb,
                                    QIcon icon,
                                    QString text,
                                    QSize size,
                                    QString property) {
    QAction *pAction = new QAction(this);
    pAction->setText(text);
    pAction->setIcon(icon);
    tb->setIconSize(size);
    tb->setDefaultAction(pAction);
    tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tb->setProperty (property.toLatin1().data(), true);
}


void HorseWidget::on_pushButton_clicked()
{
    horse2Widget->setVisible (true);
    ui->main->setVisible (false);

    // 开始扫描
    horse2Widget->reset ();
    horse2Widget->start ();
}

void HorseWidget::onHorse2IntoNextSlot () {
    horse2Widget->setVisible (false);
    ui->main->setVisible (true);

    //
    horse2Widget->stop ();
}

void HorseWidget::on_tbQuanpan_clicked()
{
    horse2Widget->setVisible (true);
    ui->main->setVisible (false);

    horse2Widget->reset ();
    horse2Widget->start ();
}

void HorseWidget::on_pushButton_2_clicked()
{

}
