#ifndef BOOKS_H
#define BOOKS_H
#include <string>
#include <iostream>

using namespace std;

class Books
{
public:
    int bookID ;
    string title ;
    string author ;
    int quantity ;
    int issued ;

    Books(int id, const string& title, const string& author, int quantity, int issued);
};

#endif // BOOKS_H
