#include "clipboardwatcher.h"
#include <QGuiApplication>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

ClipboardWatcher::ClipboardWatcher(MainWindow *mainWindow, QObject *parent) :
    QObject(parent),
    m_mainWindow(mainWindow)
{
    clipboard = QGuiApplication::clipboard();
    connect(clipboard, &QClipboard::dataChanged, this, &ClipboardWatcher::onClipboardDataChanged);
}

void ClipboardWatcher::onClipboardDataChanged() {
    const QMimeData *mimeData = clipboard->mimeData();
    if (mimeData->hasText()) {
        QPushButton *button = new QPushButton(mimeData->text());
        this->m_mainWindow->ui->ItemsList->addWidget(button);
    }
    // Добавьте другие проверки на типы данных, если нужно
}
