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
    int getWidth() { return  width_; }
    int getHeight() { return height_; }

private:
    QString filePath_;
    int width_ = 3;
    int height_ = 3;
    std::shared_ptr<JsonParser> parser_;

    void loadFirstFrame();

signals:

public slots:
};
