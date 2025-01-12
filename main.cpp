#include "dbase.h"
#include <iostream>

using namespace std;

int main()
{
    Dbase library ;
    library.openLibrary();
    library.closeLibrary();

    return 0;
}
