#ifndef MEMBERS_H
#define MEMBERS_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Members
{
    int memberID ;
    string name ;
    string password ;
    vector<int> issuedBooks ;

public:
    Members();
    void login() ;
    void issueBook() ;
    void returnBook() ;
    void listissuedBooks() ;
};

#endif // MEMBERS_H
