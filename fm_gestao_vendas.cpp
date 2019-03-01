#include "fm_gestao_vendas.h"
#include "ui_fm_gestao_vendas.h"

fm_gestao_vendas::fm_gestao_vendas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_gestao_vendas)
{
    ui->setupUi(this);
}

fm_gestao_vendas::~fm_gestao_vendas()
{
    delete ui;
}
