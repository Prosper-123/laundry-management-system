#ifndef BUSINESSINFO_H
#define BUSINESSINFO_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class BusinessInfo;
}

class BusinessInfo : public QWidget
{
    Q_OBJECT

public:
    explicit BusinessInfo(QWidget *parent = nullptr);
    ~BusinessInfo();

private slots:
    void onSaveButtonClicked();

private:
    Ui::BusinessInfo *ui;
};

#endif // BUSINESSINFO_H
