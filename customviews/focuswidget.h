#ifndef FOCUSWIDGET_H
#define FOCUSWIDGET_H

#include <QWidget>
#include <QFocusEvent>
#include <QPushButton>

class FocusWidget : public QPushButton
{
    Q_OBJECT
public:
    explicit FocusWidget(QWidget *parent = 0);

signals:

public slots:

protected:
    void focusOutEvent ( QFocusEvent * event );
    void focusInEvent ( QFocusEvent * event ) ;
};

#endif // FOCUSWIDGET_H
