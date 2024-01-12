#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    char operation;
    double num1, num2;
    
    cout<<"Enter value for Num1"<<endl;
    cin>>num1;

    cout<<"Enter value for  Num2"<<endl;
    cin>>num2;

    cout<<"Enter the operation you want to do?"<<endl;
    cout << "Enter operator (+, -, *, /): ";
    cin>>operation;      

   switch(operation)
   {
        case '+':
            cout<<"Additon of two numbers is: "<<num1+num2<<endl;
            break;

        case '-':
            cout<<"Subtraction Of two Numbers is: "<<num1 - num2<<endl;
            break;

        case '*':
          cout<<"Multiplication of two numbers is: "<<num1*num2<<endl;
            break;

        case '/':
            if(num2==0)
            {
                cout<<"Divide by zero error "<<endl;
            }
            else{
                 cout<<"Division of two numbers is: "<<num1 / num2<<endl;
            }
            break;

        default:
            cout<<"Invalid Operator"<<endl;
            break;
           
   }
   return 0;
}