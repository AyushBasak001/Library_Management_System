#include "members.h"
#include "dbase.h"
#include <iostream>

Members::Members(int id, const string& n, const string& pass)
    : memberID(id), name(n), password(pass) {}

void Members::login(const string& name, const string& pass)
{
    bool found = false;
    for (const auto& member : mem_rec)
    {
        if (member.name == name && member.password == pass)
        {
            found = true;
            memberID=member.memberID ;
            break;
        }
    }
    if (!found)
    {
        cout << "Access Denied!" << endl;
        return ;
    }
    else
        cout << "\nWelcome " << name << "!" << endl;

    operations();

}

void Members::operations()
{
    int choice=1 ;

    while(true)
    {
        cout<<"\nWhich operation would you like to perform ? "<<endl ;
        cout<<"1. Close\n2. List all Books\nEnter Choice : " ;
        cin>>choice ;

        if(choice==1) return ;
        else if(choice==2) listallbooks();
    }
}

void Members::listallbooks()
{
    cout << "\nBooks:\n";
    for (const auto& book : book_rec)
    {
        cout << "ID: " << book.bookID << ", Title: " << book.title
             << ", Author: " << book.author
             << ", Quantity: " << book.quantity
             << ", Issued: " << book.issued << endl;
    }
}

void Members::issueBook() {}
void Members::returnBook() {}
void Members::listissuedBooks() {}
