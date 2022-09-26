# JsonAndMariadb
In this repository, C++ is used together with json and mariadb. A json file is created, then it is read to fill the database.

## Compile and run:
$ g++ database.cpp json.cpp readJsonWithCppInsertIntoDB.cpp -o readJsonWithCppInsertIntoDB -L/usr/include/mariadb/mysql -lmariadbclient 
$ sudo ./readJsonWithCppInsertIntoDB

## References: 
* [1] https://mariadb.com/resources/blog/how-to-connect-c-programs-to-mariadb
* [2] https://www.youtube.com/watch?v=cSZvq7Kv6_0
* [3] https://github.com/nlohmann/json/blob/develop/docs/examples/README.cpp
* [4] https://github.com/nlohmann/json/issues/2188
* [5] https://stackoverflow.com/questions/3202136/using-g-to-compile-multiple-cpp-and-h-files
* [6] https://stackoverflow.com/questions/13935364/how-to-read-a-json-file-into-a-c-string
