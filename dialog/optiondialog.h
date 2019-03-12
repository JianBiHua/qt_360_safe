#ifndef OPTIONDIALOG_H
#define OPTIONDIALOG_H

#include <QDialog>
#include <QVector>
#include <QModelIndex>
#include <QTreeWidgetItem>

namespace Ui {
class OptionDialog;
}

class OptionItem : public QObject {
Q_OBJECT
public:
    explicit OptionItem(QWidget *parent = 0, QString t = "", QString i = "", int type = 0, bool canClick = true):
        mTitle(t), mIcon(i), mType(type), mCanClick(canClick){
    }

public:
    QString mTitle;
    QString mIcon;
    int mType;
    bool mCanClick;

    QVector<OptionItem*> subitems;
};

class OptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionDialog(QWidget *parent = 0);
    ~OptionDialog();

private slots:
    void on_close_clicked();

    void on_pushButton_clicked();

    void onTreeWidgetDidClicked(QTreeWidgetItem* item,int row);

private:
    Ui::OptionDialog *ui;
    QVector<OptionItem*> items;
    QWidget * mOldWidget;
    int mOldType;

private:
    void optionTreeWidget ();
    QWidget * topItemWidget (OptionItem * item);
    QWidget * cellItemWidget (OptionItem * item);
};

#endif // OPTIONDIALOG_H
