#include <QApplication>
#include <QClipboard>
#include <QDebug>


class ClipboardWatcher : public QObject
{
    Q_OBJECT

public:
    ClipboardWatcher(QObject *parent = nullptr) : QObject(parent)
    {
        clipboard = QApplication::clipboard();
        connect(clipboard, &QClipboard::dataChanged, this, &ClipboardWatcher::onClipboardDataChanged);
    }

private slots:
    void onClipboardDataChanged()
    {
        qDebug() << "Clipboard data changed:";
        const QMimeData *mimeData = clipboard->mimeData();
        // Добавьте другие проверки на типы данных, если нужно
    }

private:
    QClipboard *clipboard;
};
