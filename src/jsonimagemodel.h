#pragma once

#include <QObject>

class JsonImageModel : public QObject
{
    Q_OBJECT
public:
    explicit JsonImageModel(QObject *parent = nullptr);
    Q_PROPERTY(QString filePath MEMBER filePath_ READ getFilePath WRITE setFilePath)

    void setFilePath(QString filePath) { filePath_ = filePath; }
    QString getFilePath() { return filePath_; }

private:
    QString filePath_;

signals:

public slots:
};
