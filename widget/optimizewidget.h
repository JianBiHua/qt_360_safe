#ifndef OPTIMIZEWIDGET_H
#define OPTIMIZEWIDGET_H

#include <QWidget>
#include <QToolButton>
#include "optimize2widget.h"

namespace Ui {
class OptimizeWidget;
}

class OptimizeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OptimizeWidget(QWidget *parent = 0);
    ~OptimizeWidget();

private slots:
    void on_pushButton_clicked();

    void onOptimize2IntoNextSlot ();

private:
    Ui::OptimizeWidget *ui;
    Optimize2Widget * optimize2Widget;

private:
    void optionToolButtons () ;
    void optionToolButton (QToolButton * tb,
                                        QIcon icon,
                                        QString text,
                                        QSize size,
                                        QString property) ;
};

#endif // OPTIMIZEWIDGET_H
