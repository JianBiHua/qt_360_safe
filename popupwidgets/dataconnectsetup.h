#ifndef DATACONNECTSETUP_H
#define DATACONNECTSETUP_H

#include <QWidget>

namespace Ui {
class DataConnectSetup;
}

class DataConnectSetup : public QWidget
{
    Q_OBJECT

public:
    explicit DataConnectSetup(QWidget *parent = 0);
    ~DataConnectSetup();

private:
    Ui::DataConnectSetup *ui;

protected:
    void mousePressEvent(QMouseEvent *e);
};

#endif // DATACONNECTSETUP_H
