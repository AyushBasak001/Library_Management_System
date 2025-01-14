#ifndef BOOKS_H
#define BOOKS_H
#include <string>

class Books
{
public:
    int bookID ;
    std::string title ;
    std::string author ;
    int quantity ;
    int issued ;

    Books(int id, const std::string& title, const std::string& author, int quantity, int issued);
};

#endif // BOOKS_H
