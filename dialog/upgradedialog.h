#ifndef UPGRADEDIALOG_H
#define UPGRADEDIALOG_H

#include <QDialog>

namespace Ui {
class UpgradeDialog;
}

class UpgradeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UpgradeDialog(QWidget *parent = 0);
    ~UpgradeDialog();

private slots:
    void on_close_clicked();

    void on_pushButton_clicked();

    void openUrl(QString url);

private:
    Ui::UpgradeDialog *ui;
};

#endif // UPGRADEDIALOG_H
