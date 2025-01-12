#include "dbase.h"
#include <sqlite3.h>
#include <iostream>

using namespace std;

Dbase::Dbase() {}
void Dbase::openLibrary()
{
    sqlite3 *db;
    int rc;

    rc = sqlite3_open("library.db", &db);  // Open SQLite database
    if (rc)
    {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return ;
    }
}

void Dbase::closeLibrary() {}

void Dbase::loadData() {}
void Dbase::saveData() {}
