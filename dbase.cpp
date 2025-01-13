#include "dbase.h"
#include <sqlite3.h>
#include <iostream>

using namespace std;

vector<Admins> adm_rec ;
vector<Members> mem_rec ;
vector<Books> book_rec ;
vector<IssuedBooks> isu_rec ;

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

void Dbase::closeLibrary() {
    saveData();
    cout<<"saved data and closed database !"<<endl ;
}

void Dbase::loadData()
{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc = sqlite3_open("library.db", &db);

    if (rc) {
        cerr << "Error opening database: " << sqlite3_errmsg(db) << endl;
        return;
    }

    // Load Admins
    adm_rec.clear();
    const char* admin_query = "SELECT admin_id, username, password FROM admins";
    if (sqlite3_prepare_v2(db, admin_query, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            string username(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
            string password(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
            adm_rec.emplace_back(id, username, password);
        }
    } else {
        cerr << "Error loading admins: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);

    cout << "Admins:\n";
    for (const auto& admin : adm_rec) {
        cout << "ID: " << admin.adminID << ", Name: " << admin.name
             << ", Password: " << admin.password << endl;
    }

    // Load Books
    book_rec.clear();
    const char* book_query = "SELECT book_id, title, author, total_quantity, issued_quantity FROM books";
    if (sqlite3_prepare_v2(db, book_query, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            string title(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
            string author(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
            int tq = sqlite3_column_int(stmt, 3);
            int iq = sqlite3_column_int(stmt, 4);
            book_rec.emplace_back(id, title, author, tq, iq);
        }
    } else {
        cerr << "Error loading books: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);


    // Load Members
    mem_rec.clear();
    const char* member_query = "SELECT member_id, name, password FROM members";
    if (sqlite3_prepare_v2(db, member_query, -1, &stmt, nullptr) == SQLITE_OK)
    {
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            int id = sqlite3_column_int(stmt, 0);
            string name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
            string password(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
            mem_rec.emplace_back(id, name, password);
        }
    }
    else
    {
        cerr << "Error loading members: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);


    const char* isu_query = "SELECT member_id, book_id FROM issued_books";
    if (sqlite3_prepare_v2(db, isu_query, -1, &stmt, nullptr) == SQLITE_OK)
    {
        isu_rec.clear();
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            int m_id = sqlite3_column_int(stmt, 0);
            int b_id = sqlite3_column_int(stmt, 1);
            isu_rec.emplace_back(m_id, b_id);
        }
    }
    else
    {
        cerr << "Error loading issued books: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);

    sqlite3_close(db);
}

void Dbase::saveData() {
    sqlite3 *db;
    sqlite3_open("library.db", &db);

    // Begin a transaction to ensure atomicity
    sqlite3_exec(db, "BEGIN TRANSACTION;", nullptr, nullptr, nullptr);

    // Clear all data in the database by deleting records
    sqlite3_exec(db, "DELETE FROM admins;", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "DELETE FROM books;", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "DELETE FROM members;", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "DELETE FROM issued_books;", nullptr, nullptr, nullptr);

    // Re-insert data from in-memory vectors back into the database

    // Insert Admins
    for (auto& admin : adm_rec) {
        sqlite3_stmt* stmt;
        const char* insert_admin_query = "INSERT INTO admins (admin_id, username, password) VALUES (?, ?, ?)";
        sqlite3_prepare_v2(db, insert_admin_query, -1, &stmt, nullptr);
        sqlite3_bind_int(stmt, 1, admin.adminID);
        sqlite3_bind_text(stmt, 2, admin.name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, admin.password.c_str(), -1, SQLITE_STATIC);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }

    // Insert Books
    for (auto& book : book_rec) {
        sqlite3_stmt* stmt;
        const char* insert_book_query = "INSERT INTO books (book_id, title, author, total_quantity, issued_quantity) VALUES (?, ?, ?, ?, ?)";
        sqlite3_prepare_v2(db, insert_book_query, -1, &stmt, nullptr);
        sqlite3_bind_int(stmt, 1, book.bookID);
        sqlite3_bind_text(stmt, 2, book.title.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, book.author.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 4, book.quantity);
        sqlite3_bind_int(stmt, 5, book.issued);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }

    // Insert Members
    for (auto& member : mem_rec) {
        sqlite3_stmt* stmt;
        const char* insert_member_query = "INSERT INTO members (member_id, name, password) VALUES (?, ?, ?)";
        sqlite3_prepare_v2(db, insert_member_query, -1, &stmt, nullptr);
        sqlite3_bind_int(stmt, 1, member.memberID);
        sqlite3_bind_text(stmt, 2, member.name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, member.password.c_str(), -1, SQLITE_STATIC);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }

    // Insert Issued Books
    for (auto& isb : isu_rec) {
        sqlite3_stmt* stmt;
        const char* insert_isb_query = "INSERT INTO issued_books (member_id, book_id) VALUES (?, ?)";
        sqlite3_prepare_v2(db, insert_isb_query, -1, &stmt, nullptr);
        sqlite3_bind_int(stmt, 1, isb.member_ID);
        sqlite3_bind_int(stmt, 2, isb.book_ID);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }

    // Commit the transaction
    sqlite3_exec(db, "COMMIT;", nullptr, nullptr, nullptr);

    sqlite3_close(db);
}

