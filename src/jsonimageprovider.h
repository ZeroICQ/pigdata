#pragma once

#include <QObject>
#include <QQuickImageProvider>
#include <memory>
#include <jsonimagemodel.h>

class JsonImageProvider : public QQuickImageProvider
{
public:
    explicit JsonImageProvider(std::shared_ptr<JsonImageModel> imageModel);

    ~JsonImageProvider() {}

    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);

private:
std::shared_ptr<JsonImageModel> imageModel_;

signals:

public slots:
};
