#ifndef MARKET360DIALOG_H
#define MARKET360DIALOG_H

#include <QDialog>
#include <QToolButton>
#include <QtWebEngineWidgets>

namespace Ui {
class Market360Dialog;
}

class Market360Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Market360Dialog(QWidget *parent = 0);
    ~Market360Dialog();

private slots:

    void on_close_clicked();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_5_clicked();

private:
    Ui::Market360Dialog *ui;
    QWebEngineView * webview;

private:
    void optionToolButtons ();
    void optionToolButton (QToolButton * tb,
                                        QIcon icon,
                                        QString text,
                                        QSize size,
                                        QString property) ;
    void setTabBarIndex (int index);
    void createWebView (QString url) ;
};

#endif // MARKET360DIALOG_H
