#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "jsonimageprovider.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.addImageProvider(QLatin1String("fromjson"), new JsonImageProvider);


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

//    engine.rootObjects()[0]->setProperty("heh", QString("mda"));
    QQmlContext* ctx = engine.rootContext();;
    ctx->setContextProperty("heh", QString("mda"));
    return app.exec();
}
