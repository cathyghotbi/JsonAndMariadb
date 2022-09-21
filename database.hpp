
#pragma once

#include <mariadb/mysql.h>

class DataBase
{
public:
  DataBase(const char* server, const char* user, const char* password, const char* database)
    : m_connectionDetails({server, user, password, database}) 
  {
  }
  
  void mysqlConnectionSetup();
  MYSQL_RES* mysqlExecuteQuery(const char* sqlQuery);
  void showDatabase();
  MYSQL* getConnection();

  ~DataBase()
  {
  }
 
private:
  MYSQL* m_connection;
  MYSQL_RES* m_result;
  MYSQL_ROW m_row;

  struct ConnectionDetails
  {
    const char* m_server;
    const char* m_user;
    const char* m_password;
    const char* m_database;
  };

  ConnectionDetails m_connectionDetails;
};
