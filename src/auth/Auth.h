#ifndef AUTH_H
#define AUTH_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>

namespace Ui {
class Auth;
}

class Auth : public QWidget
{
    Q_OBJECT

public:
    explicit Auth(QWidget *parent = nullptr);
    ~Auth();

private slots:
    void onLoginButtonClicked();

private:
    Ui::Auth *ui;
    QLineEdit *usernameField;
    QLineEdit *passwordField;
    QPushButton *loginButton;
    QLabel *statusLabel;
};

#endif // AUTH_H
