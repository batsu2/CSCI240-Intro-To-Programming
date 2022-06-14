/***************************************************************
CSCI 240         Program 8     Fall 2017

Programmer: Bryan Butz

Section: CSCI 240  2pm-3:15pm

Date Due: 11/10/17

Purpose: Play a dice game while incorperating classes
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

char wager;
int timesRolled;
int sum;
int playerScore;
int dealerScore;
int evenOdd;

class Die
 {
	public:
		void roll();
		int getValue();
		void draw();   //Extra Credit Attempt
		
	private:
		int value;
		static const int NUM_SIDES;	
 };
 
const int Die::NUM_SIDES = 6;

int main()
{
srand(35);

cout<<"How many times should the dice be rolled? ";
cin>>timesRolled;

cout<<"\nWill the sum of the rolls be (E)ven or (O)dd? ";
cin>>wager;
cout<<endl;

Die die1;
Die die2;
die1.roll();   //Adds default values to the dice (overwritten upon entering loop)
die2.roll();   //Otherwise 1st roll will come out 6 & 3

for(int i= 0; i < timesRolled; i++)
 {
	die1.roll();
	die2.roll();
		
	die1.draw();
	die2.draw();
	sum = die1.getValue() + die2.getValue();
 
	evenOdd = sum % 2;  //Determines if sum is even or odd

//If dice roll is even
	if (evenOdd == 0)
	{
 	 if (wager == 'E' || wager == 'e')
      {
	  	cout<<"You won!\n\n";
	  	playerScore++;
	  }
 	else if (wager == 'O' || wager == 'o')
      {
       	cout<<"Dealer won.\n\n";
      	dealerScore++;
	  }
    }

//If dice roll is odd
	if (evenOdd == 1)
    {
 	 if (wager == 'O' || wager == 'o')
 	   {
 	   cout<<"You won!\n\n";
	   playerScore++;	
	   }
 	else if (wager == 'E' || wager == 'e')
 	   {
 	   cout<<"Dealer won.\n\n";
 	   dealerScore++;
	   }
 	}
 
 }

cout<<"Your final score is "<<playerScore<<" points.\n";
cout<<"Dealer's final score is "<<dealerScore<<" points.\n";

 //Determining the Winner
if(playerScore > dealerScore)     
 cout<<"You won the game!\n";
else if (playerScore < dealerScore)
 cout<<"Dealer won the game\n"; 
else if (playerScore == dealerScore)
 cout<<"Tie game\n"; 

return 0;
}

/***************************************************************
Method:  void roll()

Use: This constructor method simulates the rolling of the die

Arguments: None

Returns: Nothing
***************************************************************/
void Die:: roll()
{
 value = 1 + (rand() % NUM_SIDES);	//Generates a random number between 1 & 6
}
/***************************************************************
Method:  int getValue()

Use: This accessor method returns the current die value

Arguments: None

Returns: An integer, the dice value
***************************************************************/
int Die:: getValue()
{
 return value;	
}

/***************************************************************
Method:  void draw()         +Extra Credit

Use: This method "draws" the side of the die that is currently up

Arguments: None

Returns: None
***************************************************************/
void Die:: draw()
{
 switch (getValue())
 {
 	case 1: 
 			cout<<" ----- \n";
 			cout<<"|     |\n";
 			cout<<"|  O  |\n";
 			cout<<"|     |\n";
 			cout<<" ----- \n";
 			break;
 	case 2:
 			cout<<" ----- \n";
 			cout<<"|O    |\n";
 			cout<<"|     |\n";
 			cout<<"|    O|\n";
 			cout<<" ----- \n";
 			break;
 	case 3:
 			cout<<" ----- \n";
 			cout<<"|O    |\n";
 			cout<<"|  O  |\n";
 			cout<<"|    O|\n";
 			cout<<" ----- \n";
 			break;
 	case 4: 
 			cout<<" ----- \n";
 			cout<<"|O   O|\n";
 			cout<<"|     |\n";
 			cout<<"|O   O|\n";
 			cout<<" ----- \n";
 			break;
 	case 5:
 			cout<<" ----- \n";
 			cout<<"|O   O|\n";
 			cout<<"|  O  |\n";
 			cout<<"|O   O|\n";
 			cout<<" ----- \n";
 			break;
 	case 6:
 			cout<<" ----- \n";
 			cout<<"|O   O|\n";
 			cout<<"|O   O|\n";
 			cout<<"|O   O|\n";
 			cout<<" ----- \n";
 			break;
 			
 	default: cout<<"There was a problem displaying the dice\n";
 			break;
 }
}
