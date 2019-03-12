#include "statewidget.h"
#include "ui_statewidget.h"

StateWidget::StateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StateWidget)
{
    ui->setupUi(this);

    ui->title->setStyleSheet ("color: #676767");
    ui->title->setAlignment (Qt::AlignCenter);
}

StateWidget::~StateWidget()
{
    delete ui;
}

int StateWidget::getState () {
    return mState;
}

void StateWidget::show (QString icon, QString txt, int state) {
    ui->title->setText (txt);
    ui->icon->setStyleSheet (QString("border-image: url(%1)").arg (icon));
    setState (state);
}

void StateWidget::setState (int state) {
    mState = state;
    if (0==state) {
        ui->state->setStyleSheet (QString("border-image: url(:/other/images/other/icon_waring.png)"));
    } else {
        ui->state->setStyleSheet (QString("border-image: url(:/other/images/other/icon_right.png)"));
    }
}

void StateWidget::enterEvent(QEvent *event) {
    emit onStateWidgetHoverSinal(this);
}

void StateWidget::leaveEvent(QEvent * event) {
    emit onStateWidgetNoHoverSinal (this);
}
