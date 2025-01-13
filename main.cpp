#include "dbase.h"
#include <iostream>

using namespace std;

int main()
{


    Dbase library ;
    library.openLibrary();

    int choice=1 ;
    while(true)
    {
        cout<<"\nWhich operation would you like to Perform ?"<<endl ;
        cout<< "1. Save and Close \n2. Admin Login \n3. Member Login\nEnter Choice : " ;
        cin >> choice ;

        if(choice==1)
        {
            library.closeLibrary();
            return 0;
        }
        else if(choice==2)
        {
            string n,p ;
            cout<<"Enter Admin Name : ";
            cin>>n ;
            cout<<"Enter Password : ";
            cin>>p ;
            Admins admin(1,n,p) ;
            admin.login(n,p);
        }
        else if(choice==3)
        {
            string n,p ;
            cout<<"Enter Member Name : ";
            cin>>n ;
            cout<<"Enter Password : ";
            cin>>p ;
            Members member(1,n,p) ;
            member.login(n,p);
        }
    }
}
