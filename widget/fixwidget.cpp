#include "fixwidget.h"
#include "ui_fixwidget.h"

FixWidget::FixWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FixWidget)
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
    ui->wallBallWidget->setIcon (":/horse/images/horse/icon_fix.png", QSize(80, 80));

    optionToolButtons ();

    fix2Widget = new Fix2Widget(this);
    fix2Widget->setVisible (false);
    connect (fix2Widget, SIGNAL(onFix2IntoNextSignal()), this, SLOT(onFix2IntoNextSlot()));
}

FixWidget::~FixWidget()
{
    delete ui;
}

void FixWidget::on_pushButton_clicked()
{
    fix2Widget->setVisible (true);
    ui->home->setVisible (false);
}

void FixWidget::onFix2IntoNextSlot() {
    fix2Widget->setVisible (false);
    ui->home->setVisible (true);
}

void FixWidget::optionToolButtons () {

    //
    optionToolButton (ui->tb1,
                      QIcon(":/horse/images/horse/icon_quanpansaomiao.png"),
                      "单项修补",
                      QSize(34, 32),
                      "horsewidget_toolbutton_1") ;

    optionToolButton (ui->tb2,
                      QIcon(":/horse/images/horse/icon_xinrenqu.png"),
                      "信任区",
                      QSize(32, 32),
                      "horsewidget_toolbutton_1") ;
    optionToolButton (ui->tb3,
                      QIcon(":/horse/images/horse/icon_xinrenqu.png"),
                      "恢复区",
                      QSize(32, 32),
                      "horsewidget_toolbutton_2") ;
    optionToolButton (ui->tb4, QIcon(":/horse/images/horse/icon_huifuqu.png"),
                      "补丁管理",
                      QSize(32, 32),
                      "horsewidget_toolbutton_2") ;
    optionToolButton (ui->tb5, QIcon(":/horse/images/horse/icon_shangbaoqu.png"),
                      "驱动管理", QSize(32, 32),
                      "horsewidget_toolbutton_2") ;

    //
    optionToolButton (ui->tb6, QIcon(":/horse/images/horse/icon_icon_1.png"),
                      "驱动大师",
                      QSize(32, 32),
                      "horsewidget_toolbutton_3") ;
    optionToolButton (ui->tb7, QIcon(":/horse/images/horse/icon_icon_2.png"),
                      "主页维护",
                      QSize(32, 32),
                      "horsewidget_toolbutton_3") ;
    optionToolButton (ui->tb8, QIcon(":/horse/images/horse/icon_icon_3.png"),
                      "主页修复",
                      QSize(32, 32),
                      "horsewidget_toolbutton_3") ;
}

void FixWidget::optionToolButton (QToolButton * tb,
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
