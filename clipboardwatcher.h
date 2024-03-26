#ifndef CLIPBOARDWATCHER_H
#define CLIPBOARDWATCHER_H

#include <QObject>
#include <QClipboard>
#include <QMimeData>
#include <QMainWindow>
#include "mainwindow.h"




class ClipboardWatcher : public QObject
{
    Q_OBJECT

public:
    explicit ClipboardWatcher(MainWindow *mainWindow, QObject *parent = nullptr);
    void setLabelText(const QString &text);

private slots:
    void onClipboardDataChanged();

private:
    QClipboard *clipboard;
    MainWindow *m_mainWindow; // Указатель на MainWindow
};

#endif // CLIPBOARDWATCHER_H
