#ifndef ISSUEDBOOKS_H
#define ISSUEDBOOKS_H

using namespace std;

class Dbase ;

class IssuedBooks
{
public:
    int member_ID ;
    int book_ID ;

    IssuedBooks(int m_id, int b_id);
};

#endif // ISSUEDBOOKS_H
