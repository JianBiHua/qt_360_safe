#include "questiondialog.h"
#include "ui_questiondialog.h"
#include <QToolButton>
#include <qdebug.h>
#include <QScrollArea>
#include <QDesktopServices>

QuestionDialog::QuestionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuestionDialog)
{
    ui->setupUi(this);

    //
    // 不显示状态栏
    // 设置窗体标题栏隐藏和窗口是否有任务栏图标
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
    this->setStyleSheet ("background-color: #FAFAFA");
    //
    ui->topWidget->setAutoFillBackground(true);
    ui->lbTitle->setStyleSheet ("color:#FFFFFF");
    ui->topWidget->setStyleSheet ("background-color:#25C966");

    // 关闭按钮
    ui->pbClose->setStyleSheet (QString("border-image: url(:/top/images/top/top_close.png)"));
    ui->pbMin->setStyleSheet (QString("border-image: url(:/top/images/top/top_min.png)"));
    ui->question->setStyleSheet (QString("border-image: url(:/question/images/question/question.png)"));
    ui->icon->setStyleSheet (QString("border-image: url(:/other/images/other/icon.png)"));
    //这句很关键啊，否则就只能通过linkActivated信号，连接到自定义槽函数中打开了
    ui->pbLuntan->setStyleSheet ("color: #FFFFFF");
    ui->pbLuntan->setText ("进入360官方论坛");

    optionGridLayout ();

    // 先隐藏
    ui->next->setHidden (true);

    ui->nextIcon->setStyleSheet ("border-image: url(:/question/images/question/next_icon2.png)");

    //next
    ui->nextTitle->setStyleSheet ("color: #004c87;font-size: 15px;font-weight:bold;");
    ui->nextPhone->setStyleSheet ("color: #004c87;font-size: 15px;font-weight:bold;");
    ui->nextQQ->setStyleSheet ("color: #004c87;font-size: 15px;font-weight:bold;");
    ui->nextTextEdit->setPlaceholderText (tr("请告诉我们你的问题的提示信息或相关截图"));
    ui->nextTextEdit->setStyleSheet ("border: 1px solid #e1e0e0;");
    ui->nextOther->setStyleSheet ("color: #ABABAB");
    ui->nextBack->setStyleSheet ("color: #0893E1");

    //
    optionToolButtons ();
    optionComboBox ();
}

QuestionDialog::~QuestionDialog()
{
    delete ui;
}

void QuestionDialog::on_pbClose_clicked()
{
    this->close ();
}

void QuestionDialog::optionGridLayout () {
    const QString texts[] = {"USB连接问题",
                             "管理预装软件问题",
                             "无线连接问题",
                             "悬浮窗问题",
                             "备份,恢复",
                             "应用下载安装使用",
                             "存储卡管理",
                             "联系人短信问题",
                             "其他问题及建议"};
    const QString icons[] = {":/question/images/question/question_icon1.png",
                            ":/question/images/question/question_icon2.png",
                            ":/question/images/question/question_icon3.png",
                            ":/question/images/question/question_icon1.png",
                            ":/question/images/question/question_icon1.png",
                            ":/question/images/question/question_icon1.png",
                            ":/question/images/question/question_icon1.png",
                            ":/question/images/question/question_icon1.png",
                            ":/question/images/question/question_icon1.png"};


    ui->gridLayout->setSpacing(3);
    ui->gridLayout->setMargin(3);
    for(int i=0; i < 3; i++) {
        for(int j = 0; j < 3;j++) {
            QToolButton * tb = new QToolButton;
            tb->setText (texts[i*3+j]);
            tb->setIcon (QIcon (icons[i*3 +j]));
            tb->setIconSize (QSize(55, 55));
            tb->setMinimumSize (100, 100);
            tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            tb->setStyleSheet ("border-radius: 10px;border: 1px solid #e1e0e0;");
            //tb->setProperty ("index", i*3+j);
            tb->setObjectName ("item_"+(i*3+j));
            ui->gridLayout->addWidget (tb, i, j);

            connect (tb, SIGNAL(clicked(bool)), this, SLOT(onToolButtonDidClickedSlot(bool)));
        }
    }
}

void QuestionDialog::onToolButtonDidClickedSlot(bool b) {
   QToolButton * tb = (QToolButton *) sender ();
   qDebug()<<tb->objectName (); //打印源头对象名称
   if("item_0" == tb->objectName ()){
   } else if("item_1" == tb->objectName ()){
   } else if("item_2" == tb->objectName ()){
   } else if("item_3" == tb->objectName ()){
   } else if("item_4" == tb->objectName ()){
   } else if("item_5" == tb->objectName ()){
   } else if("item_6" == tb->objectName ()){
   } else if("item_7" == tb->objectName ()){
   } else if("item_8" == tb->objectName ()){
   }

   // 偷懒吧,只做一个处理
    showHome (false);
}

void QuestionDialog::on_nextBack_clicked()
{
    showHome (true);
}

void QuestionDialog::optionToolButtons () {

    ui->nextScreenshot->setText ("截图");
    ui->nextScreenshot->setIcon (QIcon (":/question/images/question/next_tb_1.png"));
    ui->nextScreenshot->setIconSize (QSize(20, 20));
    ui->nextScreenshot->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->nextScreenshot->setStyleSheet ("border-radius: 2px;border: 1px solid #e1e0e0;background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #ffffff, stop:1 #e3ecf2);");

    ui->nextPhoto->setText ("添加图片");
    ui->nextPhoto->setIcon (QIcon (":/question/images/question/next_tb_2.png"));
    ui->nextPhoto->setIconSize (QSize(20, 20));
    ui->nextPhoto->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->nextPhoto->setStyleSheet ("border-radius: 2px;border: 1px solid #e1e0e0;background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #ffffff, stop:1 #e3ecf2);");

    ui->nextAnnex->setText ("添加附件");
    ui->nextAnnex->setIcon (QIcon (":/question/images/question/next_tb_3.png"));
    ui->nextAnnex->setIconSize (QSize(20, 20));
    ui->nextAnnex->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->nextAnnex->setStyleSheet ("border-radius: 2px;border: 1px solid #e1e0e0;background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #ffffff, stop:1 #e3ecf2);");

    ui->nextPost->setText ("提交问题");
    ui->nextPost->setIcon (QIcon (":/question/images/question/next_tb_1.png"));
    ui->nextPost->setIconSize (QSize(20, 20));
    ui->nextPost->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->nextPost->setStyleSheet ("border-radius: 2px;border: 1px solid #e1e0e0;background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #ffffff, stop:1 #e3ecf2);");
}

void QuestionDialog::optionComboBox () {
    ui->nextComboBox->addItem(QWidget::tr("QQ"));
    ui->nextComboBox->addItem(QWidget::tr("飞信"));
    ui->nextComboBox->addItem(QWidget::tr("旺旺"));
    ui->nextComboBox->addItem(QWidget::tr("MSN"));
    ui->nextComboBox->addItem(QWidget::tr("邮箱"));
    ui->nextComboBox->addItem(QWidget::tr("电话/手机"));
    ui->nextComboBox->addItem(QWidget::tr("其它"));
}

void QuestionDialog::on_pbLuntan_clicked()
{
    const QUrl url("http://bbs.360.cn/forum-140-1.html");
    QDesktopServices::openUrl(url);
}

void QuestionDialog::showHome (bool s) {
    ui->home->setVisible (s);
    ui->next->setVisible (!s);
}

void QuestionDialog::on_pbMin_clicked()
{
    this->showMinimized ();
}
