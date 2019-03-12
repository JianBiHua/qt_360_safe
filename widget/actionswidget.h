#ifndef ACTIONSWIDGET_H
#define ACTIONSWIDGET_H

#include <QWidget>

namespace Ui {
class ActionsWidget;
}

class ActionsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ActionsWidget(QWidget *parent = 0);
    ~ActionsWidget();

private:
    Ui::ActionsWidget *ui;
};

#endif // ACTIONSWIDGET_H
