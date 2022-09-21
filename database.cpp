

#include <string>
#include <iostream>

#include "database.hpp"

void DataBase::mysqlConnectionSetup()
{
  MYSQL* connection = mysql_init(NULL);
  if(!mysql_real_connect(connection, m_connectionDetails.m_server, m_connectionDetails.m_user, m_connectionDetails.m_password, m_connectionDetails.m_database, 0, NULL, 0))
  {
    std::cout << "Connection error: " << mysql_error(connection) << std::endl;
    exit(1);
  }

  m_connection = connection;
}

MYSQL_RES* DataBase::mysqlExecuteQuery(const char* sqlQuery)
{
  if(mysql_query(m_connection, sqlQuery))
  {
    std::cout << " MySQL Query error: " << mysql_error(m_connection) << std::endl;
    exit(1);
  }

  return mysql_use_result(m_connection);
}

void DataBase::showDatabase()
{ 
  m_result = mysqlExecuteQuery("select * from person");
  while((m_row = mysql_fetch_row(m_result)) != NULL)
  {
    std::cout << m_row[0] << " | " << m_row[1] << " | "  << m_row[2] << " | " << m_row[3] << " | " << m_row[4] << " | " << m_row[5] << std::endl; // TODO
  }  
}

MYSQL* DataBase::getConnection()
{
  if(!m_connection)
  {
    std::cout << "no connection to sql" << std::endl;
  }

  return m_connection;
}
