#ifndef SCANWIDGET_H
#define SCANWIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class ScanWidget;
}

enum ScanState {
    waitScan = 0,
    scan = 1,
    finished = 2,
};

class ScanCT: public QWidget {
    Q_OBJECT
public:
    explicit ScanCT(QWidget *parent = 0);

private:
    QTimer * timer;
    bool bToLeft;
    int mRex ;
    int mSleepTimes;

protected:
    void paintEvent (QPaintEvent *event);

private slots:
    void onTimerOver();

public:
    void start ();
    void stop ();
};

class ScanWidget : public QWidget
{
    Q_OBJECT

public:
    //explicit ScanWidget(QWidget *parent = 0, QString icon = "", QString sicon = "", QString ficon = "", QString title = "");
    explicit ScanWidget(QWidget *parent = 0);
    ~ScanWidget();

private:
    Ui::ScanWidget *ui;
    ScanState mState;
    QString mIcon;

public:
    void setScanState (ScanState state) ;
    void setIcon (QString icon);
    void setTitle (QString title);

protected:
    void update ();
};

#endif // SCANWIDGET_H
