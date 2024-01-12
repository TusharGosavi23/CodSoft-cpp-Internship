#include<iostream>
using namespace std;

class node
{
    public:
    int seat,status;
    string ID;
    node *next,*prev;
};
class cinemax
{
    public:
    node *head, *tail;
    cinemax()
    {
        head=NULL;
    }
    void create();
    void display();
    void Book_Seat();
    void available();
    void Delete();
};
void cinemax::create()
{
    node *temp;
    temp=new node;
    temp->seat=1;
    temp->status=0;
    temp->ID="NULL";
    head=tail=temp;

    for(int i=2;i<=71;i++)
    {
        node *ptr;
        ptr=new node;
        ptr->seat=i;
        ptr->status=0;
        ptr->ID="NULL";

        tail->next=ptr;
        ptr->prev=tail;
        tail=ptr;
        tail->next=head;
        head->prev=tail;
    }
};
void cinemax::display()
{
    node *temp=head;
    int count=0;
    while(temp->next!=head)
    {
        if(temp->status==0)
        {
            cout<<temp->seat<<":"<<"A"<<" ";
        }
        else
        {
            cout<<temp->seat<<":"<<"B"<<" ";
          
        }
        count++;
        if(count%7==0)
        {
          cout<<endl;
        }
        temp=temp->next;
    
    }
    cout<<"\nA-Available\nB-Booked"<<endl;
};
void cinemax::Book_Seat()
{
    int x;
    string ID;
    abc:
    cout<<"Enter the seat number that you want to book";
    cin>>x;
    if(x<0 || x>70)
    {
        cout<<"Please enter valid seat number.";
        goto abc;
    }
    cout<<"Enter your seat ID ";
    cin>>ID;
    node *temp;
    temp=new node;
    temp=head;
    while(temp->seat!=x)
    {
        temp=temp->next;
    }
    if(temp->status=0)
    {
        cout<<"Seat is already book.";
    }
    else
    {
        temp->status=1;
        temp->ID=ID;
        cout<<"Seat "<<x<<" is booked"<<endl;    
    }
};
void cinemax::available()
{
    node *temp;
    temp=new node;
    temp=head;
    int count=70;
    while(temp->next!=head)
    {
        if(temp->ID!="NULL")
        {
            count--;
            temp=temp->next;
        }
        else
        {
            temp=temp->next;
        }
    }
    cout<<count<<"seats are available for booking.";
};
void cinemax::Delete()
{
    node *temp;
    temp=new node;
    temp=head;
    abc:
    string x;
    int y;
    cout<<"Enter the seat number that you want to delete";
    cin>>y;
    if(y<0 || y>70)
    {
        cout<<"Please enter valid seat number";
        goto abc;
    }
    while(temp->seat!=y)
    {
        temp=temp->next;
    }
    if(temp->ID!="NULL")
    {
        temp->ID="NULL";
        temp->status=0;
        cout<<"Booking Canclled";
    }
    else
    {
        cout<<"Seat is not book yet";
    }
};
int main()
{
    cinemax c;
    c.create();
    int ch;
    cout<<"\n1.Display\n2.Book Seat\n3.Available Seat\n4.Canclled Booking\n5.Exit"<<endl;
    do
    {
        cout<<"\nEnter your Choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            c.display();
            break;

            case 2:
            c.Book_Seat();
            break;

            case 3:
            c.available();
            break;

            case 4:
            c.Delete();
            break;

            case 5:
            cout<<"Thanks for visiting";
            break;       
        }
    }
    while(ch!=5);
    return 0;
}