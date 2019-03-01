#include "fm_novas_vendas.h"
#include "ui_fm_novas_vendas.h"

fm_novas_vendas::fm_novas_vendas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_novas_vendas)
{
    ui->setupUi(this);
}

fm_novas_vendas::~fm_novas_vendas()
{
    delete ui;
}
