#ifndef FM_PRINCIPAL_H
#define FM_PRINCIPAL_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSql>

namespace Ui {
class fm_principal;
}

class fm_principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit fm_principal(QWidget *parent = nullptr);
    ~fm_principal();

    QIcon aberto, fechado;
    static bool logado;
    static QString acesso_colab, nome_colab, username_colab;
    static int id_colab;

private slots:
    void on_pushButton_clicked();

    void on_actionSair_triggered();

    void on_pushButton_2_clicked();

    void on_actionEstoque_triggered();

    void on_actionVendas_triggered();

    void on_actionColaboradores_triggered();

private:
    Ui::fm_principal *ui;
};

#endif // FM_PRINCIPAL_H
