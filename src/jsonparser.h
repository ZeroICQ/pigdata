#pragma once

#include <QString>
#include <fstream>
#include <vector>
#include <QColor>

class JsonParser
{
    using Pixels = std::vector<std::vector<QColor>>;

public:
    explicit JsonParser(QString path);
    Pixels getNextFrame();
    size_t imgWidth;
    size_t imgHeight;
    size_t frames;

private:
    std::ifstream input_;
    long long curPos_ = 0;
    long long animationStartPos_ = 0;
    bool isMetaParsed_ = false;
    // image meta


    void parseMeta();
    Pixels parseAnimation();
};
