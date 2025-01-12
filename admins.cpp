#include "admins.h"

Admins::Admins(int id, const string& n, const string& pass)
    : adminID(id), name(n), password(pass) {}

void Admins::login() {}

void Admins::addBook() {}
void Admins::removeBook() {}
void Admins::addMember() {}
void Admins::removeMember() {}
void Admins::addAdmin() {}
void Admins::removeAdmin() {}

void Admins::listallMembers() {}
void Admins::listallAdmins() {}
void Admins::listallbooks() {}

void Admins::serchBooks() {}
