#include "jsonimagemodel.h"

JsonImageModel::JsonImageModel(QObject *parent) : QObject(parent)
{

}

void JsonImageModel::setFilePath(QString filePath) {
    filePath_ = filePath;
    parser_ = std::make_shared<JsonParser>(filePath_);
}

std::vector<std::vector<QColor> > JsonImageModel::getNextFrame()
{
    return parser_->getNextFrame();
}
