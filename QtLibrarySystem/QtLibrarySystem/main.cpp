#include "QtLibrarySystem.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	LibrarySystem::UI::QtLibrarySystem w;
    w.show();
    return a.exec();
}
