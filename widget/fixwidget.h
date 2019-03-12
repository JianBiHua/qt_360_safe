#ifndef FIXWIDGET_H
#define FIXWIDGET_H

#include <QWidget>
#include <QToolButton>
#include "fix2widget.h"

namespace Ui {
class FixWidget;
}

class FixWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FixWidget(QWidget *parent = 0);
    ~FixWidget();

private:
    Ui::FixWidget *ui;
    Fix2Widget * fix2Widget;

private slots:
    void on_pushButton_clicked();

    void onFix2IntoNextSlot();

private:
    void optionToolButtons ();
    void optionToolButton (QToolButton * tb,
                                        QIcon icon,
                                        QString text,
                                        QSize size,
                                        QString property);
};

#endif // FIXWIDGET_H
