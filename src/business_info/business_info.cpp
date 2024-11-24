#include "business_info.h"
#include "ui_business_info.h"
#include <QMessageBox>

BusinessInfo::BusinessInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BusinessInfo)
{
    ui->setupUi(this); // Set up the UI from the .ui file

    // Connect the Save button to its slot
    connect(ui->saveButton, &QPushButton::clicked, this, &BusinessInfo::onSaveButtonClicked);
}

BusinessInfo::~BusinessInfo()
{
    delete ui; // Clean up the UI
}

void BusinessInfo::onSaveButtonClicked()
{
    // Retrieve the entered business information
    QString businessName = ui->lineEditBusinessName->text();
    QString businessAddress = ui->lineEditBusinessAddress->text();
    QString businessContact = ui->lineEditBusinessContact->text();

    // Validate the inputs (example)
    if (businessName.isEmpty() || businessAddress.isEmpty() || businessContact.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields must be filled out.");
        return;
    }

    // Logic to save the business info (e.g., save to database or settings file)
    // For now, just show a confirmation message
    QMessageBox::information(this, "Success", "Business information saved successfully.");
    
    // Optionally, clear the fields after saving
    ui->lineEditBusinessName->clear();
    ui->lineEditBusinessAddress->clear();
    ui->lineEditBusinessContact->clear();
}
