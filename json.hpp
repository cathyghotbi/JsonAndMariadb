#pragma once

#include <nlohmann/json.hpp>
#include "database.hpp"

class JsonFile
{
public:
  JsonFile(DataBase& db)
    : m_database(db)
  {
  }

  void createJsonFile();
  void addJsonFileToDataBase();
  void readJsonFile();

private:
  DataBase m_database;
  nlohmann::json m_jsonObjectFromFile;
};
