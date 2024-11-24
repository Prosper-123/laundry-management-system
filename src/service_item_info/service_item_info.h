#ifndef SERVICE_ITEM_INFO_H
#define SERVICE_ITEM_INFO_H

#include <QWidget>
#include <QTableWidget>
#include <QMessageBox>
#include <QString>
#include <QInputDialog>

namespace Ui {
class ServiceItemInfo;
}

class ServiceItemInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ServiceItemInfo(QWidget *parent = nullptr);
    ~ServiceItemInfo();

private slots:
    void onAddItemButtonClicked();
    void onRemoveItemButtonClicked();
    void onUpdateItemButtonClicked();

private:
    Ui::ServiceItemInfo *ui;

    void addItem(const QString &itemName, const QString &price, const QString &description);
    void removeItem();
    void updateItem();
};

#endif // SERVICE_ITEM_INFO_H
