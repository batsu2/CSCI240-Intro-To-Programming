/***************************************************************
CSCI 240         Program 5    Fall 2017

Programmer: Bryan Butz

Section: CSCI 240  2pm-3:15pm

Date Due: 10/13/17

Purpose: Play Craps!

***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std; 

const int TWO=2;
const int THREE=3;
const int TWELVE=12;
int die1;
int die2;
int roll;
int i;
int point;
bool end; 
char playAgain='Y'; 

int main()
{
cout<<" \x3\x4Welcome to Craps!\x5\x6\n\n";   //Title and sleeper loop pause
for (i=1; i<=700000000; i++);
	
while(playAgain=='Y' or playAgain== 'y')      //Extra Credit While loop
{
 srand(8);
 end=0;
 
 while(end != 1)
  {
  die1 = 1 + (rand() % 6);   //Rolling come out roll
  die2 = 1 + (rand() % 6);
  roll = die1 + die2;
  
 cout<<"Your come out roll is "<<roll<<endl;  //Display come out roll and pause
 for (i=1; i<=500000000; i++);
 
  if (roll== 7 or roll==11)
   {
  	cout<<"Winner winner chicken dinner!\x1\n";
  	end=1;
   }
  else if (roll== TWO or roll== THREE or roll==TWELVE)
   { 
  	cout<<"Bummer, you crapped out!\n";
  	end=1;
   }
    else 
     {
   	  point=roll;
   	  cout<<"\nThe point is "<<point<<endl;  //Display point and pause
   	  for (i=1; i<=450000000; i++);
   	  while (end != 1)
   	     {
   	     	die1 = 1 + (rand() % 6);   //Rolling for the point
            die2 = 1 + (rand() % 6);
            roll = die1 + die2;
            
            cout<<"Your next roll is "<<roll<<endl;
			
			
             if (roll == point)
             {
              cout<<"You matched the point! You win! \x1\n";
              end=1;
		 	 }
			 else if (roll == 7)
			 {
			  cout<<"You seven'd out. Game Over\n";
			  end=1;
	     	 }
			
			for (i=1; i<=500000000; i++);
		 }
     }
  }
 
cout<<"\nWould you like to play again? Y or y : ";  //Extra credit
cin>>playAgain;	
cout<<endl;
}

return 0;
}
