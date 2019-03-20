#pragma once

#include <QObject>
#include <QQuickImageProvider>

class JsonImageProvider : public QQuickImageProvider
{
public:
    explicit JsonImageProvider();

    ~JsonImageProvider() {}

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);

private:


signals:

public slots:
};
