#ifndef FM_LOGIN_H
#define FM_LOGIN_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>

#include "fm_conexao.h"

namespace Ui {
class fm_login;
}

class fm_login : public QDialog
{
    Q_OBJECT

public:
    explicit fm_login(QWidget *parent = nullptr);
    ~fm_login();

    bool logado;
    int id;
    Conexao con;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::fm_login *ui;
};

#endif // FM_LOGIN_H
