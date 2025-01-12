#ifndef ADMINS_H
#define ADMINS_H
#include <string>
#include <iostream>

using namespace std;

class Admins
{
    int adminID ;
    string name ;
    string password ;

public:
    Admins();
    void login() ;

    void addBook() ;
    void removeBook() ;
    void addMember() ;
    void removeMember() ;
    void addAdmin() ;
    void removeAdmin() ;

    void listallMembers() ;
    void listallAdmins() ;
    void listallbooks() ;

    void serchBooks() ;

};

#endif // ADMINS_H
