#ifndef HOME2WIDGET_H
#define HOME2WIDGET_H

#include <QWidget>
#include <QVector>
#include <QTimer>
#include "customviews/checkwidget.h"

namespace Ui {
class Home2Widget;
}

class Home2TreeObj : public QObject {
Q_OBJECT
public:
    explicit Home2TreeObj(QWidget *parent = 0, int t = 0, QString i = NULL, QString n = "") :
        mType(t), mIcon (i), mTitle (n)
    {}
public:
    // 0: 头 1: 子项
    int mType;
    //
    QString mIcon;
    QString mTitle;

    QVector<Home2TreeObj *> mSubItems;
};

class Home2Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Home2Widget(QWidget *parent = 0);
    ~Home2Widget();

private:
    Ui::Home2Widget *ui;
    //
    QVector <Home2TreeObj *> objs;
    CheckWidget * currentCheckWidget;
    QTimer * timer ;
    int mIndex;

signals:
    void onHome2IntoNextSignal ();


private slots:
    void on_pushButton_clicked();

    void onTimeOut();

private:
    void optionTreeWidget ();
    QWidget * titleWidget (Home2TreeObj * obj);
    QWidget * cellWidget (Home2TreeObj * obj, bool isLast);
    void reset ();

public:
    void start ();
    void stop ();
};

#endif // HOME2WIDGET_H
