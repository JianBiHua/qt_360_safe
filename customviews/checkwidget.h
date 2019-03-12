#ifndef CHECKWIDGET_H
#define CHECKWIDGET_H

#include <QWidget>
#include <QTimer>

class CheckWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CheckWidget(QWidget *parent = 0);

protected:
    void paintEvent (QPaintEvent *event);

signals:

public slots:
    void onTimerOut();

private:
    QString mImagePath;
    QTimer *timer;
    float mImageSpread;
    int mCurrentAln;
    bool bCheckFinisehd;

public:
    void setIcon (QString icon);
    void start ();
    void stop ();
    void setImageSpraed (float s) ;
};

#endif // CHECKWIDGET_H
