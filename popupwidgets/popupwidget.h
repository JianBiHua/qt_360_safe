#ifndef POPUPWIDGET_H
#define POPUPWIDGET_H

#include <QWidget>
#include <QEvent>
#include <QVariant>

enum PopupArrowDirection {
    NONE = -1,
    UP = 0,
    RIGHT = 1,
    DOWN= 2,
    LEFT = 3
};

class PopupWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int alpha READ alpha WRITE setAlpha)
public:
    explicit PopupWidget(QWidget *parent = 0);


signals:
    void onMouseLeavePopupWidget (PopupWidget * widget);
    void onMouseEnterPopupWidget(PopupWidget * widget);

private slots:
    void onGeometryAnimationValueChanged(QVariant v);

protected:
    void paintEvent (QPaintEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent * event) ;

private:
    PopupArrowDirection mArrowDirection;
    QRect mArrowRect;
    int mAlpha;
    QRect mOldRect;

public:
    void setArrow (PopupArrowDirection type, QRect rect);
    void addWidget (QWidget * widget);


    void setGeometry (const QRect & rect);
    void setGeometry (int x, int y, int w, int h) ;

    void setVisible (bool visible);

private:
    int alpha() const;
    void setAlpha(const int alpha);

};

#endif // POPUPWIDGET_H
