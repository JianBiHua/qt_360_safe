#include "dataconnectsetup.h"
#include "ui_dataconnectsetup.h"

DataConnectSetup::DataConnectSetup(QWidget *parent) :
    QWidget(parent, Qt::FramelessWindowHint|Qt::Popup),
    ui(new Ui::DataConnectSetup)
{
    ui->setupUi(this);
}

DataConnectSetup::~DataConnectSetup()
{
    delete ui;
}

void DataConnectSetup::mousePressEvent(QMouseEvent *e)
{
    setAttribute(Qt::WA_NoMouseReplay);
    QWidget::mousePressEvent(e);
}
