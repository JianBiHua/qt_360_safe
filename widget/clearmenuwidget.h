#ifndef CLEARMENUWIDGET_H
#define CLEARMENUWIDGET_H

#include <QWidget>

namespace Ui {
class ClearMenuWidget;
}

class ClearMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClearMenuWidget(QWidget *parent = 0);
    ~ClearMenuWidget();

private:
    Ui::ClearMenuWidget *ui;
};

#endif // CLEARMENUWIDGET_H
