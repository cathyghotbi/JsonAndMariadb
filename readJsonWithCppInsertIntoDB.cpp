#include <string>
#include <iostream>
#include <fstream>

#include "database.hpp"
#include "json.hpp"

int main()
{
  DataBase testDatabase("localhost", "", "root", "test");

  std::cout << "--------------- opening conenction to database: ---------------" << std::endl;
  testDatabase.mysqlConnectionSetup();

  std::cout << "--------------- creating json file: ---------------" << std::endl;
  JsonFile jsonFile(testDatabase);
  jsonFile.createJsonFile();

  std::cout << "--------------- reading json file: ---------------" << std::endl;
  jsonFile.readJsonFile();

  std::cout << "--------------- adding the content of json file to database: ---------------" << std::endl;
  jsonFile.addJsonFileToDataBase();

  testDatabase.showDatabase();
  std::cout << "--------------- closing conenction to database: ---------------" << std::endl;

  return 0;
}
