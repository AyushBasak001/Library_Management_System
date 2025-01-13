#ifndef MEMBERS_H
#define MEMBERS_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Dbase ;

class Members
{
public:
    int memberID ;
    string name ;
    string password ;
    vector<int> issuedBooks ;

    Members(int id, const string& name, const string& pass);
    void login(const string& name, const string& pass) ;
    void operations() ;
    void listallbooks() ;
    void issueBook() ;
    void returnBook() ;
    void listissuedBooks() ;
};

#endif // MEMBERS_H
