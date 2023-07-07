
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QSqlDatabase>

QSqlDatabase dbConnect() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("ensah_library");
    db.setUserName("root");
    db.setPassword("");

    if(!db.open()) {
        QMessageBox::information(nullptr,"Database Connection","Database Not Connected");
    } else {
        return db;
    }
}


#endif // FUNCTIONS_H
