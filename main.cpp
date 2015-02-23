#include "common.h"
#include "settings.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("unixod");
    QCoreApplication::setApplicationName("app");

    QFile cfgDefaults(":/default.cfg");
    cfgDefaults.open(QIODevice::ReadOnly);
    Settings::setDefaults(cfgDefaults.readAll());

    Common w;
    w.work();

    return a.exec();
}
