#include "jsonimageprovider.h"

JsonImageProvider::JsonImageProvider(std::shared_ptr<JsonImageModel> imageModel)
    : QQuickImageProvider(QQuickImageProvider::Image), imageModel_(imageModel)
{

}

QImage JsonImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    QImage img(
                SCALE_FACTOR * imageModel_->getWidth(),
                SCALE_FACTOR * imageModel_->getHeight(),
                QImage::Format::Format_RGB32);

    auto nextFramePixels =  imageModel_->getNextFrame();

    for (auto y = 0; y < img.height(); y++) {
        for(auto x = 0; x < img.width(); x++) {

            img.setPixelColor(x,y, nextFramePixels[y/SCALE_FACTOR][x/SCALE_FACTOR]);
        }
    }
    return img;
}
