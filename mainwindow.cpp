#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QDesktopServices>
#include "dialog/questiondialog.h"
#include "dialog/aboutdialog.h"
#include "widget/homewidget.h"
#include "widget/home2widget.h"
#include "widget/horsewidget.h"
#include "widget/horse2widget.h"
#include "widget/clearwidget.h"
#include "widget/clear2widget.h"
#include "widget/fixwidget.h"
#include "widget/fix2widget.h"
#include "widget/optimizewidget.h"
#include "widget/optimize2widget.h"
#include "widget/fuctionswidget.h"
#include "dialog/market360dialog.h"
#include "dialog/upgradedialog.h"
#include "dialog/optiondialog.h"
#include "popupwidgets/dataconnectsetup.h"
#include <QCursor>
#include "widget/loginwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent, Qt::FramelessWindowHint),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loginPopupWidget = NULL;
    //
    ui->backgroundWidget->setStyleSheet ("background-color: #22CB64");
    //ui->mainWidget->setStyleSheet ("background-color: #EFF8F1");
    ui->title->setStyleSheet ("color: #FFFFFF");
    ui->icon->setStyleSheet ("border-image: url(:/other/images/other/icon.png)");
    ui->pbIcon->setStyleSheet ("border-image: url(:/other/images/other/icon_w.png)");
    ui->pb360->setStyleSheet ("color: #FFFFFF;;font-family: \"宋体\";font-size: 30px;");
    //ui->pb360->setStyleSheet ("border-image: url(:/other/images/other/icon_360.png);");
    ui->pbLogion->setStyleSheet ("color: #FFFFFF;font-family: \"微软雅黑\";font-size: 12px;");

    connect (ui->pb360, SIGNAL(onHoverPushButtonHoverSinal(HoverPushButton*)),
             this, SLOT(onHoverPushButtonHoverSlot(HoverPushButton*)));
    connect (ui->pbIcon, SIGNAL(onHoverPushButtonHoverSinal(HoverPushButton*)),
             this, SLOT(onHoverPushButtonHoverSlot(HoverPushButton*)));
    connect (ui->pbLogion, SIGNAL(onHoverPushButtonHoverSinal(HoverPushButton*)),
             this, SLOT(onHoverPushButtonHoverSlot(HoverPushButton*)));
    connect (ui->pb360, SIGNAL(onHoverPushButtonNoHoverSinal(HoverPushButton*)),
             this, SLOT(onHoverPushButtonNoHoverSlot(HoverPushButton*)));
    connect (ui->pbIcon, SIGNAL(onHoverPushButtonNoHoverSinal(HoverPushButton*)),
             this, SLOT(onHoverPushButtonNoHoverSlot(HoverPushButton*)));
    connect (ui->pbLogion, SIGNAL(onHoverPushButtonNoHoverSinal(HoverPushButton*)),
             this, SLOT(onHoverPushButtonNoHoverSlot(HoverPushButton*)));

    //
    optionTopBtns ();
    optionToolButtons ();
    createContextMenu ();
    showStackedWidget ();

    //
    setTabBarIndex (0) ;

    //
    setMouseTracking (true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_close_clicked()
{
    // 退出
    QCoreApplication::exit();
}

void MainWindow::optionTopBtns () {
    ui->close->setStyleSheet ("border-image: url(:/top/images/top/top_close.png);");
    ui->min->setStyleSheet ("border-image: url(:/top/images/top/top_min.png);");
    ui->menu->setStyleSheet ("border-image: url(:/top/images/top/top_menu.png);");
    ui->theme->setStyleSheet ("border-image: url(:/top/images/top/top_theme.png);");
}

void MainWindow::optionToolButton (QToolButton * tb, QIcon icon, QString text) {
    QAction *pAction = new QAction(this);
    pAction->setText(text);
    pAction->setIcon(icon);
    tb->setIconSize(QSize(50, 50));
    tb->setDefaultAction(pAction);
    tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tb->setProperty ("mainwindow_toolbutton", true);
}

void MainWindow::setTabBarIndex (int index) {
    char * key = "mainwindow_toolbutton_selected";
    ui->tbHome->setProperty (key, index==0?true:false);
    updateStyle (ui->tbHome) ;
    ui->tbHorse->setProperty (key, index==1?true:false);
    updateStyle (ui->tbHorse) ;
    ui->tbClear->setProperty (key, index==2?true:false);
    updateStyle (ui->tbClear) ;
    ui->tbFix->setProperty (key, index==3?true:false);
    updateStyle (ui->tbFix) ;
    ui->tbYouhua->setProperty (key, index==4?true:false);
    updateStyle (ui->tbYouhua) ;
    ui->tbActions->setProperty (key, index==5?true:false);
    updateStyle (ui->tbActions) ;
    ui->tbMarket->setProperty (key, index==6?true:false);
    updateStyle (ui->tbMarket) ;
    ui->tbApp->setProperty (key, index==7?true:false);
    updateStyle (ui->tbApp) ;
}

void MainWindow::updateStyle (QWidget * w) {
    w->style()->unpolish(w);
    w->style()->polish(w);
    w->update ();
}

void MainWindow::optionToolButtons () {
    optionToolButton (ui->tbHome, QIcon(":/tab/images/tab/tab_home.png"), "电脑体验");
    optionToolButton (ui->tbHorse, QIcon(":/tab/images/tab/tab_horse.png"), "木马查杀");
    optionToolButton (ui->tbClear, QIcon(":/tab/images/tab/tab_clear.png"), "电脑清理");
    optionToolButton (ui->tbFix, QIcon(":/tab/images/tab/tab_fix.png"), "系统修复");
    optionToolButton (ui->tbYouhua, QIcon(":/tab/images/tab/tab_optimize.png"), "优化加速");
    optionToolButton (ui->tbActions, QIcon(":/tab/images/tab/tab_actions.png"), "功能大全");
    optionToolButton (ui->tbMarket, QIcon(":/tab/images/tab/tab_market.png"), "360商城");
    optionToolButton (ui->tbApp, QIcon(":/tab/images/tab/tab_app.png"), "软件管家");
}

void MainWindow::on_min_clicked()
{
     this->showMinimized();
}

void MainWindow::on_tbHome_clicked()
{
//    DataConnectSetup *connectSetDlg = new DataConnectSetup();  //定义弹出子窗口
//       QPoint moveTo(100, 100);// = m_connectSetBtn->mapToGlobal(QPoint(0,0));
//       moveTo += QPoint(20, 38);  //具体位置自行调试
//       connectSetDlg->move(moveTo);
//       connectSetDlg->show();
    setTabBarIndex (0);
    stackedWidget->setCurrentIndex (0);
}

void MainWindow::on_tbHorse_clicked()
{
    setTabBarIndex (1);
    stackedWidget->setCurrentIndex (1);
}

void MainWindow::on_tbClear_clicked()
{
    setTabBarIndex (2);
    stackedWidget->setCurrentIndex (2);
}

void MainWindow::on_tbFix_clicked()
{
    setTabBarIndex (3);
    stackedWidget->setCurrentIndex (3);
}

void MainWindow::on_tbYouhua_clicked()
{
    setTabBarIndex (4);
    stackedWidget->setCurrentIndex (4);
}

void MainWindow::on_tbActions_clicked()
{
    setTabBarIndex (5);
    stackedWidget->setCurrentIndex (5);
}

void MainWindow::on_tbMarket_clicked()
{
 //   setTabBarIndex (6);
    Market360Dialog * md = new Market360Dialog;
    md->exec ();
}

void MainWindow::on_tbApp_clicked()
{
   // setTabBarIndex (7);
}

void MainWindow::createContextMenu () {
    QAction *shezhi = new QAction( tr("设置"), this);
    connect(shezhi, SIGNAL(triggered()), this, SLOT(shezhiActionSlot()));
    shezhi->setIcon (QIcon(":/menu/images/menu/menu_option.png"));
    QAction *jianchagengxin = new QAction( tr("检查更新"), this);
    connect(jianchagengxin, SIGNAL(triggered()), this, SLOT(jianchagengxinActionSlot()));
    jianchagengxin->setIcon (QIcon(":/menu/images/menu/menu_upgrade.png"));
    QAction *qiehuan = new QAction( tr("切换为企业版本"), this);
    connect(qiehuan, SIGNAL(triggered()), this, SLOT(qiehuanActionSlot()));
    qiehuan->setIcon (QIcon(":/menu/images/menu/menu_change.png"));
    QAction *wentifankui = new QAction( tr("问题反馈"), this);
    connect(wentifankui, SIGNAL(triggered()), this, SLOT(wentifankuiActionSlot()));
    wentifankui->setIcon (QIcon(":/menu/images/menu/menu_question.png"));
    QAction *luntan = new QAction( tr("论坛求助"), this);
    connect(luntan, SIGNAL(triggered()), this, SLOT(luntanActionSlot()));
    luntan->setIcon (QIcon(":/menu/images/menu/menu_help.png"));
    QAction *wangzhan = new QAction( tr("360网站"), this);
    connect(wangzhan, SIGNAL(triggered()), this, SLOT(wangzhanActionSlot()));
    wangzhan->setIcon (QIcon(":/menu/images/menu/menu_web.png"));
    QAction *yinsi = new QAction( tr("隐私保护"), this);
    yinsi->setIcon (QIcon(":/menu/images/menu/menu_yinsi.png"));
    connect(yinsi, SIGNAL(triggered()), this, SLOT(yinsiActionSlot()));
    QAction *mianfei = new QAction( tr("360为什么免费"), this);
    connect(mianfei, SIGNAL(triggered()), this, SLOT(mianfeiActionSlot()));
    mianfei->setIcon (QIcon(":/menu/images/menu/menu_mian.png"));
    QAction *guanyu = new QAction( tr("关于我们"), this);
    connect(guanyu, SIGNAL(triggered()), this, SLOT(guanyuActionSlot()));
    guanyu->setIcon (QIcon(":/menu/images/menu/menu_about.png"));

    contextmenu = new QMenu(this);
    contextmenu->addAction(shezhi);
    contextmenu->addAction(jianchagengxin);
    contextmenu->addAction(qiehuan);
    contextmenu->addSeparator();
    contextmenu->addAction(wentifankui);
    contextmenu->addAction(luntan);
    contextmenu->addAction(wangzhan);
    contextmenu->addAction(yinsi);
    contextmenu->addAction(mianfei);
    contextmenu->addAction(guanyu);
    //设置如何显示上下文菜单
    this->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::showContextMenu ()  {

    QPoint point = ui->menu->mapToGlobal (QPoint(0,
                   ui->menu->height ()));
    contextmenu->hide ();
    contextmenu->move(point); //让菜单显示的位置在鼠标的坐标上
    contextmenu->show();
}

void MainWindow::on_menu_clicked()
{
    showContextMenu ();
}

void MainWindow::shezhiActionSlot() {
    OptionDialog * od = new OptionDialog;
    od->exec ();
}

void MainWindow::jianchagengxinActionSlot() {
    UpgradeDialog * ud = new UpgradeDialog;
    ud->exec ();
}

void MainWindow::qiehuanActionSlot() {

}

void MainWindow::wentifankuiActionSlot(){
    QuestionDialog * qd = new QuestionDialog;
    qd->exec ();
}

void MainWindow::luntanActionSlot(){
    const QUrl url("http://bbs.360.cn/forum-140-1.html?ver=11.0.0.1001&sys=windowsnt");
    QDesktopServices::openUrl(url);
}

void MainWindow::wangzhanActionSlot(){
    const QUrl url("http://www.360.cn/?uid=1&pid=105720&m=4bf713720bc3e781be1a94f8ee88fff5");
    QDesktopServices::openUrl(url);
}

void MainWindow::yinsiActionSlot(){
    const QUrl url("http://www.360.cn/privacy/v2/index.html");
    QDesktopServices::openUrl(url);
}

void MainWindow::mianfeiActionSlot(){
    const QUrl url("http://se.360.cn/wel/whyFree.html");
    QDesktopServices::openUrl(url);
}

void MainWindow::guanyuActionSlot(){
    AboutDialog * qd = new AboutDialog;
    qd->exec ();
}

void MainWindow::showStackedWidget () {
    stackedWidget = new QStackedWidget;

    HomeWidget * hw = new HomeWidget;
    stackedWidget->addWidget (hw);

    HorseWidget * horseWidget = new HorseWidget;
    stackedWidget->addWidget (horseWidget);

    ClearWidget * clearWidget = new ClearWidget;
    stackedWidget->addWidget (clearWidget);

    FixWidget * fixWidget = new FixWidget;
    stackedWidget->addWidget (fixWidget);

    OptimizeWidget * optimizeWidget = new OptimizeWidget;
    stackedWidget->addWidget (optimizeWidget);

    FuctionsWidget * fuctionWidget = new FuctionsWidget;
    stackedWidget->addWidget (fuctionWidget);

    ui->verticalLayout->addWidget (stackedWidget);
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){//左键拖动窗体
       relativePos = this->pos()- event->globalPos();
   }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() + relativePos);
}

void MainWindow::onHoverPushButtonHoverSlot(HoverPushButton*pb) {
    showLoginPopupWidget ();
}

void MainWindow::onHoverPushButtonNoHoverSlot(HoverPushButton*pb) {
    if (!loginPopupWidget->rect ().contains (loginPopupWidget->mapFromGlobal (QCursor::pos())) &&
            !ui->pb360->rect ().contains (ui->pb360->mapFromGlobal (QCursor::pos())) &&
            !ui->pbIcon->rect ().contains (ui->pbIcon->mapFromGlobal (QCursor::pos())) &&
            !ui->pbLogion->rect ().contains (ui->pbLogion->mapFromGlobal (QCursor::pos()))) {
       hideLoginPopupWidget ();
    }
}

void MainWindow::showLoginPopupWidget () {
    if (loginPopupWidget == NULL) {
        loginPopupWidget = new PopupWidget (this);
        loginPopupWidget->setArrow (PopupArrowDirection::UP, QRect(225, 0, 10, 10));
        loginPopupWidget->setGeometry (630, 95, 250, 140);
        connect (loginPopupWidget, SIGNAL(onMouseEnterPopupWidget(PopupWidget*)), this,
                 SLOT(onMouseEnterPopupWidgetSlot(PopupWidget*)));
        connect (loginPopupWidget, SIGNAL(onMouseLeavePopupWidget(PopupWidget*)), this,
                 SLOT(onMouseLeavePopupWidgetSlot(PopupWidget*)));
        loginPopupWidget->setWindowFlags (Qt::WindowStaysOnTopHint);

        //
        loginPopupWidget->addWidget (new LoginWidget);
    }

    if (!loginPopupWidget->isVisible ()) {
        loginPopupWidget->setVisible (true);
    }
}

void MainWindow::hideLoginPopupWidget () {
    if (loginPopupWidget->isVisible ()) {
        loginPopupWidget->setVisible (false);
    }
}

void MainWindow::onMouseEnterPopupWidgetSlot(PopupWidget* widget) {
    showLoginPopupWidget ();
}

void MainWindow::onMouseLeavePopupWidgetSlot(PopupWidget* widget) {
    // 只有出了这几个控件范围,才会隐藏
    if (!loginPopupWidget->rect ().contains (loginPopupWidget->mapFromGlobal (QCursor::pos())) &&
            !ui->pb360->rect ().contains (ui->pb360->mapFromGlobal (QCursor::pos())) &&
            !ui->pbIcon->rect ().contains (ui->pbIcon->mapFromGlobal (QCursor::pos())) &&
            !ui->pbLogion->rect ().contains (ui->pbLogion->mapFromGlobal (QCursor::pos()))) {
       hideLoginPopupWidget ();
    }
}
