#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
    srand(time(0));
    int secrectNumber= rand()%100+1;
    int guess;
    int attempts=0;
    

    cout<<"Welcome to Number Guess Game...You are Good to Go.."<<endl;
    cout<<"I have selected a number between 1 to 100 . Try to Guess it .."<<endl;

    do
    {
      cout<<"Enter Your Guess: "<<endl;
      cin>>guess;
      attempts++;


      if(guess==secrectNumber)
      {
        cout<<"Congratulations..You have Guess Correct Number in "<<attempts<<"attempts"<<endl;

      }
      else if(guess<secrectNumber)
      {
        cout<<"Too Low ...Try to Guess Higher Number.."<<endl;
      }
      else{
        cout<<"Too High...Try to guess Lower Number"<<endl;
      }
    } while (guess != secrectNumber);
    return 0;
}