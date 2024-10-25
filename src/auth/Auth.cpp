#include "Auth.h"
#include <QMessageBox>

Auth::Auth(QWidget *parent) : QWidget(parent) {
    emailInput = new QLineEdit(this);
    passwordInput = new QLineEdit(this);
    loginButton = new QPushButton("Login", this);

    connect(loginButton, &QPushButton::clicked, this, &Auth::handleLogin);

    // Layout the UI components here...
}

void Auth::handleLogin() {
    QString email = emailInput->text();
    QString password = passwordInput->text();

    // Firebase login logic here
    // If successful:
    QMessageBox::information(this, "Login", "Login successful");
    // Open the main dashboard here

    // If failed:
    QMessageBox::warning(this, "Login", "Login failed. Check your credentials.");
}
