
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functions.h"
#include<QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("ensah_library");
    db.setUserName("root");
    db.setPassword("");

    if(!db.open()) {
        QMessageBox::information(this,"Database Connection","Database Not Connected");
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM account WHERE login = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.exec();

    if(query.next()) {
        hide();
        HomeDialog HomeDialog;
        HomeDialog.setModal(true);
        HomeDialog.exec();
    } else {
        ui->label_login_error->setText(QString("Incorrect username or password"));
    }

    db.close();
}

