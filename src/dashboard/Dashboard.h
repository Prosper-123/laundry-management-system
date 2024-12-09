#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>

namespace Ui {
class Dashboard;  // Forward declaration of the UI class
}

class Dashboard : public QMainWindow
{
    Q_OBJECT  // Required macro for Qt's signal and slot mechanism

public:
    // Constructor and Destructor
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

private slots:
    // Slot functions for handling button clicks and switching pages in the stacked widget
    void showPOS();
    void showServiceItems();
    void showReceipts();
    void showIncomeExpense();
    void showReports();

private:
    // Pointer to the UI class generated by the .ui file
    Ui::Dashboard *ui;
};

#endif // DASHBOARD_H
