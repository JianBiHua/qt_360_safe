#ifndef PROGRESSBARWIDGET_H
#define PROGRESSBARWIDGET_H

#include <QWidget>

class ProgressBarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ProgressBarWidget(QWidget *parent = 0);

signals:

public slots:

private:
    QColor mColor;
    float mProgress;

public:
    void setColor (QColor color);
    void setProgress (float progress);

private:
    void paintEvent (QPaintEvent *event);
};

#endif // PROGRESSBARWIDGET_H
