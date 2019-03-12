#include "upgradedialog.h"
#include "ui_upgradedialog.h"
#include <QDesktopServices>
#include <QUrl>

UpgradeDialog::UpgradeDialog(QWidget *parent) :
    QDialog(parent, Qt::FramelessWindowHint),
    ui(new Ui::UpgradeDialog)
{
    ui->setupUi(this);

    //
    ui->label->setStyleSheet ("color: #FFFFFF;");
    ui->title->setStyleSheet ("color: #444444;font-size: 25px;");
    ui->title->setAlignment (Qt::AlignCenter);
    ui->subtitle->setAlignment (Qt::AlignCenter);
    // 关闭按钮
    ui->close->setStyleSheet (QString("border-image: url(:/top/images/top/top_close.png)"));
    ui->icon->setStyleSheet ("border-image: url(:/other/images/other/icon.png)");
    ui->pushButton->setStyleSheet (QString("background-color: #EDEDED;border-radius: 15px;color: #000000;font-size: 15px;border: 1px solid #4cb702;"));

    //
    ui->bottom->setStyleSheet ("QWidget#bottom{background-color: #F7F7F7}");
    ui->middle->setStyleSheet ("QWidget#middle{background-color: #FFFFFF}");
    //a59ce7 625eae
    ui->top->setStyleSheet ("QWidget#top{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #a59ce7, stop:1 #625eae);}");

    //设置链接颜色:
    ui->subtitle->setOpenExternalLinks(true);
    ui->subtitle->setText(QString::fromLocal8Bit("您还可前往360<a href=\"http://www.360.cn/?uid=1&pid=105720&m=4bf713720bc3e781be1a94f8ee88fff5\">官网</a>覆盖安装最新版本,享受最优体验"));
    connect(ui->subtitle,SIGNAL(linkActivated(QString)),this,SLOT(openUrl(QString)));  //在.h里面定义一个槽private slots: void openUrl(QString url);
}

UpgradeDialog::~UpgradeDialog()
{
    delete ui;
}

void UpgradeDialog::on_close_clicked()
{
    this->close ();
}

void UpgradeDialog::on_pushButton_clicked()
{
    this->close ();
}

void UpgradeDialog::openUrl(QString url) {
    QDesktopServices::openUrl(QUrl(url));
}
