#ifndef FM_GESTAO_VENDAS_H
#define FM_GESTAO_VENDAS_H

#include <QDialog>

namespace Ui {
class fm_gestao_vendas;
}

class fm_gestao_vendas : public QDialog
{
    Q_OBJECT

public:
    explicit fm_gestao_vendas(QWidget *parent = nullptr);
    ~fm_gestao_vendas();

private:
    Ui::fm_gestao_vendas *ui;
};

#endif // FM_GESTAO_VENDAS_H
