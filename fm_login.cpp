#include "fm_login.h"
#include "ui_fm_login.h"

#include "fm_principal.h"

fm_login::fm_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_login)
{
    ui->setupUi(this);
    logado = false;

}

fm_login::~fm_login()
{
    delete ui;
}

void fm_login::on_pushButton_2_clicked()
{
    logado = false;
    close();
}

void fm_login::on_pushButton_clicked()
{
    if(con.abrir()){

        QString username = ui -> lineEdit -> text();
        QString senha = ui -> lineEdit_2 -> text();

        QSqlQuery query("select * from tb_colaboradores where username_colab = '"+username+"' and senha_colab = '"+senha+"'");

        if(!query.exec()){
            QMessageBox :: critical (this, "Login", "Erro ao tentar executar Query");

        }else{
            query.first();
            if(query.value(1).toString() != ""){
                QMessageBox :: information (this, "Login", "Login efetuado com sucesso\nBem vindo ao Estoque!");
                fm_principal :: logado = true;
                fm_principal :: id_colab = query.value(0).toInt();
                fm_principal :: nome_colab = query.value(1).toString();;
                fm_principal :: acesso_colab = query.value(3).toString();;

                con.fechar();
                close();
            }else{
                QMessageBox :: critical (this, "Erro", "Colaborador não encontrado");
                ui -> lineEdit -> clear();
                ui -> lineEdit_2 -> clear();
                ui -> lineEdit -> setFocus();
            }
        }
    }else{
        QMessageBox :: critical (this, "Erro", "Erro ao tentar abrir o Database");
    }

    con.fechar();
}

