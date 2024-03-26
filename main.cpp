#include "mainwindow.h"
#include "clipboardwatcher.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QApplication>
#include <QClipboard>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    ClipboardWatcher watcher(&w);

    w.show();
    return a.exec();
}

