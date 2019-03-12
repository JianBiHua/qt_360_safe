#include "focuswidget.h"
#include <qdebug.h>

FocusWidget::FocusWidget(QWidget *parent) : QPushButton(parent)
{
}

void FocusWidget::focusOutEvent ( QFocusEvent * event )
{
    qDebug () << "focusOutEvent";
}

void FocusWidget::focusInEvent ( QFocusEvent * event )  {
    qDebug () << "focusInEvent";
}
