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
        cout<<"1. Close\n2. View all Books\n3. View Issued Books\n4. Issue Book\n5. Return Book\nEnter Choice : " ;
        cin>>choice ;

        if(choice==1) return ;
        else if(choice==2) listallbooks();
        else if(choice==3) listissuedBooks();
        else if(choice==4) issueBook();
        else if(choice==5) returnBook();

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

void Members::issueBook()
{
    int bid ;
    cout<<"Enter Book ID to be issued : ";
    cin>>bid ;

    int num=0 ;
    for (const auto& ib : isu_rec)
    {
        if(ib.member_ID==memberID)
        {
            if((num++)==3)
            {
                cout<<"Cannot issue more than 3 books at a time !"<<endl ;
                return ;
            }
        }
        if(ib.book_ID==bid && ib.member_ID==memberID)
        {
            cout<<"Book already issued by you !"<<endl ;
            return ;
        }
    }

    for (auto& book : book_rec)
    {
        if(book.bookID==bid)
        {
            if(book.quantity>book.issued)
            {
                book.issued++;
                isu_rec.emplace_back(memberID, bid);
                cout<<"Successful operation"<<endl ;
                return;
            }
            else
            {
                cout<<"Book is currently unavailable !"<<endl ;
                return ;
            }
        }
    }
    cout<<"No book found with provided ID !"<<endl ;
}

void Members::returnBook()
{
    int bid ;
    cout<<"Enter Book ID to be returned : ";
    cin>>bid ;

    for (auto it = isu_rec.begin(); it != isu_rec.end(); ++it)
    {
        if (it->book_ID == bid)
        {
            isu_rec.erase(it);
            for (auto& book : book_rec)
                if(book.bookID==bid)
                {
                    book.issued--;
                    cout << "Book Returned" << endl;
                    return;
                }
        }
    }
    cout << "Book not issued!" << endl;
}

void Members::listissuedBooks()
{
    cout << "\nBooks Issued by "<<name<<" :\n";
    for (const auto& issbook : isu_rec)
    {
        if(issbook.member_ID==memberID)
        {
            cout << "Book ID: " << issbook.book_ID<< endl;
        }
    }
}
