#ifndef FM_GESTAO_ESTOQUE_H
#define FM_GESTAO_ESTOQUE_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
#include <QTableWidget>

#include "fm_conexao.h"

namespace Ui {
class fm_gestao_estoque;
}

class fm_gestao_estoque : public QDialog
{
    Q_OBJECT

public:
    explicit fm_gestao_estoque(QWidget *parent = nullptr);
    ~fm_gestao_estoque();
    Conexao con;

    void Remover_Linhas(QTableWidget *tw);

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_btn_ge_pesquisar_clicked();

    void on_btn_ge_excluir_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_tableWidget_itemSelectionChanged();

private:
    Ui::fm_gestao_estoque *ui;
};

#endif // FM_GESTAO_ESTOQUE_H
