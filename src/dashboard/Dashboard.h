#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>

class Dashboard : public QMainWindow {
    Q_OBJECT

public:
    Dashboard(QWidget *parent = nullptr);

private:
    // UI components for Dashboard functionalities
    void setupUi();
};

#endif
