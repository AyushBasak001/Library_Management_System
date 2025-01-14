#ifndef MEMBERS_H
#define MEMBERS_H
#include <string>
#include <vector>

class Members
{
public:
    int memberID ;
    std::string name ;
    std::string password ;
    std::vector<int> issuedBooks ;

    Members(int id, const std::string& name, const std::string& pass);
    void login(const std::string& name, const std::string& pass) ;
    void operations() ;
    void listallbooks() ;
    void issueBook() ;
    void returnBook() ;
    void listissuedBooks() ;
};

#endif // MEMBERS_H
