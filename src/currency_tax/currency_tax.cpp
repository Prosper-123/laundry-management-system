#include "currency_tax.h"
#include "ui_currency_tax.h"
#include <QMessageBox>

CurrencyTax::CurrencyTax(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CurrencyTax)
{
    ui->setupUi(this);

    // Connect Save button to its slot
    connect(ui->saveButton, &QPushButton::clicked, this, &CurrencyTax::onSaveButtonClicked);
}

CurrencyTax::~CurrencyTax()
{
    delete ui;
}

void CurrencyTax::onSaveButtonClicked()
{
    // Get data from the input fields
    QString currencySymbol = ui->lineEditCurrencySymbol->text();
    QString exchangeRate = ui->lineEditExchangeRate->text();
    QString taxRate = ui->lineEditTaxRate->text();

    // Validate the input
    if (currencySymbol.isEmpty() || exchangeRate.isEmpty() || taxRate.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields must be filled out.");
        return;
    }

    // Check if the exchange rate and tax rate are numeric
    bool isExchangeRateNumeric, isTaxRateNumeric;
    double exchangeRateValue = exchangeRate.toDouble(&isExchangeRateNumeric);
    double taxRateValue = taxRate.toDouble(&isTaxRateNumeric);

    if (!isExchangeRateNumeric || !isTaxRateNumeric) {
        QMessageBox::warning(this, "Input Error", "Exchange rate and tax percentage must be numeric.");
        return;
    }

    // Example: Save or update currency and tax settings
    QMessageBox::information(this, "Success", "Currency and Tax settings saved successfully!");

    // Optionally, clear fields after saving
    ui->lineEditCurrencySymbol->clear();
    ui->lineEditExchangeRate->clear();
    ui->lineEditTaxRate->clear();
}
