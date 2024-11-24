#include "service_item_info.h"
#include "ui_service_item_info.h"

ServiceItemInfo::ServiceItemInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServiceItemInfo)
{
    ui->setupUi(this);

    // Connect button signals to slots
    connect(ui->buttonAddItem, &QPushButton::clicked, this, &ServiceItemInfo::onAddItemButtonClicked);
    connect(ui->buttonRemoveItem, &QPushButton::clicked, this, &ServiceItemInfo::onRemoveItemButtonClicked);
    connect(ui->buttonUpdateItem, &QPushButton::clicked, this, &ServiceItemInfo::onUpdateItemButtonClicked);
}

ServiceItemInfo::~ServiceItemInfo()
{
    delete ui;
}

void ServiceItemInfo::onAddItemButtonClicked()
{
    QString itemName = QInputDialog::getText(this, "Add Item", "Enter Item Name:");
    if (itemName.isEmpty()) return;

    QString price = QInputDialog::getText(this, "Add Item", "Enter Price:");
    if (price.isEmpty()) return;

    QString description = QInputDialog::getText(this, "Add Item", "Enter Description:");
    if (description.isEmpty()) return;

    addItem(itemName, price, description);
}

void ServiceItemInfo::onRemoveItemButtonClicked()
{
    removeItem();
}

void ServiceItemInfo::onUpdateItemButtonClicked()
{
    updateItem();
}

void ServiceItemInfo::addItem(const QString &itemName, const QString &price, const QString &description)
{
    int rowCount = ui->tableWidgetServices->rowCount();
    ui->tableWidgetServices->insertRow(rowCount);

    ui->tableWidgetServices->setItem(rowCount, 0, new QTableWidgetItem(itemName));
    ui->tableWidgetServices->setItem(rowCount, 1, new QTableWidgetItem(price));
    ui->tableWidgetServices->setItem(rowCount, 2, new QTableWidgetItem(description));
}

void ServiceItemInfo::removeItem()
{
    int currentRow = ui->tableWidgetServices->currentRow();
    if (currentRow >= 0) {
        ui->tableWidgetServices->removeRow(currentRow);
        QMessageBox::information(this, "Success", "Item removed successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Please select an item to remove.");
    }
}

void ServiceItemInfo::updateItem()
{
    int currentRow = ui->tableWidgetServices->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Error", "Please select an item to update.");
        return;
    }

    QString newItemName = QInputDialog::getText(this, "Update Item", "Enter New Item Name:");
    if (!newItemName.isEmpty())
        ui->tableWidgetServices->item(currentRow, 0)->setText(newItemName);

    QString newPrice = QInputDialog::getText(this, "Update Item", "Enter New Price:");
    if (!newPrice.isEmpty())
        ui->tableWidgetServices->item(currentRow, 1)->setText(newPrice);

    QString newDescription = QInputDialog::getText(this, "Update Item", "Enter New Description:");
    if (!newDescription.isEmpty())
        ui->tableWidgetServices->item(currentRow, 2)->setText(newDescription);
}
