#include "jsonimageprovider.h"

JsonImageProvider::JsonImageProvider(std::shared_ptr<JsonImageModel> imageModel)
    : QQuickImageProvider(QQuickImageProvider::Image), imageModel_(imageModel)
{

}

QImage JsonImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{

   QImage img(imageModel_->getWidth(), imageModel_->getHeight(), QImage::Format::Format_RGB32);
   int i = 0,j = 0;
   for (const auto& y : imageModel_->getNextFrame()) {
       j = 0;
       for(const auto& color : y) {
           img.setPixelColor(i,j++, color);
       }
       i++;
   }
   return img;
}
