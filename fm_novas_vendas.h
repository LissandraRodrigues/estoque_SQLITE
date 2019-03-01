#ifndef FM_NOVAS_VENDAS_H
#define FM_NOVAS_VENDAS_H

#include <QDialog>

namespace Ui {
class fm_novas_vendas;
}

class fm_novas_vendas : public QDialog
{
    Q_OBJECT

public:
    explicit fm_novas_vendas(QWidget *parent = nullptr);
    ~fm_novas_vendas();

private:
    Ui::fm_novas_vendas *ui;
};

#endif // FM_NOVAS_VENDAS_H
