#ifndef ADMINS_H
#define ADMINS_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Dbase ;

class Admins
{  // declare data members as private after checking link
public:
    int adminID ;
    string name ;
    string password ;

    Admins(int id, const string& name, const string& pass);
    void login(const string& name, const string& pass) ;

    void operations() ;

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
