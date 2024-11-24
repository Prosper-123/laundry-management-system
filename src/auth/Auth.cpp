#include "auth.h"
#include "ui_auth.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QDebug>

Auth::Auth(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Auth)
{
    ui->setupUi(this);

    // Set up UI elements
    usernameField = ui->usernameField;
    passwordField = ui->passwordField;
    loginButton = ui->loginButton;
    statusLabel = ui->statusLabel;

    // Connect login button click to the function
    connect(loginButton, &QPushButton::clicked, this, &Auth::onLoginButtonClicked);

    // Set placeholder texts
    usernameField->setPlaceholderText("Enter Username");
    passwordField->setPlaceholderText("Enter Password");
    passwordField->setEchoMode(QLineEdit::Password);  // Mask the password field

    // Optional: Set up validators for username and password
    QRegularExpressionValidator *usernameValidator = new QRegularExpressionValidator(QRegularExpression("[A-Za-z0-9_]+"), this);
    usernameField->setValidator(usernameValidator);
}

Auth::~Auth()
{
    delete ui;
}

void Auth::onLoginButtonClicked()
{
    QString username = usernameField->text();
    QString password = passwordField->text();

    if (username.isEmpty() || password.isEmpty()) {
        statusLabel->setText("Please enter both username and password.");
        return;
    }

    // For demonstration purposes: hardcoded login check
    if (username == "admin" && password == "password123") {
        statusLabel->setText("Login successful.");
        // Redirect to the Dashboard (or next steps in your app)
        // You can emit a signal or call a method to open the Dashboard window here.
        qDebug() << "Login successful, proceeding to the dashboard...";
        // You may want to use actual Firebase Authentication logic here
    } else {
        statusLabel->setText("Invalid username or password.");
    }
}
