#ifndef BOOKS_H
#define BOOKS_H
#include <string>
#include <iostream>

using namespace std;

class Books
{
    int bookID ;
    string title ;
    string author ;
    int quantity ;
    int issued ;

public:
    Books();
    bool isAvailable() ;
    void issueBook() ;
    void returnBook() ;
};

#endif // BOOKS_H
