#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //设置皮肤
    QFile styleSheet(":/qss/styles.qss");
    if (!styleSheet.open(QIODevice::ReadOnly)) {
        qWarning("Can't open the style sheet file.");
        return NULL;
    }
    qApp->setStyleSheet(styleSheet.readAll());

    MainWindow w;
    w.show();

    return a.exec();
}
