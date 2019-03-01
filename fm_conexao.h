#ifndef FM_CONEXAO_H
#define FM_CONEXAO_H

#include <QtSql>

class Conexao{

public:

      QSqlDatabase banco_de_dados;
      QString banco;
      QString local;

      Conexao(){
          banco_de_dados = QSqlDatabase :: addDatabase("QSQLITE");
          //local = qApp -> applicationDirPath();
         //banco = local + "/Banco_Estoque/estoque.db";

          local  = "C:/Users/luiza/Desktop/Programação/Projeto_Estoque/P_SQL_QT/Banco_Estoque/";
          banco = local + "/estoque.db";

      }

      void fechar(){
          banco_de_dados.close();
      }

      bool abrir(){
          banco_de_dados.setDatabaseName(banco);

          if(!banco_de_dados.open()){
             return false;
          }else{
              return true;
          }
      }

      bool aberto(){
          if(banco_de_dados.isOpen()){
              return true;
          }else{
              return false;
          }
      }

};

#endif // FM_CONEXAO_H
