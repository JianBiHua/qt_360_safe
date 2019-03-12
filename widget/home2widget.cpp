#include "home2widget.h"
#include "ui_home2widget.h"
#include <QTreeWidgetItem>
#include <qdebug.h>

Home2Widget::Home2Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home2Widget)
{
    ui->setupUi(this);

    currentCheckWidget = NULL;
    //
    //ui->background->setStyleSheet ("QWidget#background{background-color: rgba(255, 255, 255, 230);}");
    ui->bottom->setStyleSheet ("QWidget#bottom{background-color: #FFFFFF;}");
    ui->top->setStyleSheet ("QWidget#top{background-color: #f1f9f1;}");
    ui->pushButton->setStyleSheet ("background-color: transparent;border-radius: 16px;color: #4cb702;font-size: 15px;border: 1px solid #4cb702;");
    ui->title->setStyleSheet ("color: #444444;font-size: 25px;");
    ui->subtitle->setStyleSheet ("color: #9b9999;font-size: 16px;");
    //
    ui->waveBall->setWaveMode (WaveBallMode::noWaveMode);
    ui->waveBall->setProgress (1);
    ui->waveBall->startRound ();
    //
    ui->progreBar->setProgress (0);

    //
    ui->treeWidget->header ()->setVisible (false);
    ui->treeWidget->setFocusPolicy (Qt::NoFocus);
    ui->treeWidget->setSelectionMode (QAbstractItemView::NoSelection);
    ui->treeWidget->setIndentation (0);

    //

    reset ();

    timer = new QTimer ();
    connect (timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
}

void Home2Widget::start () {
    // 每两秒一个
    timer->start (1000*1);
}

void Home2Widget::stop () {
    timer->stop ();
    currentCheckWidget->stop ();
}

void Home2Widget::reset () {
    ui->treeWidget->clear ();

    Home2TreeObj * to = new Home2TreeObj(0, 0, NULL, "鼓掌检测共9项(.....)");
    to->mSubItems.append (new Home2TreeObj(0, 1, ":/other/images/other/icon_check_1.png", "清理插件"));
    objs.append (to);
    optionTreeWidget ();

}

void Home2Widget::onTimeOut() {
    qDebug () << "onTimeOut: " << mIndex;

    // 更新进度
    ui->progreBar->setProgress (mIndex*1.0/27);

    ui->treeWidget->clear ();
    if (mIndex == 9) {
        Home2TreeObj * to = new Home2TreeObj(0, 0, NULL, "鼓掌检测共9项(.....)");
        objs.insert (0, to);
    } else  if (mIndex == 18) {
        Home2TreeObj * to = new Home2TreeObj(0, 0, NULL, "鼓掌检测共9项(.....)");
        objs.insert (0, to);
    } else  if (mIndex == 27) {
        Home2TreeObj * to = new Home2TreeObj(0, 0, NULL, "鼓掌检测共9项(.....)");
        objs.insert (0, to);
    }

    Home2TreeObj * to = objs.last ();
    to->mSubItems.append (new Home2TreeObj(0, 1, ":/other/images/other/icon_check_1.png", "清理插件"));
    optionTreeWidget ();

    mIndex++;
}

Home2Widget::~Home2Widget()
{
    delete ui;
}

void Home2Widget::on_pushButton_clicked()
{
    emit onHome2IntoNextSignal ();
}

void Home2Widget::optionTreeWidget () {
    for (int i = 0; i < objs.size (); i++) {
        Home2TreeObj * oItem = objs.at (i);

        //
        QTreeWidgetItem* item = new QTreeWidgetItem;
        item->setSizeHint (0, QSize(900, 30));
        ui->treeWidget->addTopLevelItem (item);
        ui->treeWidget->setItemWidget (item, 0, titleWidget (oItem));

        // 子项
        qDebug () << "(100 * (oItem->mSubItems.size ()/7 +1): " <<  (90 * (oItem->mSubItems.size ()/7 +1));
        QTreeWidgetItem* subItem = new QTreeWidgetItem;
        subItem->setSizeHint (0, QSize(900, (90 * (oItem->mSubItems.size ()/7 +1))));
        item->addChild (subItem);
        ui->treeWidget->setItemWidget (subItem, 0, cellWidget (oItem, i==0));
   }

    ui->treeWidget->expandAll ();
}

QWidget * Home2Widget::titleWidget (Home2TreeObj * obj) {
    QWidget * w = new QWidget ;
    w->setGeometry (0, 0, 900, 30);
    w->setStyleSheet ("background-color: #F3F3F3");

    QLabel * lb = new QLabel (w);
    lb->setGeometry (70, 0, 900, 30);
    lb->setText (obj->mTitle);

    return w;
}

QWidget * Home2Widget::cellWidget (Home2TreeObj * obj, bool isLast) {
    QWidget * w = new QWidget ;
    w->setGeometry (0, 0, 900, (90 * (obj->mSubItems.size ()/7 +1)));

    for (int i = 0; i < obj->mSubItems.size (); i++) {
        Home2TreeObj * item = obj->mSubItems.at (i);

        QWidget * sub = new QWidget(w) ;
        sub->setGeometry (50+(i%7)*120, (i/7)*90, 100, 90);

        CheckWidget *cw = new CheckWidget(sub);
        cw->setGeometry (20, 15, 60, 60);
        cw->setIcon (item->mIcon);
        if (isLast && i == obj->mSubItems.size ()-1) {
            cw->start ();
            currentCheckWidget = cw;
        } else {
            cw->stop ();
        }
        QLabel * lb = new QLabel (sub);
        lb->setGeometry (0, 70, 100, 20);
        lb->setAlignment (Qt::AlignCenter);
        lb->setText (item->mTitle);
    }

    return w;
}
