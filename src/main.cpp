#include <QMainWindow>
#include <QApplication>
#include "../src/auth/auth.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    // lets strt with showing the auth screens first
    Auth authWindow;
    auth.show();
    return app.exec();
}