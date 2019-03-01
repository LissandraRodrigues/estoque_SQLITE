#include "fm_gestao_colaboradores.h"
#include "ui_fm_gestao_colaboradores.h"

fm_gestao_colaboradores::fm_gestao_colaboradores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_gestao_colaboradores)
{
    ui->setupUi(this);
}

fm_gestao_colaboradores::~fm_gestao_colaboradores()
{
    delete ui;
}
