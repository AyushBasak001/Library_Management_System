#include "admins.h"
#include "dbase.h"
#include <iostream>

using namespace std ;

Admins::Admins(int id, const string& n, const string& pass)
    : adminID(id), name(n), password(pass) {}

void Admins::login(const string& name, const string& pass)
{
    bool found = false;
    for (const auto& admin : adm_rec)
    {
        if (admin.name == name && admin.password == pass)
        {
            found = true;
            adminID=admin.adminID ;
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

void Admins::operations()
{
    int choice=1 ;

    while(true)
    {
        cout<<"\nWhich operation would you like to perform ? "<<endl ;
        cout<<"1. Close\n2. Add new Admin\n3. Add new Member\n4. Add new Book\n5. List all Books\n6. List all Members\n7. List all Admins\n8. Remove Book\n9. Remove Member\n10.Remove Admin\nEnter Choice : " ;
        cin>>choice ;

        if(choice==1) return ;
        else if(choice==2) addAdmin();
        else if(choice==3) addMember();
        else if(choice==4) addBook();
        else if(choice==5) listallbooks();
        else if(choice==6) listallMembers();
        else if(choice==7) listallAdmins();
        else if(choice==8) removeBook();
        else if(choice==9) removeMember();
        else if(choice==10) removeAdmin();
    }
}

void Admins::addBook()
{
    int id=book_rec.back().bookID + 1 ;
    string t,a ;
    int q ;
    cout<<"Enter Book Title : ";
    cin.ignore();
    getline(cin, t);
    cout<<"Enter Author's Name : ";
    getline(cin, a);
    cout<<"Enter Quantity of Book : ";
    cin>>q ;

    book_rec.emplace_back(id, t, a, q, 0);
}

void Admins::removeBook()
{
    int id;
    cout << "Enter Book ID: ";
    cin >> id;

    for (auto it = book_rec.begin(); it != book_rec.end(); ++it)
    {
        if (it->bookID == id)
        {
            book_rec.erase(it);
            cout << "Book removed!" << endl;
            return;
        }
    }
    cout << "Book not found!" << endl;
}

void Admins::addMember()
{
    string n,p ;
    cout<<"Enter a Name : ";
    cin.ignore();
    getline(cin, n);
    cout<<"Enter a Password : ";
    cin>>p ;
    int id=mem_rec.back().memberID + 1 ;

    mem_rec.emplace_back(id, n, p);
}

void Admins::removeMember()
{
    int id;
    cout << "Enter Member ID: ";
    cin >> id;

    for (auto it = mem_rec.begin(); it != mem_rec.end(); ++it)
    {
        if (it->memberID == id)
        {
            mem_rec.erase(it);
            cout << "Member removed!" << endl;
            return;
        }
    }
    cout << "Member not found!" << endl;
}

void Admins::addAdmin()
{
    string n,p ;
    cout<<"Enter a Name : ";
    cin.ignore();
    getline(cin, n);
    cout<<"Enter a Password : ";
    cin>>p ;
    int id=adm_rec.back().adminID + 1 ;

    adm_rec.emplace_back(id, n, p);
}

void Admins::removeAdmin()
{
    if(adm_rec.size()==1)
    {
        cout<<"Can not remove the only remaining admin !"<<endl ;
        return ;
    }
    int id;
    cout << "Enter Admin ID: ";
    cin >> id;

    for (auto it = adm_rec.begin(); it != adm_rec.end(); ++it) {
        if (it->adminID == id) {
            adm_rec.erase(it); // Erase the book
            cout << "Admin removed!" << endl;
            return;
        }
    }
    cout << "Admin not found!" << endl;
}

void Admins::listallMembers()
{
    cout << "\nMembers:\n";
    for (const auto& member : mem_rec)
    {
        cout << "ID: " << member.memberID << ", Name: " << member.name
             << ", Password: " << member.password << endl;
    }
    return ;
}

void Admins::listallAdmins()
{
    cout << "\nAdmins:\n";
    for (const auto& admin : adm_rec)
    {
        cout << "ID: " << admin.adminID << ", Name: " << admin.name
             << ", Password: " << admin.password << endl;
    }
}

void Admins::listallbooks()
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

void Admins::serchBooks() {}
