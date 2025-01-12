#ifndef MEMBERS_H
#define MEMBERS_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Members
{
public:
    int memberID ;
    string name ;
    string password ;
    vector<int> issuedBooks ;

    Members(int id, const string& name, const string& pass);
    void login() ;
    void issueBook() ;
    void returnBook() ;
    void listissuedBooks() ;
};

#endif // MEMBERS_H
