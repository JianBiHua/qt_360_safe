#ifndef WAVEBALLWIDGET_H
#define WAVEBALLWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QVector>

enum WaveBallMode {
    waveMode = 0,                               // 波形模式
    noWaveMode = 1,                             // 普通模式
};

//
class Bubble : public QObject{
Q_OBJECT
public:
    explicit Bubble(QWidget *parent = 0, QPoint p = QPoint(), int w = 10, float s = 1.0):
        point(p),
        width(w),
        speed (s) {
    }

public:
    QPoint point;
    int width;
    float speed;
};

class WaveBallWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WaveBallWidget(QWidget *parent = 0);
    ~WaveBallWidget();

protected:
    void paintEvent (QPaintEvent *event);

private slots:
    void on_timer_out();
    void on_roundTimer_out();

public:
    void startRound ();
    void stopRound ();

    void startWave ();
    void stopWave ();

    // 波形模式.
    void setWaveMode (WaveBallMode mode = waveMode);
    // 显示边框圆
    void showRound (bool isShow = true);
    // 显示分数
    void showScores (bool s);

    //
    void setProgress (float p);

    //
    void setIcon (QString icon, QSize size);

private:
    int offset;
    float progress;
    // 圆的弧度
    int roundAlen;
    bool bShowRound;
    bool bShowBubble;

    // 波形模式
    WaveBallMode mWaveBallMode;
    // 气泡数组
    QVector<Bubble*> bubbles;

    //
    bool bScores;

    QTimer * timer;
    QTimer * roundTimer;

    //
    bool bShowImage;
    QString mImagePath;
    QSize mImageSize;

private:
    void drawWaveBallBg ();
    void drawWaveBall ();
    void drawFullWaveBall ();
    void drawRound ();
    void drawScores ();
    void drawBubble ();
    void drawImage ();

    Bubble * getRandBubble ();
    QColor getPenColor ();
    QLinearGradient getLinearGradient (bool isBackColor);
    QPoint getPoint (int arg, int w);
};

#endif // WAVEBALLWIDGET_H
