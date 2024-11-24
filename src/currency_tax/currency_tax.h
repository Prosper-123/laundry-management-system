#ifndef CURRENCYTAX_H
#define CURRENCYTAX_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class CurrencyTax;
}

class CurrencyTax : public QWidget
{
    Q_OBJECT

public:
    explicit CurrencyTax(QWidget *parent = nullptr);
    ~CurrencyTax();

private slots:
    void onSaveButtonClicked();

private:
    Ui::CurrencyTax *ui;
};

#endif // CURRENCYTAX_H
