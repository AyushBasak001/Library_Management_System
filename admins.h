#ifndef ADMINS_H
#define ADMINS_H
#include <string>
#include <vector>

class Admins
{
public:
    int adminID ;
    std::string name ;
    std::string password ;

    Admins(int id, const std::string& name, const std::string& pass);
    void login(const std::string& name, const std::string& pass) ;

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

    void updateQty() ;
};

#endif // ADMINS_H
