#include "dashboard.h"
#include "ui_dashboard.h"

Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);

    // Connect buttons to respective pages
    connect(ui->btnPOS, &QPushButton::clicked, this, &Dashboard::showPOS);
    connect(ui->btnServiceItems, &QPushButton::clicked, this, &Dashboard::showServiceItems);
    connect(ui->btnReceipts, &QPushButton::clicked, this, &Dashboard::showReceipts);
    connect(ui->btnIncomeExpense, &QPushButton::clicked, this, &Dashboard::showIncomeExpense);
    connect(ui->btnReports, &QPushButton::clicked, this, &Dashboard::showReports);
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::showPOS()
{
    ui->stackedWidget->setCurrentWidget(ui->pagePOS);
}

void Dashboard::showServiceItems()
{
    ui->stackedWidget->setCurrentWidget(ui->pageServiceItems);
}

void Dashboard::showReceipts()
{
    ui->stackedWidget->setCurrentWidget(ui->pageReceipts);
}

void Dashboard::showIncomeExpense()
{
    ui->stackedWidget->setCurrentWidget(ui->pageIncomeExpense);
}

void Dashboard::showReports()
{
    ui->stackedWidget->setCurrentWidget(ui->pageReports);
}
