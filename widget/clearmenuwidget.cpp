#include "clearmenuwidget.h"
#include "ui_clearmenuwidget.h"

ClearMenuWidget::ClearMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClearMenuWidget)
{
    ui->setupUi(this);
}

ClearMenuWidget::~ClearMenuWidget()
{
    delete ui;
}
