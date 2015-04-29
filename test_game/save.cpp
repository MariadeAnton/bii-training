#include "save.h"

using namespace std;

void execute_sql(sqlite3 *db, string zSql, sqlite3_callback xCallback, void *pArg){

	int  rc;
	char *pzErrMsg = 0;
	rc = sqlite3_exec(db, zSql.c_str(), xCallback, pArg, &pzErrMsg);
	if( rc != SQLITE_OK ){
	fprintf(stderr, "SQL error: %s\n", pzErrMsg);
    	sqlite3_free(pzErrMsg);
	}
}

void connect(sqlite3 **db){
	int  rc;
	rc = sqlite3_open("save.db", db);
	if( rc ){
    	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(*db));
    	exit(0);
	}
}


void init_database(){
	sqlite3 *db;
	sqlite3_callback void_callback = 0;
	string query;

	/* Open database */
	connect(&db);

	query = "CREATE TABLE IF NOT EXISTS PARAMETERS (ID INT UNIQUE, RADIOUS FLOAT, GRAVITY FLOAT);";
	execute_sql(db, query, void_callback, 0);

	/* Close database */
	sqlite3_close(db);
}


void save(game_parameters params){
	sqlite3 *db;
	sqlite3_callback void_callback;
	const char* query = "INSERT OR REPLACE INTO PARAMETERS (ID, RADIOUS, GRAVITY) VALUES (0, %f, %f);";

	/* Open database */
	connect(&db);
	char buffer[1000];
	sprintf(buffer, query, params.radius, params.gravity);
	execute_sql(db, buffer, void_callback, 0);

	/* Close database */
	sqlite3_close(db);

	cout << "Saved!" << endl;
}


static int load_callback(void *data, int argc, char **argv, char **azColName){
   int i;
   game_parameters* ret = (game_parameters*) data;
   ret->radius =  atof(argv[1]);
   ret->gravity = atof(argv[2]);
   return 0;
}

game_parameters load(){
	///Callback must receive a game_parameters object

	sqlite3 *db;
	sqlite3_callback void_callback;
	string query;
	game_parameters results[1];
	results[0].gravity = 9.8;
	results[0].radius = 0.8;

	/* Open database */
	connect(&db);

	query = "SELECT * from PARAMETERS WHERE ID=0";
	execute_sql(db, query, load_callback, results);

	/* Close database */
	sqlite3_close(db);

	game_parameters ret;
	ret.gravity = results[0].gravity;
	ret.radius = results[0].radius;

	return ret;
}
