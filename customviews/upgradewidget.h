#ifndef UPGRADEWIDGET_H
#define UPGRADEWIDGET_H

#include <QWidget>
#include <QTimer>

enum UpgradeMode {
    scan = 0,                               // 扫描
    download = 1,                             // 下载
    finished = 2,//完成
};

class UpgradeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UpgradeWidget(QWidget *parent = 0);

signals:

private slots:
    void on_timer_out();

protected:
    void paintEvent (QPaintEvent *event);

private:
    QTimer * timer;
    int mRadian;
    UpgradeMode mMode;

public:
    void start ();
    void stop ();

private:
    QPoint getPoint (int arg, int w) ;

    void drawScanMode ();
    void drawDownLoadMode ();
    void drawFinishedMode ();

};

#endif // UPGRADEWIDGET_H
