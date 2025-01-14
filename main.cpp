#include "dbase.h"

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

        // Handle invalid input (e.g., letters or special characters)
        if (cin.fail())
        {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input in the buffer
            cout << "Invalid input! Please enter a number between 1 and 3.\n";
            continue; // Skip to the next iteration of the loop
        }

        if(choice==1)
        {
            library.closeLibrary();
            return 0;
        }
        else if(choice==2)
        {
            string n,p ;
            cout<<"Enter Admin Name : ";
            cin.ignore();
            getline(cin, n);
            cout<<"Enter Password : ";
            getline(cin, p);
            Admins admin(1,n,p) ;
            admin.login(n,p);
        }
        else if(choice==3)
        {
            string n,p ;
            cout<<"Enter Member Name : ";
            cin.ignore();
            getline(cin, n);
            cout<<"Enter Password : ";
            getline(cin, p);
            Members member(1,n,p) ;
            member.login(n,p);
        }
        else cout << "Invalid input! Please enter a number between 1 and 3"<<endl ;

    }
}
