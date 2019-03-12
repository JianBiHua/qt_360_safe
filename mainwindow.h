#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QMenu>
#include <QStackedWidget>
#include "customviews/hoverpushbutton.h"
#include "customviews/statewidget.h"
#include "popupwidgets/popupwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_close_clicked();

    void on_min_clicked();

    void on_tbHome_clicked();

    void on_tbHorse_clicked();

    void on_tbClear_clicked();

    void on_tbFix_clicked();

    void on_tbYouhua_clicked();

    void on_tbActions_clicked();

    void on_tbMarket_clicked();

    void on_tbApp_clicked();

    void on_menu_clicked();

    void shezhiActionSlot();

    void jianchagengxinActionSlot();

    void qiehuanActionSlot();

    void wentifankuiActionSlot();

    void luntanActionSlot();

    void wangzhanActionSlot();

    void yinsiActionSlot();

    void mianfeiActionSlot();

    void guanyuActionSlot();

    void onHoverPushButtonHoverSlot(HoverPushButton*pb) ;

    void onHoverPushButtonNoHoverSlot(HoverPushButton*pb);

    void onMouseEnterPopupWidgetSlot(PopupWidget* widget);

    void onMouseLeavePopupWidgetSlot(PopupWidget* widget);

private:
    Ui::MainWindow *ui;
    QMenu * contextmenu;
    QStackedWidget * stackedWidget;
    QPoint relativePos;
    PopupWidget * loginPopupWidget;

private:
    void optionTopBtns ();
    void optionToolButton (QToolButton * tb, QIcon icon, QString text);
    void optionToolButtons ();

    void setTabBarIndex (int index);
    void updateStyle (QWidget * w);

    void createContextMenu ();
    void showContextMenu ();

    void showStackedWidget ();

    void showLoginPopupWidget ();
    void hideLoginPopupWidget ();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

};

#endif // MAINWINDOW_H
