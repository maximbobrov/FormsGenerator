

#include <QApplication>
#include <QFile>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QStringList paths = QCoreApplication::libraryPaths();
    paths.append(".");
    paths.append("imageformats");
    paths.append("platforms");
    paths.append("sqldrivers");
    paths.append("printsupport");
    QCoreApplication::setLibraryPaths(paths);

    QApplication app(argc, argv);

    QFile file(":/qss/default.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    qApp->setStyleSheet(styleSheet);

    MainWindow mainWindow;
    mainWindow.showMaximized();

    return app.exec();
}
