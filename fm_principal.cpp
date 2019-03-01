#include "fm_principal.h"
#include "ui_fm_principal.h"

#include "fm_gestao_colaboradores.h"
#include "fm_gestao_estoque.h"
#include "fm_gestao_vendas.h"
#include "fm_login.h"
#include "fm_novas_vendas.h"

int fm_principal :: id_colab;
bool fm_principal :: logado;
QString fm_principal :: nome_colab;
QString fm_principal :: username_colab;
QString fm_principal :: acesso_colab;

fm_principal::fm_principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fm_principal)
{
    ui->setupUi(this);

    logado = false;

        aberto.addFile(":/Icones - Copia/cadeado_aberto.jpg");
        fechado.addFile(":/Icones - Copia/cadeado_fechado.jpg");

        ui -> pushButton -> setText("");
        ui -> pushButton -> setIcon(fechado);
        ui -> statusBar -> addWidget(ui -> pushButton);
        ui -> statusBar -> addWidget(ui -> label);

}

fm_principal::~fm_principal()
{
    delete ui;
}

void fm_principal::on_pushButton_clicked()
{

    if(!logado){
        fm_login f_login;
        f_login.exec();

        if(logado){
            ui -> pushButton -> setIcon(aberto);
            ui -> label -> setText(nome_colab);
        }
    }else{
        logado = false;
        ui -> label -> setText("Sem colaborador");
        ui -> pushButton -> setIcon(fechado);

        }
}

void fm_principal::on_actionSair_triggered()
{
    close();
}

void fm_principal::on_pushButton_2_clicked()
{
    if(logado){
    fm_novas_vendas f_novas_vendas;
    f_novas_vendas.exec();
    }else{
        QMessageBox :: critical (this, "Erro", "Acesso negado");
    }
}

void fm_principal::on_actionEstoque_triggered()
{
   if(logado){
       if(acesso_colab == "A") {
            fm_gestao_estoque f_gestao_estoque;
            f_gestao_estoque.exec();
        }else{
            QMessageBox :: critical (this, "Erro", "Acesso negado");
        }
   }else{
       QMessageBox :: critical (this, "Erro", "Acesso negado");
   }

}

void fm_principal::on_actionVendas_triggered()
{
    if(logado){
        if(acesso_colab == "A"){
            fm_gestao_vendas f_gestao_vendas;
            f_gestao_vendas.exec();
        }else {
            QMessageBox :: critical (this, "Erro", "Acesso negado");
        }
    }else{
        QMessageBox :: critical (this, "Erro", "Acesso negado");
    }
}

void fm_principal::on_actionColaboradores_triggered()
{
   if(logado){
       if(acesso_colab == "A"){
            fm_gestao_colaboradores f_gestao_colaboradores;
            f_gestao_colaboradores.exec();
        }else{
            QMessageBox :: critical (this, "Erro", "Acesso negado");
        }
   }else{
       QMessageBox :: critical (this, "Erro", "Acesso negado");
   }
}

