#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>
#include "jsonimageprovider.h"
#include "jsonimagemodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    auto imageModel = std::make_shared<JsonImageModel>();

    engine.addImageProvider(QLatin1String("fromjson"), new JsonImageProvider(imageModel));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

//    engine.rootObjects()[0]->setProperty("heh", QString("mda"));
    QQmlContext* ctx = engine.rootContext();;

    ctx->setContextProperty("jsonImageModel", imageModel.get());

    return app.exec();
}
