#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    // 不显示状态栏
    // 设置窗体标题栏隐藏和窗口是否有任务栏图标
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);


    //
    ui->topWidget->setAutoFillBackground(true);
    ui->mainWidget->setAutoFillBackground(true);

    //
    ui->lbTitle->setStyleSheet ("color:#FFFFFF");

    //
//    QPalette palette;
//    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/LoginBanner.png")));
//    ui->topWidget->setPalette (palette);
    //
    QPalette palette2;
    palette2.setColor(QPalette::Background, QColor(0xFD,0xFD,0xFD));
    ui->mainWidget->setPalette (palette2);

    // 关闭按钮
    ui->pbClose->setStyleSheet (QString("border-image: url(:/top/images/top/top_close.png)"));
    ui->icon->setStyleSheet ("border-image: url(:/other/images/other/icon.png)");

    //这句很关键啊，否则就只能通过linkActivated信号，连接到自定义槽函数中打开了
    ui->guanwang->setOpenExternalLinks(true);
    ui->guanwang->setText(tr("<a href=\"http://sj.360.cn/index.html/\">http://sj.360.cn/index.html"));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_pushButton_clicked()
{
    this->close ();
}

void AboutDialog::on_pbClose_clicked()
{
    this->close ();
}
