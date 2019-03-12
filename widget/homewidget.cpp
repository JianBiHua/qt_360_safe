#include "homewidget.h"
#include "ui_homewidget.h"


HomeWidget::HomeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeWidget)
{
    ui->setupUi(this);

    //
    ui->background->setStyleSheet ("background-color: #FFFFFF;");
    //
    ui->pushButton->setStyleSheet ("background-color: #16da6c;border-radius: 30px;color: #FFFFFF;font-size: 25px;");
    ui->title->setStyleSheet ("color: #444444;font-size: 25px;");
    ui->subtitle->setStyleSheet ("color: #9b9999;font-size: 16px;");
    //
    ui->wallBallWidget->setProgress (0.3);

    optionToolButtons ();
    optionStateWidgets ();

    //
    home2Widget = new Home2Widget(this);
    home2Widget->setVisible (false);
    connect (home2Widget, SIGNAL(onHome2IntoNextSignal()), this, SLOT(onHome2IntoNextSlot()));
}

HomeWidget::~HomeWidget()
{
    delete ui;
}

void HomeWidget::optionStateWidgets () {
    ui->fangHuZhongXin->show (":/other/images/other/icon_fanghuzhongxin.png", "防护中心", 1);
    ui->wangGouXianPei->show (":/other/images/other/icon_wanggou.png", "网购先陪", 1);
    ui->fanLeSuo->show (":/other/images/other/icon_fanlesuo.png", "反勒索服务", 0);

    //
    connect (ui->fangHuZhongXin, SIGNAL(onStateWidgetHoverSinal(StateWidget*)),
             this, SLOT(onStateWidgetHoverSlot(StateWidget*)));
    connect (ui->fangHuZhongXin, SIGNAL(onStateWidgetNoHoverSinal(StateWidget*)),
             this, SLOT(onStateWidgetNoHoverSlot(StateWidget*)));
    connect (ui->wangGouXianPei, SIGNAL(onStateWidgetHoverSinal(StateWidget*)),
             this, SLOT(onStateWidgetHoverSlot(StateWidget*)));
    connect (ui->wangGouXianPei, SIGNAL(onStateWidgetNoHoverSinal(StateWidget*)),
             this, SLOT(onStateWidgetNoHoverSlot(StateWidget*)));
    connect (ui->fanLeSuo, SIGNAL(onStateWidgetHoverSinal(StateWidget*)),
             this, SLOT(onStateWidgetHoverSlot(StateWidget*)));
    connect (ui->fanLeSuo, SIGNAL(onStateWidgetNoHoverSinal(StateWidget*)),
             this, SLOT(onStateWidgetNoHoverSlot(StateWidget*)));
}

void HomeWidget::optionToolButtons () {
    optionToolButton (ui->tbApp, QIcon(":/other/images/other/icon_app.png"), "软件管理");
    optionToolButton (ui->tbFix, QIcon(":/other/images/other/icon_fix.png"), "主页修复");
    optionToolButton (ui->tbHandler, QIcon(":/other/images/other/icon_handler.png"), "手机助手");
    optionToolButton (ui->tbMore, QIcon(":/other/images/other/icon_more.png"), "更多功能");
    optionToolButton (ui->tbService, QIcon(":/other/images/other/icon_help.png"), "人工服务");
}

void HomeWidget::optionToolButton (QToolButton * tb, QIcon icon, QString text) {
    QAction *pAction = new QAction(this);
    pAction->setText(text);
    pAction->setIcon(icon);
    tb->setIconSize(QSize(42, 42));
    tb->setDefaultAction(pAction);
    tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tb->setProperty ("homewidget_toolbutton", true);
}

void HomeWidget::onStateWidgetHoverSlot(StateWidget*s) {

}

void HomeWidget::onStateWidgetNoHoverSlot(StateWidget*s) {

}

void HomeWidget::on_pushButton_clicked()
{
    home2Widget->setVisible (true);
    ui->home->setVisible (false);
    home2Widget->start ();
}

void HomeWidget::onHome2IntoNextSlot() {
    home2Widget->setVisible (false);
    ui->home->setVisible (true);
    home2Widget->stop ();
}
