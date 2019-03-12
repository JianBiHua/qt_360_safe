#include "fuctionswidget.h"
#include "ui_fuctionswidget.h"
#include <QLabel>
#include <qdebug.h>
#include "widget/actionswidget.h"

FuctionsWidget::FuctionsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FuctionsWidget)
{
    ui->setupUi(this);

    mOldIndex = -1;
    //
    ui->background->setStyleSheet ("background-color: #FFFFFF;");
    ui->listWidgetBackGround->setStyleSheet ("background-color: #F3F3F3;");

    functionList.append (new FunctionsItem(0, ":/other/images/other/icon_fanghuzhongxin.png",
                                       ":/other/images/other/icon_fanghuzhongxin.png",
                                       "全部工具", 0));
    functionList.append (new FunctionsItem(0, ":/other/images/other/icon_fanghuzhongxin.png",
                                       ":/other/images/other/icon_fanghuzhongxin.png",
                                       "电脑安全", 1));
    functionList.append (new FunctionsItem(0, ":/other/images/other/icon_fanghuzhongxin.png",
                                       ":/other/images/other/icon_fanghuzhongxin.png",
                                       "网络优化", 1));
    functionList.append (new FunctionsItem(0, ":/other/images/other/icon_fanghuzhongxin.png",
                                       ":/other/images/other/icon_fanghuzhongxin.png",
                                       "系统工具", 1));
    functionList.append (new FunctionsItem(0, ":/other/images/other/icon_fanghuzhongxin.png",
                                       ":/other/images/other/icon_fanghuzhongxin.png", "游戏优化", 1));
    functionList.append (new FunctionsItem(0, ":/other/images/other/icon_fanghuzhongxin.png",
                                       ":/other/images/other/icon_fanghuzhongxin.png",
                                       "实用工具", 1));
    functionList.append (new FunctionsItem(0, ":/other/images/other/icon_fanghuzhongxin.png",
                                       ":/other/images/other/icon_fanghuzhongxin.png",
                                       "我的工具", 0));
    optionListWidget ();
    optoinScrollView ();

    //
    ui->redian->setStyleSheet ("color: #FFFFFF; background-color: #fa9626");
    ui->redian->setAlignment (Qt::AlignCenter);
    ui->line->setStyleSheet ("background-color: #d9d9d9");
    ui->line_2->setStyleSheet ("background-color: #d9d9d9");
    ui->searchIcon->setCursor(Qt::ArrowCursor);
    ui->searchIcon->setStyleSheet ("border-image: url(:/other/images/other/icon_search_normal.png)");
    ui->search->setStyleSheet ("#search{border: 1px solid #d9d9d9; border-radius: 15px;}");
    ui->lineEdit->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->lineEdit->setPlaceholderText ("搜索工具");
    ui->lineEdit->setStyleSheet ("border: 0px;");
}

FuctionsWidget::~FuctionsWidget()
{
    delete ui;
}

void FuctionsWidget::optoinScrollView () {
    scrollArea = new QScrollArea(ui->scrollview);
//    scrollArea->setBackgroundRole(QPalette::Dark);

    ActionsWidget * aw = new ActionsWidget;
    aw->setMinimumSize (0, aw->height ());;
    scrollArea->setWidget(aw);
    //强制滚动条总可见 水平
    //scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //强制滚动条总可见 竖直
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setGeometry (0, 0, ui->scrollview->width (), ui->scrollview->height ());
    scrollArea->setStyleSheet ("background-color: #FFFFFF");
}

void FuctionsWidget::optionListWidget () {

    ui->listWidget->setStyleSheet ("border: none; background-color: rgba(0, 0, 0, 0)");
    ui->listWidget->setFocusPolicy(Qt::NoFocus);
    ui->listWidget->setSelectionMode (QAbstractItemView::NoSelection);
    connect (ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
             this, SLOT(onListwidgetClicked(QListWidgetItem*)));

    //
    for (int i = 0; i < functionList.size (); i++) {
        FunctionsItem * fi = functionList.at (i);

        QListWidgetItem *item = new QListWidgetItem;
        item->setSizeHint (QSize (140, !fi->type?60:40));
        QWidget * widget = new QWidget;

        QWidget * back = new QWidget(widget) ;

        QWidget * icon = new QWidget(widget) ;
        icon->setStyleSheet (QString("border-image: url(%1)").arg (fi->icon));

        QLabel *lb = new QLabel (widget);
        lb->setText (fi->name);
        lb->setStyleSheet ("color: #7e797f");

        if (!fi->type) {
            back->setGeometry (0, 0, 150, 60);
            icon->setGeometry (15, 15, 30, 30);
            lb->setGeometry (45, 15, 100, 30);
            back->setStyleSheet ("background-color: rgba(0,0,0,0);border: 1px solid #e9e9ea;");
        } else {
            back->setGeometry (0, 0, 150, 40);
            icon->setGeometry (30, 5, 30, 30);
            lb->setGeometry (70, 5, 100, 30);
            back->setStyleSheet ("background-color: rgba(0,0,0,0);");
        }

        ui->listWidget->addItem (item);
        ui->listWidget->setItemWidget (item, widget);
    }

    //
    ui->listWidget->itemClicked (ui->listWidget->item (0));
}

void FuctionsWidget::onListwidgetClicked(QListWidgetItem*item) {
    int index = ui->listWidget->row (item);;//ui->listWidget->currentRow ();
    FunctionsItem * fi = functionList.at (index);
    QWidget * widget = (QWidget *) ui->listWidget->itemWidget (item);

    if (mOldIndex != index) {
       QWidget* b=(QWidget*) widget->children ().at (0);
       QWidget* w=(QWidget*) widget->children ().at (1);
       QLabel* l=(QLabel*) widget->children ().at (2);

       w->setStyleSheet (QString("border-image: url(%1)").arg (fi->iconH));
       l->setStyleSheet ("color: #5eb161");
       b->setStyleSheet ("background-color: #FFFFFF");

       if (mOldIndex != -1) {
           fi = functionList.at (mOldIndex);
           widget = (QWidget *) ui->listWidget->itemWidget (ui->listWidget->item (mOldIndex));
           w=(QWidget*) widget->children ().at (1);
           l=(QLabel*) widget->children ().at (2);
           b=(QWidget*) widget->children ().at (0);

           if (!fi->type) {
               b->setStyleSheet ("background-color: rgba(0,0,0,0);border: 1px solid #e9e9ea;");
           } else {
               b->setStyleSheet ("background-color: rgba(0,0,0,0)");
           }
           w->setStyleSheet (QString("border-image: url(%1)").arg (fi->icon));
           l->setStyleSheet ("color: #7e797f");
        }
    }
    mOldIndex = index;
}
