#include "books.h"
#include "members.h"
#include "admins.h"
#include <vector>

using namespace std;

#ifndef DBASE_H
#define DBASE_H

class Dbase
{
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
