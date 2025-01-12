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

    loadData();
}

void Dbase::closeLibrary() {}

void Dbase::loadData()
{
    vector<Admins> adm_rec ;
    vector<Members> mem_rec ;
    vector<Books> book_rec ;

    sqlite3_stmt* stmt ;
    sqlite3 *db;
    int rc = sqlite3_open("library.db", &db);

    // Load Admins
    const char* admin_query = "SELECT admin_id, username, password FROM admins" ;
    if(sqlite3_prepare_v2(db, admin_query, -1, &stmt, nullptr) == SQLITE_OK)
    {
        while(sqlite3_step(stmt) == SQLITE_ROW)
        {
            int id = sqlite3_column_int(stmt, 0) ;
            string username(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))) ;
            string password(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2))) ;

            adm_rec.emplace_back(id, username, password) ;
        }
    }
    else
    {
        cerr << "Error loading admins: "<< sqlite3_errmsg(db) << endl ;
    }
    sqlite3_finalize(stmt) ;

    // check adm_rec
    cout<< "Admins :"<<endl ;
    for(const auto& admin : adm_rec)
    {
        cout<<"ID : "<<admin.adminID<<", Name : "<<admin.name<<", Password : "<<admin.password<<endl ;
    }

    // Load Books
    const char* book_query = "SELECT book_id, title, author, total_quantity, issued_quantity FROM books" ;
    if(sqlite3_prepare_v2(db, book_query, -1, &stmt, nullptr) == SQLITE_OK)
    {
        while(sqlite3_step(stmt) == SQLITE_ROW)
        {
            int id = sqlite3_column_int(stmt, 0) ;
            string title(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))) ;
            string author(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2))) ;
            int tq = sqlite3_column_int(stmt, 3) ;
            int iq = sqlite3_column_int(stmt, 4) ;

            book_rec.emplace_back(id, title, author, tq, iq) ;
        }
    }
    else
    {
        cerr << "Error loading admins: "<< sqlite3_errmsg(db) << endl ;
    }
    sqlite3_finalize(stmt) ;

    // check book_rec
    cout<< "Books :"<<endl ;
    for(const auto& book : book_rec)
    {
        cout<<"ID : "<<book.bookID<<", Title : "<<book.title<<", Author : "<<book.author<<", Quantity : "<<book.quantity<<", Issued : "<<book.issued<<endl ;
    }


    // Load Members
    const char* member_query = "SELECT member_id, name, password FROM members" ;
    if(sqlite3_prepare_v2(db, member_query, -1, &stmt, nullptr) == SQLITE_OK)
    {
        while(sqlite3_step(stmt) == SQLITE_ROW)
        {
            int id = sqlite3_column_int(stmt, 0) ;
            string name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))) ;
            string password(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2))) ;

            mem_rec.emplace_back(id, name, password) ;
        }
    }
    else
    {
        cerr << "Error loading admins: "<< sqlite3_errmsg(db) << endl ;
    }
    sqlite3_finalize(stmt) ;

    // check adm_rec
    cout<< "Members :"<<endl ;
    for(const auto& member : mem_rec)
    {
        cout<<"ID : "<<member.memberID<<", Name : "<<member.name<<", Password : "<<member.password<<endl ;
    }

}
void Dbase::saveData() {}
