#include<iostream>
#include<string>
#include<ios>
#include<limits>
#include<stdlib.h>
using namespace std;
class Country{
     string name,capital,currency,demonym,continent;
     long population,area;
     public:
     Country()
     {
         name=capital=currency=demonym=continent="Nameless";
         population=area=0;
     }
     void getdata()
     {
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
         cout<<"Name of the country : ";
         getline(cin,name);
         cout<<"Capital : ";
         getline(cin,capital);
         cout<<"Currency : ";
         getline(cin,currency);
         cout<<"Demonym : ";
         getline(cin,demonym);
         cout<<"Continent : ";
         getline(cin,continent);
         cout<<"Population : ";
         cin>>population;
         cout<<"Area : ";
         cin>>area;
     }
     void dispdata()
     {
         cout<<"Name : "<<name<<endl;
         cout<<"Capital : "<<capital<<endl;
         cout<<"Currency : "<<currency<<endl;
         cout<<"Demonym : "<<demonym<<endl;
         cout<<"Continent : "<<continent<<endl;
         cout<<"Population : "<<population<<endl;
         cout<<"Area : "<<area<<" sq mi "<<endl;
     }
     ~Country()
     {
         cout<<"Goodbye "<<name<<" !!!"<<endl;
     }
     friend void Find_out(Country c[]);
}c[10];
int n=0;
void Insert()
{
    cout<<"Enter the no. of countries to be entered : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Details of Country "<<i+1<<"::\n";
        c[i].getdata();
    }
}
void Find_out(Country c[])
{
    int x,i;
    int pos;
    string temp;
    cout<<"What do you want to find out ????"<<endl;
    cout<<"1. Country with largest area\n2. Country with largest population\n3. Country's capital city\n4. Continent--->Country\n5. Return back\n";
    while(1)
    {
        cout<<"Enter your choice : ";
        cin>>x;
        switch(x)
        {
            case 1:
            pos=0;
            for(i=1;i<n;i++)
            {
                  if(c[i].area>c[pos].area)
                   pos=i;
            }
            cout<<"Details "<<endl;
            c[pos].dispdata();
            break;
            case 2:
            pos=0;
            for(i=1;i<n;i++)
            {
                  if(c[i].population>c[pos].population)
                   pos=i;
            }
            cout<<"Details "<<endl;
            c[pos].dispdata();
            break;
            case 3:
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Please enter the country name : ";
            getline(cin,temp);
            for(i=0;i<n;i++)
            {
                if(c[i].name==temp)
                {
                    cout<<"Capital City : "<<c[i].capital<<endl;
                }
            }
            break;
            case 4:
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Enter the continent name : ";
            getline(cin,temp);
            cout<<"Countries in "<<temp<<" ::"<<endl;
            for(i=0;i<n;i++)
            {
                if(c[i].continent==temp)
                  cout<<c[i].name<<endl;
            }
            break;
            case 5:
            cout<<"Returning back to the main menu.....\n";
            return;
            break;
        }
    }

   
}
int main()
{
    int choice;
    cout<<"Welcome to the Main Menu"<<endl;
    cout<<"1. Insert country list\n2. Find out\n3. Exit\n"<<endl;
    while(1)
    {
        cout<<"Please enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            Insert();
            break;
            case 2:
            Find_out(c);
            break;
            case 3:
            exit(0);
            break;
        }
    }
    return 0;
}