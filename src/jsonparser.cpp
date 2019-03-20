#include "jsonparser.h"
#include <ios>

JsonParser::JsonParser(QString path) : input_(path.toStdString(), std::ios::in)
{
    char c;
    input_ >> c >> c; //skip [[
    auto b = input_.peek();
    curPos_ = input_.tellg();
    animationStartPos_ = curPos_;
    auto a = input_.peek();
}

std::vector<std::vector<QColor> > JsonParser::getNextFrame()
{
    if (input_.eof() || input_.peek() == ']') {
        input_.clear();
        input_.seekg(animationStartPos_);
    }

    char tmp;
    int r,g,b;
    std::vector<std::vector<QColor>> result;
    result.reserve(Y_SIZE);

    for (auto y = 0; y < Y_SIZE; y++) {
        result.emplace_back();
        for (auto x = 0; x < X_SIZE; x++) {

            input_ >> tmp //[
                   >> r
                   >> tmp //,
                   >> g
                   >> tmp //,
                   >> b
                   >> tmp >> tmp; //,]

            curPos_ = input_.tellg();
            //todo: replace with emplace back
            result[y].push_back(QColor(r,g,b));
        }


    }

    input_ >> tmp; // ]
    if (input_.peek() == ',')
        input_>> tmp; // ,
    return result;
}
