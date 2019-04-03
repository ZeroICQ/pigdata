#pragma once

#include <QObject>
#include <vector>
#include <memory>
#include <jsonparser.h>


class JsonImageModel : public QObject
{
    Q_OBJECT
public:
    explicit JsonImageModel(QObject *parent = nullptr);
    Q_PROPERTY(QString filePath MEMBER filePath_ WRITE setFilePath)

    void setFilePath(QString filePath);

    std::vector<std::vector<QColor>> getNextFrame();
    int getWidth() { return  parser_->imgWidth; }
    int getHeight() { return parser_->imgHeight; }

private:
    QString filePath_;
    std::shared_ptr<JsonParser> parser_;

    void loadFirstFrame();

signals:

public slots:
};
