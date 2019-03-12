#ifndef CLEARWIDGET_H
#define CLEARWIDGET_H

#include <QWidget>
#include <QToolButton>
#include "clear2widget.h"
#include "popupwidgets/popupwidget.h"
#include "widget/clearmenuwidget.h"
#include "customviews/hovertoolbutton.h"

namespace Ui {
class ClearWidget;
}

class ClearWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClearWidget(QWidget *parent = 0);
    ~ClearWidget();

private slots:
    void on_pushButton_clicked();

    void onClear2IntoNextSlot ();

    void onHoverToolButtonHoverSlot(HoverToolButton*pb);

    void onHoverToolButtonNoHoverSlot(HoverToolButton*pb);

    void onMouseEnterPopupWidgetSlot(PopupWidget* widget);

    void onMouseLeavePopupWidgetSlot(PopupWidget* widget);

private:
    Ui::ClearWidget *ui;
    Clear2Widget * clear2Widget;
    PopupWidget * clearMenuWidget;

private:
    void optionToolButtons ();
    void optionToolButton (QToolButton * tb,
                                        QIcon icon,
                                        QString text,
                                        QSize size,
                                        QString property);

    void showClearMenuWidget () ;
    void hideClearMenuWidget ();
};

#endif // CLEARWIDGET_H
