#include <QApplication>
#include "auth.h"  // Including the Auth class, replace with MainWindow if needed

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create an authentication screen or a main window
    Auth authWindow;  // or MainWindow if you're starting with a main window
    authWindow.show();  // Display the window

    return a.exec();  // Start the application event loop
}
