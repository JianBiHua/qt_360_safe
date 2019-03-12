#include "actionswidget.h"
#include "ui_actionswidget.h"

ActionsWidget::ActionsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActionsWidget)
{
    ui->setupUi(this);
}

ActionsWidget::~ActionsWidget()
{
    delete ui;
}
