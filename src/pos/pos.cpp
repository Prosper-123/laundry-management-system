#include "pos.h"
#include "ui_pos.h"
#include <QInputDialog>
#include <QMessageBox>

POS::POS(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::POS)
{
    ui->setupUi(this);

    // Connect button signals to slots
    connect(ui->buttonAddItem, &QPushButton::clicked, this, &POS::onAddItemButtonClicked);
    connect(ui->buttonCompleteSale, &QPushButton::clicked, this, &POS::onCompleteSaleButtonClicked);
}

POS::~POS()
{
    delete ui;
}

void POS::onAddItemButtonClicked()
{
    // Prompt user to input item details
    bool ok;
    QString itemName = QInputDialog::getText(this, "Add Item", "Enter item name:", QLineEdit::Normal, "", &ok);
    if (!ok || itemName.isEmpty()) return;

    QString itemPrice = QInputDialog::getText(this, "Add Item", "Enter item price:", QLineEdit::Normal, "", &ok);
    if (!ok || itemPrice.isEmpty()) return;

    QString itemQuantity = QInputDialog::getText(this, "Add Item", "Enter quantity:", QLineEdit::Normal, "", &ok);
    if (!ok || itemQuantity.isEmpty()) return;

    // Validate numeric inputs
    bool isPriceNumeric, isQuantityNumeric;
    double price = itemPrice.toDouble(&isPriceNumeric);
    int quantity = itemQuantity.toInt(&isQuantityNumeric);

    if (!isPriceNumeric || !isQuantityNumeric || price <= 0 || quantity <= 0) {
        QMessageBox::warning(this, "Input Error", "Price and Quantity must be positive numbers.");
        return;
    }

    // Calculate total for the item
    double total = price * quantity;

    // Add the item to the table
    int row = ui->tableWidgetItems->rowCount();
    ui->tableWidgetItems->insertRow(row);
    ui->tableWidgetItems->setItem(row, 0, new QTableWidgetItem(itemName));
    ui->tableWidgetItems->setItem(row, 1, new QTableWidgetItem(QString::number(price, 'f', 2)));
    ui->tableWidgetItems->setItem(row, 2, new QTableWidgetItem(QString::number(quantity)));
    ui->tableWidgetItems->setItem(row, 3, new QTableWidgetItem(QString::number(total, 'f', 2)));

    // Update the total
    updateTotal();
}

void POS::onCompleteSaleButtonClicked()
{
    QMessageBox::information(this, "Sale Complete", "The sale has been successfully completed!");
    ui->tableWidgetItems->clearContents();
    ui->tableWidgetItems->setRowCount(0);
    ui->lineEditTotal->clear();
}

void POS::updateTotal()
{
    double total = 0;
    for (int row = 0; row < ui->tableWidgetItems->rowCount(); ++row) {
        double rowTotal = ui->tableWidgetItems->item(row, 3)->text().toDouble();
        total += rowTotal;
    }
    ui->lineEditTotal->setText(QString::number(total, 'f', 2));
}
