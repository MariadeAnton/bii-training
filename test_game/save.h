#include <sqlite/sqlite/sqlite3/sqlite3.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct game_parameters{
	float radius;
	float gravity;
};

void execute_sql(sqlite3 *db, string zSql, sqlite3_callback xCallback, void *pArg);
void connect(sqlite3 **db);
void init_database();
void save(game_parameters params);
game_parameters load();
static int load_callback(void *data, int argc, char **argv, char **azColName);
