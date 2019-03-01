#ifndef FM_GESTAO_COLABORADORES_H
#define FM_GESTAO_COLABORADORES_H

#include <QDialog>

namespace Ui {
class fm_gestao_colaboradores;
}

class fm_gestao_colaboradores : public QDialog
{
    Q_OBJECT

public:
    explicit fm_gestao_colaboradores(QWidget *parent = nullptr);
    ~fm_gestao_colaboradores();

private:
    Ui::fm_gestao_colaboradores *ui;
};

#endif // FM_GESTAO_COLABORADORES_H
