#ifndef USER_INFO_H
#define USER_INFO_H

#include <QWidget>
#include <QTableWidget>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>

namespace Ui {
class UserInfo;
}

class UserInfo : public QWidget
{
    Q_OBJECT

public:
    explicit UserInfo(QWidget *parent = nullptr);
    ~UserInfo();

private slots:
    void onAddUserButtonClicked();
    void onRemoveUserButtonClicked();
    void onUpdateUserButtonClicked();

private:
    Ui::UserInfo *ui;

    void addUser(const QString &userName, const QString &email, const QString &role);
    void removeUser();
    void updateUser();
};

#endif // USER_INFO_H
