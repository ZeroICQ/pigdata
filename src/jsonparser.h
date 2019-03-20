#pragma once

#include <QString>
#include <fstream>
#include <vector>
#include <QColor>

class JsonParser
{
public:
    explicit JsonParser(QString path);
    std::vector<std::vector<QColor>> getNextFrame();

private:
    static const int X_SIZE = 3;
    static const int Y_SIZE = 3;
    std::ifstream input_;
    long long curPos_ = 0;
    long long animationStartPos_ = 0;
};
