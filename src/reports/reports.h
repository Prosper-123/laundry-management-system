#ifndef REPORTS_H
#define REPORTS_H

#include <QWidget>
#include <QTableWidget>
#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include <QMessageBox>

namespace Ui {
class Reports;
}

class Reports : public QWidget
{
    Q_OBJECT

public:
    explicit Reports(QWidget *parent = nullptr);
    ~Reports();

private slots:
    void onLoadReportsButtonClicked();
    void onExportReportsButtonClicked();

private:
    Ui::Reports *ui;

    void loadDummyData(); // Method to load mock data for reports
    void exportToCSV();   // Method to export table data to a CSV file
};

#endif // REPORTS_H
