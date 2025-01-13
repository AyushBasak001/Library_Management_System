#include "books.h"
#include "members.h"
#include "admins.h"
#include <vector>

using namespace std;

extern vector<Admins> adm_rec ;
extern vector<Members> mem_rec ;
extern vector<Books> book_rec ;

#ifndef DBASE_H
#define DBASE_H

class Dbase
{
public:

    Dbase();
    void openLibrary() ;
    void closeLibrary() ;

    void loadData() ;
    void saveData() ;

};



#endif // DBASE_H
