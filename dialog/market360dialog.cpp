#include "market360dialog.h"
#include "ui_market360dialog.h"
#include <qdebug.h>

Market360Dialog::Market360Dialog(QWidget *parent) :
    QDialog(parent, Qt::FramelessWindowHint),
    ui(new Ui::Market360Dialog)
{
    ui->setupUi(this);

    webview = NULL;
    ui->background->setStyleSheet ("background: #F3F3F3");
    ui->icon->setStyleSheet ("image: url(:/other/images/other/icon.png)");
    ui->close->setStyleSheet ("image: url(:/top/images/top/top_close_b.png);");
    ui->min->setStyleSheet ("image: url(:/top/images/top/top_min_b.png);");
    ui->bottom->setStyleSheet ("background-color: #F5F5F5");

    optionToolButtons ();
    setTabBarIndex (0);
}

Market360Dialog::~Market360Dialog()
{
    delete ui;
}

void Market360Dialog::createWebView (QString url) {
    if (webview == NULL) {
        webview = new QWebEngineView;
        ui->verticalLayout->addWidget (webview);
    }

    webview->load(QUrl(url));
}

void Market360Dialog::on_close_clicked()
{
    this->close ();
}

void Market360Dialog::optionToolButtons () {
    optionToolButton (ui->toolButton,
                      QIcon(":/market/images/market/market_icon_1_b.png"),
                      "首页",
                      QSize(30, 30),
                      "market_toolbutton");
    optionToolButton (ui->toolButton_2,
                      QIcon(":/market/images/market/market_icon_2_b.png"),
                      "手机",
                      QSize(30, 30),
                      "market_toolbutton");
    optionToolButton (ui->toolButton_3,
                      QIcon(":/market/images/market/market_icon_3_b.png"),
                      "出行",
                      QSize(30, 30),
                      "market_toolbutton");
    optionToolButton (ui->toolButton_4,
                      QIcon(":/market/images/market/market_icon_4_b.png"),
                      "家居",
                      QSize(30, 30),
                      "market_toolbutton");
    optionToolButton (ui->toolButton_5,
                      QIcon(":/market/images/market/market_icon_5_b.png"),
                      "陪护",
                      QSize(30, 30),
                      "market_toolbutton");
}


void Market360Dialog::optionToolButton (QToolButton * tb,
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


void Market360Dialog::setTabBarIndex (int index) {
    ui->toolButton->setIcon (QIcon(index==0?":/market/images/market/market_icon_1_g.png":":/market/images/market/market_icon_1_b.png"));
    ui->toolButton->setStyleSheet (index==0?"color: #06c655;":"color: 8b8b8b;");
    ui->toolButton_2->setIcon (QIcon(index==1?":/market/images/market/market_icon_2_g.png":":/market/images/market/market_icon_2_b.png"));
    ui->toolButton_2->setStyleSheet (index==1?"color: #06c655;":"color: 8b8b8b;");
    ui->toolButton_3->setIcon (QIcon(index==2?":/market/images/market/market_icon_3_g.png":":/market/images/market/market_icon_3_b.png"));
    ui->toolButton_3->setStyleSheet (index==2?"color: #06c655;":"color: 8b8b8b;");
    ui->toolButton_4->setIcon (QIcon(index==3?":/market/images/market/market_icon_4_g.png":":/market/images/market/market_icon_4_b.png"));
    ui->toolButton_4->setStyleSheet (index==3?"color: #06c655;":"color: 8b8b8b;");
    ui->toolButton_5->setIcon (QIcon(index==4?":/market/images/market/market_icon_5_g.png":":/market/images/market/market_icon_5_b.png"));
    ui->toolButton_5->setStyleSheet (index==4?"color: #06c655;":"color: 8b8b8b;");

    QString url[] = {
        QString("http://mall.safe.360.cn/index.html"),
        QString("http://mall.safe.360.cn/list_phone.html"),
        QString("http://mall.safe.360.cn/list_trip.html"),
        QString("http://mall.safe.360.cn/list_houseware.html"),
        QString("http://mall.safe.360.cn/list_accompany.html"),
    };
    createWebView (url[index]) ;
 }


void Market360Dialog::on_toolButton_clicked()
{
    setTabBarIndex (0);
}

void Market360Dialog::on_toolButton_2_clicked()
{
    setTabBarIndex (1);
}

void Market360Dialog::on_toolButton_3_clicked()
{
    setTabBarIndex (2);
}

void Market360Dialog::on_toolButton_4_clicked()
{
    setTabBarIndex (3);
}

void Market360Dialog::on_toolButton_5_clicked()
{
    setTabBarIndex (4);
}
