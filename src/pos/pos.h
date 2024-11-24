#ifndef POS_H
#define POS_H

#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class POS;
}

class POS : public QWidget
{
    Q_OBJECT

public:
    explicit POS(QWidget *parent = nullptr);
    ~POS();

private slots:
    void onAddItemButtonClicked();
    void onCompleteSaleButtonClicked();

private:
    Ui::POS *ui;
    void updateTotal();
};

#endif // POS_H
