#include "jsonparser.h"
#include <ios>

JsonParser::JsonParser(QString path) : input_(path.toStdString(), std::ios::in|std::ios::binary)
{
    input_.exceptions( std::ifstream::failbit | std::ifstream::badbit);
}

void JsonParser::parseMeta()
{
    char tmpChar;
    std::string tmpStr;
    input_.seekg(0, std::ios::beg);

    input_ >> tmpChar   // {
           >> tmpStr    // "width":
           >> imgWidth
           >> tmpChar   // ,
           >> tmpStr    // "height":
           >> imgHeight
           >> tmpChar   //,
           >> tmpStr    // "frames":
           >> frames;

    input_ >> tmpChar >> tmpStr >> tmpChar >> tmpChar; // skip "animation"

//    char c;
//    input_ >> c >> c; //skip [[
//    auto b = input_.peek();
//    curPos_ = ;
    animationStartPos_ = input_.tellg();
    isMetaParsed_ = true;
}

JsonParser::Pixels JsonParser::parseAnimation()
{
//    if (input_.eof() || input_.peek() == '}') {
    if (curFrame == frames) {
        input_.clear();
        input_.seekg(animationStartPos_);
        curFrame = 0;
    }
    curFrame++;

    char tmp;
    int r,g,b;
    std::vector<std::vector<QColor>> result;
    result.reserve(imgHeight);

    for (auto x = 0; x < imgWidth; x++) {
        result.emplace_back();
        for (auto y = 0; y < imgHeight; y++) {

            input_ >> tmp //[
                   >> r
                   >> tmp //,
                   >> g
                   >> tmp //,
                   >> b
                   >> tmp; //]

            input_ >> tmp;
            if (tmp != ',') {
                input_.putback(tmp);
            }

            curPos_ = input_.tellg();
            //todo: replace with emplace back
            result[x].push_back(QColor(r,g,b));
        }
    }

    input_ >> tmp >> tmp >> tmp;
    return result;
}

std::vector<std::vector<QColor> > JsonParser::getNextFrame()
{
    if (!isMetaParsed_)
        parseMeta();
    return parseAnimation();
}
