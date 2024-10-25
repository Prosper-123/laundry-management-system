#ifndef AUTH_H
#define AUTH_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class Auth : public QWidget {
    Q_OBJECT

public:
    Auth(QWidget *parent = nullptr);

private slots:
    void handleLogin();

private:
    QLineEdit *emailInput;
    QLineEdit *passwordInput;
    QPushButton *loginButton;
};

#endif
