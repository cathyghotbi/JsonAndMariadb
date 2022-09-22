
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
    delete m_result;
    delete m_row;
    m_result = nullptr;
    m_row = nullptr;
  }

private:
  MYSQL* m_connection;
  MYSQL_RES* m_result;
  MYSQL_ROW m_row;

  struct ConnectionDetails
  {
    std::string m_server;
    std::string m_user;
    std::string m_password;
    std::string m_database;
  };

  ConnectionDetails m_connectionDetails;
};
