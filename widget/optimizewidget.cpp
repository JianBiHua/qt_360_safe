#include "optimizewidget.h"
#include "ui_optimizewidget.h"

OptimizeWidget::OptimizeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptimizeWidget)
{
    ui->setupUi(this);

    //
    ui->background->setStyleSheet ("background-color: #FFFFFF;");
    //
    ui->pushButton->setStyleSheet ("background-color: #16da6c;border-radius: 30px;color: #FFFFFF;font-size: 25px;");
    ui->title->setStyleSheet ("color: #444444;font-size: 25px;");
    ui->subtitle->setStyleSheet ("color: #9b9999;font-size: 16px;");
    //
    ui->wallBallWidget->setProgress (1);
    ui->wallBallWidget->setWaveMode (WaveBallMode::noWaveMode);
    ui->wallBallWidget->showScores (false);
    ui->wallBallWidget->setIcon (":/horse/images/horse/icon_optimize.png", QSize(80, 80));

    optionToolButtons ();

    //
    optimize2Widget = new Optimize2Widget(this);
    optimize2Widget->setVisible (false);
    connect (optimize2Widget, SIGNAL(onOptimize2IntoNextSignal()), this, SLOT(onOptimize2IntoNextSlot()));
}

OptimizeWidget::~OptimizeWidget()
{
    delete ui;
}

void OptimizeWidget::on_pushButton_clicked()
{
    optimize2Widget->setVisible (true);
    ui->home->setVisible (false);
}

void OptimizeWidget::onOptimize2IntoNextSlot () {
    optimize2Widget->setVisible (false);
    ui->home->setVisible (true);
}

void OptimizeWidget::optionToolButtons () {

    //
    optionToolButton (ui->tb1,
                      QIcon(":/horse/images/horse/icon_quanpansaomiao.png"),
                      "单项加速",
                      QSize(34, 32),
                      "horsewidget_toolbutton_1") ;

    optionToolButton (ui->tb2,
                      QIcon(":/horse/images/horse/icon_xinrenqu.png"),
                      "启动项",
                      QSize(32, 32),
                      "horsewidget_toolbutton_1") ;
    optionToolButton (ui->tb3,
                      QIcon(":/horse/images/horse/icon_xinrenqu.png"),
                      "忽略项",
                      QSize(32, 32),
                      "horsewidget_toolbutton_2") ;
    //
    optionToolButton (ui->tb4, QIcon(":/horse/images/horse/icon_icon_1.png"),
                      "开机时间",
                      QSize(32, 32),
                      "horsewidget_toolbutton_3") ;
    optionToolButton (ui->tb5, QIcon(":/horse/images/horse/icon_icon_2.png"),
                      "优化记录",
                      QSize(32, 32),
                      "horsewidget_toolbutton_3") ;
    optionToolButton (ui->tb6, QIcon(":/horse/images/horse/icon_icon_3.png"),
                      "小清新日历",
                      QSize(32, 32),
                      "horsewidget_toolbutton_3") ;
}

void OptimizeWidget::optionToolButton (QToolButton * tb,
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
