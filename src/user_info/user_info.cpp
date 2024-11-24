#include "user_info.h"
#include "ui_user_info.h"

UserInfo::UserInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserInfo)
{
    ui->setupUi(this);

    // Connect button signals to slots
    connect(ui->buttonAddUser, &QPushButton::clicked, this, &UserInfo::onAddUserButtonClicked);
    connect(ui->buttonRemoveUser, &QPushButton::clicked, this, &UserInfo::onRemoveUserButtonClicked);
    connect(ui->buttonUpdateUser, &QPushButton::clicked, this, &UserInfo::onUpdateUserButtonClicked);
}

UserInfo::~UserInfo()
{
    delete ui;
}

void UserInfo::onAddUserButtonClicked()
{
    QString userName = QInputDialog::getText(this, "Add User", "Enter User Name:");
    if (userName.isEmpty()) return;

    QString email = QInputDialog::getText(this, "Add User", "Enter Email:");
    if (email.isEmpty()) return;

    QString role = QInputDialog::getText(this, "Add User", "Enter Role (Admin/Assistant):");
    if (role.isEmpty()) return;

    addUser(userName, email, role);
}

void UserInfo::onRemoveUserButtonClicked()
{
    removeUser();
}

void UserInfo::onUpdateUserButtonClicked()
{
    updateUser();
}

void UserInfo::addUser(const QString &userName, const QString &email, const QString &role)
{
    int rowCount = ui->tableWidgetUsers->rowCount();
    ui->tableWidgetUsers->insertRow(rowCount);

    ui->tableWidgetUsers->setItem(rowCount, 0, new QTableWidgetItem(userName));
    ui->tableWidgetUsers->setItem(rowCount, 1, new QTableWidgetItem(email));
    ui->tableWidgetUsers->setItem(rowCount, 2, new QTableWidgetItem(role));
}

void UserInfo::removeUser()
{
    int currentRow = ui->tableWidgetUsers->currentRow();
    if (currentRow >= 0) {
        ui->tableWidgetUsers->removeRow(currentRow);
        QMessageBox::information(this, "Success", "User removed successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Please select a user to remove.");
    }
}

void UserInfo::updateUser()
{
    int currentRow = ui->tableWidgetUsers->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Error", "Please select a user to update.");
        return;
    }

    QString newUserName = QInputDialog::getText(this, "Update User", "Enter New User Name:");
    if (!newUserName.isEmpty())
        ui->tableWidgetUsers->item(currentRow, 0)->setText(newUserName);

    QString newEmail = QInputDialog::getText(this, "Update User", "Enter New Email:");
    if (!newEmail.isEmpty())
        ui->tableWidgetUsers->item(currentRow, 1)->setText(newEmail);

    QString newRole = QInputDialog::getText(this, "Update User", "Enter New Role (Admin/Assistant):");
    if (!newRole.isEmpty())
        ui->tableWidgetUsers->item(currentRow, 2)->setText(newRole);
}
