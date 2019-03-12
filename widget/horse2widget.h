#ifndef HORSE2WIDGET_H
#define HORSE2WIDGET_H

#include <QWidget>
#include <QTimer>
#include "customviews/scanwidget.h"

namespace Ui {
class Horse2Widget;
}

class Horse2Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Horse2Widget(QWidget *parent = 0);
    ~Horse2Widget();

private:
    Ui::Horse2Widget *ui;
    QTimer * scanTimer;
    int mScanIndex;
    ScanWidget *mCurrentScanWidget;
    int timerTick;
    int randTimerDis;

signals:
    void onHorse2IntoNextSignal ();

private slots:
    void on_pushButton_clicked();

    void onScanTimerOut();

private:
    void optionScanWidgets ();
    void optionScanWidget(ScanWidget * widget);

public:
    void reset ();
    void start ();
    void stop ();
};

#endif // HORSE2WIDGET_H
