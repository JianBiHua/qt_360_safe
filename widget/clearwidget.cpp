#include "clearwidget.h"
#include "ui_clearwidget.h"
#include <qdebug.h>

ClearWidget::ClearWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClearWidget)
{
    ui->setupUi(this);

    clearMenuWidget = NULL;

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
    ui->wallBallWidget->setIcon (":/horse/images/horse/icon_clear.png", QSize(80, 80));

    optionToolButtons ();


    clear2Widget = new Clear2Widget(this);
    clear2Widget->setVisible (false);
    connect (clear2Widget, SIGNAL(onClear2IntoNextSignal()), this, SLOT(onClear2IntoNextSlot()));
}

ClearWidget::~ClearWidget()
{
    delete ui;
}

void ClearWidget::on_pushButton_clicked()
{
    clear2Widget->setVisible (true);
    ui->home->setVisible (false);
}

void ClearWidget::onClear2IntoNextSlot () {
    clear2Widget->setVisible (false);
    ui->home->setVisible (true);
}

void ClearWidget::optionToolButtons () {

    //
    optionToolButton (ui->tb1,
                      QIcon(":/horse/images/horse/icon_quanpansaomiao.png"),
                      "单项清理",
                      QSize(34, 32),
                      "horsewidget_toolbutton_1") ;
    connect (ui->tb1, SIGNAL(onHoverToolButtonHoverSinal(HoverToolButton*)), this, SLOT(onHoverToolButtonHoverSlot(HoverToolButton*)));
    connect (ui->tb1, SIGNAL(onHoverToolButtonNoHoverSinal(HoverToolButton*)), this, SLOT(onHoverToolButtonNoHoverSlot(HoverToolButton*)));


    optionToolButton (ui->tb2,
                      QIcon(":/horse/images/horse/icon_xinrenqu.png"),
                      "自动清理",
                      QSize(34, 32),
                      "horsewidget_toolbutton_1") ;
    optionToolButton (ui->tb3,
                      QIcon(":/horse/images/horse/icon_xinrenqu.png"),
                      "恢复区",
                      QSize(32, 32),
                      "horsewidget_toolbutton_2") ;
    optionToolButton (ui->tb4, QIcon(":/horse/images/horse/icon_huifuqu.png"),
                      "维修模式",
                      QSize(32, 32),
                      "horsewidget_toolbutton_2") ;
    optionToolButton (ui->tb5, QIcon(":/horse/images/horse/icon_shangbaoqu.png"),
                      "上经典版清理", QSize(32, 32),
                      "horsewidget_toolbutton_2") ;

    //
    optionToolButton (ui->tb6, QIcon(":/horse/images/horse/icon_icon_1.png"),
                      "微信清理",
                      QSize(32, 32),
                      "horsewidget_toolbutton_3") ;
    optionToolButton (ui->tb7, QIcon(":/horse/images/horse/icon_icon_2.png"),
                      "系统盘瘦身",
                      QSize(32, 32),
                      "horsewidget_toolbutton_3") ;
    optionToolButton (ui->tb8, QIcon(":/horse/images/horse/icon_icon_3.png"),
                      "查找大文件",
                      QSize(32, 32),
                      "horsewidget_toolbutton_3") ;
}

void ClearWidget::optionToolButton (QToolButton * tb,
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

void ClearWidget::showClearMenuWidget () {
    if (clearMenuWidget == NULL) {
        clearMenuWidget = new PopupWidget (this);
        clearMenuWidget->setArrow (PopupArrowDirection::LEFT, QRect(0, 70, 10, 10));
        clearMenuWidget->setGeometry (630, 150, 130, 220);
        connect (clearMenuWidget, SIGNAL(onMouseEnterPopupWidget(PopupWidget*)), this,
                 SLOT(onMouseEnterPopupWidgetSlot(PopupWidget*)));
        connect (clearMenuWidget, SIGNAL(onMouseLeavePopupWidget(PopupWidget*)), this,
                 SLOT(onMouseLeavePopupWidgetSlot(PopupWidget*)));
        clearMenuWidget->setWindowFlags (Qt::WindowStaysOnTopHint);
        //
        clearMenuWidget->addWidget (new ClearMenuWidget);
    }

    if (!clearMenuWidget->isVisible ()) {
        clearMenuWidget->setVisible (true);
    }
}

void ClearWidget::hideClearMenuWidget () {
    if (clearMenuWidget != NULL && clearMenuWidget->isVisible ()) {
        clearMenuWidget->setVisible (false);
    }
}


void ClearWidget::onHoverToolButtonHoverSlot(HoverToolButton*pb) {
    qDebug() << "onHoverToolButtonHoverSlot";
    showClearMenuWidget ();
}

void ClearWidget::onHoverToolButtonNoHoverSlot(HoverToolButton*pb) {
    if (!clearMenuWidget->rect ().contains (clearMenuWidget->mapFromGlobal (QCursor::pos())) &&
            !ui->tb1->rect ().contains (ui->tb1->mapFromGlobal (QCursor::pos()))) {
       hideClearMenuWidget ();
    }
}

void ClearWidget::onMouseEnterPopupWidgetSlot(PopupWidget* widget) {
    showClearMenuWidget ();
}

void ClearWidget::onMouseLeavePopupWidgetSlot(PopupWidget* widget) {
    if (!clearMenuWidget->rect ().contains (clearMenuWidget->mapFromGlobal (QCursor::pos())) &&
            !ui->tb1->rect ().contains (ui->tb1->mapFromGlobal (QCursor::pos()))) {
       hideClearMenuWidget ();
    }
}
