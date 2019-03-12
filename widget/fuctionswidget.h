#ifndef FUCTIONSWIDGET_H
#define FUCTIONSWIDGET_H

#include <QWidget>
#include <QVector>
#include <QListWidgetItem>
#include <QScrollArea>

namespace Ui {
class FuctionsWidget;
}

class FunctionsItem : public QObject {
    Q_OBJECT
public:
    explicit FunctionsItem(QWidget *parent = 0, QString i="", QString hi="", QString n="", int t=0):
        icon(i), iconH(hi), name(n), type(t){

    }

    QString icon;
    QString iconH;
    QString name;
    int type;  //
};

class FuctionsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FuctionsWidget(QWidget *parent = 0);
    ~FuctionsWidget();

private:
    Ui::FuctionsWidget *ui;
    QVector<FunctionsItem *> functionList;
    int mOldIndex ;
    QScrollArea * scrollArea;

private:
    void optionListWidget ();
    void optoinScrollView ();

private slots:
    void onListwidgetClicked(QListWidgetItem*item);
};

#endif // FUCTIONSWIDGET_H
