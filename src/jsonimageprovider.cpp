#include "jsonimageprovider.h"

JsonImageProvider::JsonImageProvider() : QQuickImageProvider(QQuickImageProvider::Pixmap)
{

}

QPixmap JsonImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    static Qt::GlobalColor color = Qt::GlobalColor::red;
    int width = 100;
    int height = 50;

   if (size)
      *size = QSize(width, height);

   QPixmap pixmap(requestedSize.width() > 0 ? requestedSize.width() : width,
                  requestedSize.height() > 0 ? requestedSize.height() : height);

    pixmap.fill(QColor(color).rgb());
    if (color == Qt::GlobalColor::red) {
        color = Qt::GlobalColor::blue;
    } else {
        color = Qt::GlobalColor::red;
    }
    return pixmap;
}
