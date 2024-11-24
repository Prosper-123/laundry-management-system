#include "reports.h"
#include "ui_reports.h"
#include <QFileDialog>

Reports::Reports(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reports)
{
    ui->setupUi(this);

    // Connect button signals to slots
    connect(ui->buttonLoadReports, &QPushButton::clicked, this, &Reports::onLoadReportsButtonClicked);
    connect(ui->buttonExportReports, &QPushButton::clicked, this, &Reports::onExportReportsButtonClicked);
}

Reports::~Reports()
{
    delete ui;
}

void Reports::onLoadReportsButtonClicked()
{
    loadDummyData(); // Call method to load mock data
}

void Reports::onExportReportsButtonClicked()
{
    exportToCSV(); // Call method to export data to CSV
}

void Reports::loadDummyData()
{
    // Example mock data
    ui->tableWidgetReports->setRowCount(5);

    ui->tableWidgetReports->setItem(0, 0, new QTableWidgetItem("2024-11-12"));
    ui->tableWidgetReports->setItem(0, 1, new QTableWidgetItem("Sale"));
    ui->tableWidgetReports->setItem(0, 2, new QTableWidgetItem("$50.00"));
    ui->tableWidgetReports->setItem(0, 3, new QTableWidgetItem("Laundry Service"));

    ui->tableWidgetReports->setItem(1, 0, new QTableWidgetItem("2024-11-11"));
    ui->tableWidgetReports->setItem(1, 1, new QTableWidgetItem("Expense"));
    ui->tableWidgetReports->setItem(1, 2, new QTableWidgetItem("$20.00"));
    ui->tableWidgetReports->setItem(1, 3, new QTableWidgetItem("Cleaning Supplies"));

    // Add more rows as needed...
}

void Reports::exportToCSV()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save Reports", "", "CSV Files (*.csv)");
    if (filePath.isEmpty())
        return;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open file for writing.");
        return;
    }

    QTextStream out(&file);
    // Write headers
    out << "Date,Type,Amount,Details\n";

    // Write table data
    for (int row = 0; row < ui->tableWidgetReports->rowCount(); ++row) {
        QStringList rowData;
        for (int col = 0; col < ui->tableWidgetReports->columnCount(); ++col) {
            rowData << ui->tableWidgetReports->item(row, col)->text();
        }
        out << rowData.join(",") << "\n";
    }

    file.close();
    QMessageBox::information(this, "Export Success", "Reports exported successfully to " + filePath);
}
