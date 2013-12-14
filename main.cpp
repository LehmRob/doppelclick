#include <QApplication>

#include "doppelclick.h"

int main(int argc, char *argv[])
{
        QApplication app(argc, argv);
        Doppelclick doppelclick;
        doppelclick.show();

        return app.exec();
}
