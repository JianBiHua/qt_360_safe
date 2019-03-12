#ifndef QUESTIONDIALOG_H
#define QUESTIONDIALOG_H

#include <QDialog>

namespace Ui {
class QuestionDialog;
}

class QuestionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QuestionDialog(QWidget *parent = 0);
    ~QuestionDialog();

private slots:
    void on_pbClose_clicked();

    void onToolButtonDidClickedSlot (bool);

    void on_nextBack_clicked();

    void on_pbLuntan_clicked();

    void on_pbMin_clicked();

private:
    Ui::QuestionDialog *ui;

private:
    void optionGridLayout () ;
    void optionToolButtons () ;
    void optionComboBox () ;
    void showHome (bool s) ;
};

#endif // QUESTIONDIALOG_H
