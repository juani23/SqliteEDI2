#include <iostream>
#include "sqlite3.h"
#include <stdio.h>

int main(void) {

 sqlite3 *db;
  char *err_message = 0;

  int rc = sqlite3_open("Account.db", &db);

  if (rc != SQLITE_OK) {

    fprintf(stderr, "No se puede abrir la base de datos: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  } else {
    fprintf(stdout, "La base de datos se abrió correctamente...\n");
  }

  char *sql_query = "DROP TABLE IF EXISTS PERSONA;"
                    "CREATE TABLE PERSONA(Id INT PRIMARY KEY NOT NULL, Name NOMBRE, Number INT);"
                    "INSERT INTO PERSONA(Id,Name,Number)VALUES(412,'Juan',3500);";
                    "INSERT INTO PERSONA(Id,Name,Number)VALUES(411,'Lorenzo',7900);";
  rc = sqlite3_exec(db, sql_query, 0, 0, &err_message);

  if (rc != SQLITE_OK ) {

    fprintf(stderr, "SQL error: %s\n", err_message);

    sqlite3_free(err_message);
    sqlite3_close(db);

    return 1;
  } else {
    fprintf(stdout, "La tabla se creó correctamente...\n");
  }

  sqlite3_close(db);

  return 0;
}
