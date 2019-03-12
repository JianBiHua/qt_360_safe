#include "optiondialog.h"
#include "ui_optiondialog.h"
#include <qdebug.h>

OptionDialog::OptionDialog(QWidget *parent) :
    QDialog(parent, Qt::FramelessWindowHint),
    ui(new Ui::OptionDialog)
{
    ui->setupUi(this);

    mOldWidget = NULL;
    mOldType = 0;

    ui->background->setStyleSheet ("QWidget#background{background-color:#22CB64}");
    ui->title->setStyleSheet ("color:#FFFFFF");
    // 关闭按钮
    ui->close->setStyleSheet (QString("border-image: url(:/top/images/top/top_close.png)"));

    ui->main->setStyleSheet ("#main{background-color: #FFFFFF}");
    ui->bottom->setStyleSheet ("background-color: #FFFFFF");
    ui->pushButton_2->setStyleSheet ("color: #3a91db");
    ui->pushButton->setStyleSheet ("background-color: #e3e3e3; border: 1px solid #c0c2c0;");
    ui->treeWidget->setStyleSheet ("QTreeWidget#treeWidget{border: 1px solid #d9d9d9;}");
    ui->right->setStyleSheet ("#right{border: 1px solid #d9d9d9;}");

    //
    ui->treeWidget->header ()->setVisible (false);
    ui->treeWidget->setFocusPolicy (Qt::NoFocus);
    ui->treeWidget->setSelectionMode (QAbstractItemView::NoSelection);
    ui->treeWidget->setIndentation (0);
  //    ui->treeWidget->setItemsExpandable(false);

    connect (ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(onTreeWidgetDidClicked(QTreeWidgetItem*,int)));

    //
    OptionItem * item = new OptionItem(0, "基础设置", ":/option/images/option/option_top_1.png", 0, false);
    item->subitems.append (new OptionItem(0, "功能定制", ":/option/images/option/option_cell_1.png", 1));
    item->subitems.append (new OptionItem(0, "界面缩放", ":/option/images/option/option_cell_1.png", 1));
    item->subitems.append (new OptionItem(0, "提醒设置", ":/option/images/option/option_cell_1.png", 1));
    item->subitems.append (new OptionItem(0, "系统右键菜单", ":/option/images/option/option_cell_1.png", 1));
    item->subitems.append (new OptionItem(0, "升级设置", ":/option/images/option/option_cell_1.png", 1));
    item->subitems.append (new OptionItem(0, "开机启动项设置", ":/option/images/option/option_cell_1.png", 1));
    item->subitems.append (new OptionItem(0, "用户体验改善计划", ":/option/images/option/option_cell_1.png", 1));
    item->subitems.append (new OptionItem(0, "云安全计划", ":/option/images/option/option_cell_1.png", 1));
    item->subitems.append (new OptionItem(0, "网址云安全计划", ":/option/images/option/option_cell_1.png", 1));
    items.append (item);
    item = new OptionItem(0, "弹窗设置", ":/option/images/option/option_top_2.png", 0, false);
    item->subitems.append (new OptionItem(0, "防护弹窗模式", ":/option/images/option/option_cell_1.png", 1));
    item->subitems.append (new OptionItem(0, "网购安全提示", ":/option/images/option/option_cell_1.png", 1));
    item->subitems.append (new OptionItem(0, "邮件安全提示", ":/option/images/option/option_cell_1.png", 1));
    items.append (item);
    items.append (new OptionItem(0, "开机小助手", ":/option/images/option/option_top_3.png", 0));
    item = new OptionItem(0, "安全防护中心", ":/option/images/option/option_top_4.png", 0, false);
    item->subitems.append (new OptionItem(0, "网页安全防护", ":/option/images/option/option_cell_1.png", 1));
    item->subitems.append (new OptionItem(0, "看片安全防护", ":/option/images/option/option_cell_1.png", 1));
    items.append (item);
    item = new OptionItem(0, "漏洞修复", ":/option/images/option/option_top_5.png", 0, false);
    item->subitems.append (new OptionItem(0, "不定保存设置", ":/option/images/option/option_cell_1.png", 1));
    item->subitems.append (new OptionItem(0, "补丁下载安装顺序", ":/option/images/option/option_cell_1.png", 1));
    item->subitems.append (new OptionItem(0, "其它设置", ":/option/images/option/option_cell_1.png", 1));
    items.append (new OptionItem(0, "木马查杀", ":/option/images/option/option_top_6.png", 0));

    optionTreeWidget ();

    // 默认打开第一项的第一个子项
    ui->treeWidget->itemClicked (ui->treeWidget->topLevelItem (0)->child (0), 0);
    ui->treeWidget->expandItem (ui->treeWidget->topLevelItem (0));

    //
    ui->groupBox->setStyleSheet ("QGroupBox {"
                                 "border: 2px solid #14932e;"
                                 "border-radius: 5px;"
                                 "margin-top: 1ex; "
                                 "color: #14932e"
                             "}"
                             "QGroupBox::title {"
                                 "subcontrol-origin: margin;"
                                 "subcontrol-position: top center; "
                                 "padding: 0 3px;"
                                 "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                                   "stop: 0 #FFOECE, stop: 1 #FFFFFF);"
                             "}");
}

OptionDialog::~OptionDialog()
{
    delete ui;
}

void OptionDialog::on_close_clicked()
{
    this->close ();
}

void OptionDialog::on_pushButton_clicked()
{
    this->close ();
}

void OptionDialog::optionTreeWidget () {

    for (int i = 0; i < items.size (); i++) {
        OptionItem * oItem = items.at (i);
        QTreeWidgetItem* item = new QTreeWidgetItem;
        item->setSizeHint (0, QSize(190, 30));
        ui->treeWidget->addTopLevelItem (item);
        ui->treeWidget->setItemWidget (item, 0, topItemWidget (oItem));

        for (int j = 0; j < oItem->subitems.size (); j++) {
            OptionItem * sub = oItem->subitems.at (j);

            QTreeWidgetItem* subItem = new QTreeWidgetItem;
            subItem->setSizeHint (0, QSize(190, 30));
            item->addChild (subItem);
            ui->treeWidget->setItemWidget (subItem, 0, cellItemWidget (sub));
        }
    }
}

QWidget * OptionDialog::topItemWidget (OptionItem * item) {
    QWidget * w = new QWidget;
    w->setObjectName ("topItemWidget");
    w->setGeometry (0, 0, 150, 30);

    QWidget * icon = new QWidget(w);
    icon->setGeometry (20, 5, 20, 20);
    icon->setStyleSheet (QString("border-image: url(%1)").arg (item->mIcon));

    QLabel * label = new QLabel(w);
    label->setGeometry (45, 5, 100, 20);
    label->setText (item->mTitle);

    w->setStyleSheet ("QWidget#topItemWidget{background-color: #f3f3f3}");

    return w;
}

QWidget * OptionDialog::cellItemWidget (OptionItem * item) {
    QWidget * w = new QWidget;
    w->setObjectName ("cellItemWidget");
    w->setGeometry (0, 0, 150, 30);

    QWidget * icon = new QWidget(w);
    icon->setGeometry (30, 5, 20, 20);
    icon->setStyleSheet (QString("border-image: url(%1)").arg (item->mIcon));

    QLabel * label = new QLabel(w);
    label->setGeometry (55, 5, 100, 20);
    label->setText (item->mTitle);

    w->setStyleSheet ("QWidget#cellItemWidget{background-color: #FFFFFF}");

    return w;
}

void OptionDialog::onTreeWidgetDidClicked(QTreeWidgetItem* item,int row) {
    QTreeWidgetItem* pitem = item->parent ();
    int subCol = ui->treeWidget->indexOfTopLevelItem (item);
    int subRow = 0;
    QWidget *widget = NULL;

    bool isTopItem = (subCol!=-1);
    if (subCol == -1) {
        subCol = ui->treeWidget->indexOfTopLevelItem (pitem);
        subRow = pitem->indexOfChild (item);
    } else {
    }

    OptionItem* top = items.at (subCol);
    int isbreak = -1;
    if (isTopItem) {
        // 关闭其它的项
        for (int i = 0; i < items.size (); i++) {
            if (i != subCol) {
                 ui->treeWidget->collapseItem(ui->treeWidget->topLevelItem (i));
                 //
            } else {
                ui->treeWidget->expandItem (ui->treeWidget->topLevelItem (i));
                if (!top->mCanClick) {
                    // ui->treeWidget->itemClicked (ui->treeWidget->topLevelItem (i)->child (0), 0);
                    isbreak = i;
                }
            }
        }

        if (isbreak == -1 && top->mCanClick) {
            widget = (QWidget *) ui->treeWidget->itemWidget (item, 0);
            widget->setStyleSheet ("QWidget#topItemWidget{background-color: #14932e}");
            //
            mOldType = 0;
        }
    } else {
        widget = (QWidget *) ui->treeWidget->itemWidget (item, 0);
        widget->setStyleSheet ("QWidget#cellItemWidget{background-color: #14932e}");
        //
        mOldType = 1;
    }

    toBreak:
    // 恢复历史点击项
    if (mOldWidget != NULL && mOldWidget != widget) {
       if (mOldType== 0) {
           mOldWidget->setStyleSheet ("QWidget#topItemWidget{background-color: #f3f3f3}");
       } else {
           mOldWidget->setStyleSheet ("QWidget#cellItemWidget{background-color: #FFFFFF}");
       }
    }
    mOldWidget = widget;

    // 这个必须放到最后,否则上面程序会执行两次.
    // 可以试试去掉上面那个注释看看效果.
    if (isbreak != -1) {
        ui->treeWidget->itemClicked (ui->treeWidget->topLevelItem (isbreak)->child (0), 0);
    }
}
