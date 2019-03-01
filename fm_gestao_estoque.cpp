#include "fm_gestao_estoque.h"
#include "ui_fm_gestao_estoque.h"

#include "fm_conexao.h"

fm_gestao_estoque::fm_gestao_estoque(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_gestao_estoque)
{
    ui->setupUi(this);

    QSqlQuery query;

    if(!con.abrir()){
        QMessageBox :: critical (this, "Erro", "Erro ao abrir o database");
    }

    ui -> tableWidget -> setColumnCount(7);
}


fm_gestao_estoque::~fm_gestao_estoque()
{
    delete ui;
    con.fechar();
}

void fm_gestao_estoque::on_pushButton_clicked()
{
    ui -> lineEdit -> clear();
    ui -> lineEdit_2 -> clear();
    ui -> lineEdit_3 -> clear();
    ui -> lineEdit_4 -> clear();
    ui -> lineEdit_5 -> clear();
    ui -> lineEdit_6 -> clear();

    ui -> lineEdit -> setFocus();
}

void fm_gestao_estoque::on_pushButton_2_clicked()
{

        QString codigo = ui -> lineEdit -> text();
        QString quantidade = ui -> lineEdit_2 -> text();
        QString descricao = ui -> lineEdit_3 -> text();
        QString fornecedor = ui -> lineEdit_4 -> text();

        QString aux;

        aux = ui -> lineEdit_5 -> text();
        std :: replace(aux.begin(), aux.end(), ',', '.');
        QString valor_compra = aux;

        aux = ui -> lineEdit_6 -> text();
        std :: replace(aux.begin(), aux.end(), ',', '.');
        QString valor_venda = aux;

        QSqlQuery query;

        if(codigo != "" && quantidade != "" && descricao != "" && fornecedor != "" && valor_compra != "" && valor_venda != ""){

            if(!query.exec("insert into tb_produtos (id_produto, id_fornecedor, valor_compra, valor_venda, quantidade_estoque, produto)"
                       " values ('"+QString :: number(codigo.toInt())+"','"+QString :: number(fornecedor.toInt())+"','"+QString :: number(valor_compra.toDouble())+"',"
                       "'"+QString :: number(valor_venda.toDouble())+"','"+QString :: number(quantidade.toInt())+"','"+descricao+"')")){

                QMessageBox :: critical (this, "Erro", "Erro no processo do Query");

                 ui -> lineEdit -> clear();
                 ui -> lineEdit_2 -> clear();
                 ui -> lineEdit_3 -> clear();
                 ui -> lineEdit_4 -> clear();
                 ui -> lineEdit_5 -> clear();
                 ui -> lineEdit_6 -> clear();
            }else{
                QMessageBox :: information (this, "Register", "Register efetuado com sucesso");

                 ui -> lineEdit -> clear();
                 ui -> lineEdit_2 -> clear();
                 ui -> lineEdit_3 -> clear();
                 ui -> lineEdit_4 -> clear();
                 ui -> lineEdit_5 -> clear();
                 ui -> lineEdit_6 -> clear();

                 ui -> lineEdit -> setFocus();

            }

        }else{
            QMessageBox :: critical (this, "Erro", "Preencha todos os campos!");
        }

   // }

}



void fm_gestao_estoque::on_btn_ge_pesquisar_clicked()
{

}

void fm_gestao_estoque::on_btn_ge_excluir_clicked()
{

    int linha = ui -> tableWidget -> currentRow();
    int id = ui -> tableWidget -> item(linha, 0) -> text().toInt();

   QSqlQuery query;

    if(query.exec("delete from tb_produtos where id_produto='"+QString :: number(id)+"'")){
        ui -> tableWidget -> removeRow(linha);
        QMessageBox :: information (this, "Remove", "Item excluído com sucesso");
    }else{
        QMessageBox :: critical (this, "Remove", "Item não excluído");
    }


}

void fm_gestao_estoque::on_tabWidget_currentChanged(int index)
{

    if(index == 1){

        Remover_Linhas( ui -> tableWidget);
        QSqlQuery query;
        int cont = 0;

        if(query.exec("select id_produto, produto from tb_produtos order by id_produto asc")){

            while(query.next()){

                ui -> tableWidget -> insertRow(cont);

                ui -> tableWidget -> setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
                ui -> tableWidget -> setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));

                ui -> tableWidget -> setRowHeight(cont, 20);
                cont ++;
            }
            ui -> tableWidget -> setColumnWidth(0,100);
            ui -> tableWidget -> setColumnWidth(1,150);

            QStringList cabecalhos = {"id_produto", "Produto"};

            ui -> tableWidget -> setHorizontalHeaderLabels(cabecalhos);

            ui -> tableWidget -> setStyleSheet("QTableView {selection-background-color: blue, color: white}");

            ui -> tableWidget -> setEditTriggers(QAbstractItemView :: NoEditTriggers);

            ui -> tableWidget -> setSelectionBehavior(QAbstractItemView :: SelectRows);

            ui -> tableWidget -> verticalHeader() -> setVisible(false);


        }else{
            QMessageBox :: warning (this, "Erro", "Erro na Query");

        }

    }
}

void fm_gestao_estoque ::Remover_Linhas(QTableWidget *tw){
    while(tw -> rowCount() > 0){
        tw -> removeRow(0);
    }
}

void fm_gestao_estoque::on_tableWidget_itemSelectionChanged()
{

    int id = ui -> tableWidget -> item(ui -> tableWidget -> currentRow(), 0) -> text().toInt();

    QSqlQuery query("select * where id_produto="+QString :: number(id));

      if(query.exec()){

          query.first();

          QMessageBox :: information(this, "", "ok");

          ui -> txt_ge_codigo -> setText(query.value(1).toString());
          ui -> txt_ge_fornecedor -> setText(query.value(2).toString());
          ui -> txt_ge_valor_compra -> setText(query.value(3).toString());
          ui -> txt_ge_valor_venda -> setText(query.value(4).toString());
          ui -> txt_ge_quantidade -> setText(query.value(5).toString());
          ui -> txt_ge_produto -> setText(query.value(6).toString());

    }else{
        QMessageBox :: critical (this, "Erro", "Erro na Query B");
    }

}
