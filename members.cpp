#include "members.h"

Members::Members(int id, const string& n, const string& pass)
    : memberID(id), name(n), password(pass) {}

void Members::login() {}
void Members::issueBook() {}
void Members::returnBook() {}
void Members::listissuedBooks() {}
