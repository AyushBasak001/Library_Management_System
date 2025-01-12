#include "books.h"
#include "members.h"
#include "admins.h"
#include <vector>

using namespace std;

#ifndef DBASE_H
#define DBASE_H

class Dbase
{
    vector<Admins> adm_rec ;
    vector<Members> mem_rec ;
    vector<Books> book_rec ;

public:

    vector<Books> books ;
    vector<Members> members ;
    vector<Admins> admins ;

    Dbase();
    void openLibrary() ;
    void closeLibrary() ;

    void loadData() ;
    void saveData() ;

};

#endif // DBASE_H
