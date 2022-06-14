/***************************************************************
CSCI 240         Program 6     Fall 2017

Programmer: Bryan Butz

Section: CSCI 240  2pm-3:15pm

Date Due: 10/20/17

Purpose: Transmit values between functions & do work within 
		 those functions
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_VALS = 10;       //the maximum number of values to use

/********* Put the function prototypes below this line *********/
int sumDigits( int num );
int reverse( int num );
bool isPalindrome( int num );
bool isPrime( int num );

void numerology(); 		//EXTRA CREDIT+


int main()
{
int number,          //holds the random number that is manipulated and tested
    loopCnt;         //controls the loop

//set the seed value for the random number generator
//Note: a value of 1 will generate the same sequence of "random" numbers every
//      time the program is executed

srand(31);


//Generate 10 random numbers to be manipulated and tested

for( loopCnt = 1; loopCnt <= NUM_VALS; loopCnt++ )
  {
  //Get a random number
  number = rand();

  //Display the sum of adding up the digits in the random number, the reversed
  //random number, and whether or not the number is palindromic or a prime number
   
  cout << "The number is " << number << endl
       << "----------------------------------------" << endl
       << "Adding the digits result" << setw(16) << sumDigits( number ) << endl
       << "Reversing the digits result" << setw(13) << reverse(number) << endl
       << "Is the number a palindrome?" << setw(13) << (isPalindrome(number)? "Yes" : "No") << endl
       << "Is the number prime?" << setw(20) << (isPrime(number)? "Yes" : "No") << endl
	   << endl << endl;
  }

/** If the extra credit is being attempted, call the extra function below this line **/
numerology();


return 0;
}


/********* Code the functions below this line *********/

/***************************************************************
Function:  int sumDigits( int )

Use: This function adds up the individual digits of a number

Arguments: an integer, the number to be tested

Returns: an integer value that is the sum of a number's digits
***************************************************************/
int sumDigits( int number )
{
  int i=0, sum=0;

  while ( number != 0)
	{
	 i = number % 10;   	//determines the last digit in number and saves the value
	 number = number / 10;	//removes that last digit from the number
	 sum = sum + i;			//adds that last digit to overall sum
	}
	
 return ( sum );
}


/***************************************************************
Function:  int reverse( int )

Use: This function reverses the digit order of a given number

Arguments: an integer, the number to be tested

Returns: an integer value that represents the reverse order of
		 a number
***************************************************************/
int reverse( int number )
{
 int reverseNum = 0;
 int i = 0;
 
	while ( number != 0)     //executes as long as there are digits to be removed
     {
      reverseNum = reverseNum * 10;   
	  i = number % 10;				//determines the end digit and stores the value
	  reverseNum = reverseNum + i;	//adds i to total
	  number = number / 10;  		//removes the end digit from NUMBER
	 }
	
	number = reverseNum;
return ( number );	
}


/***************************************************************
Function:  bool isPalindrome( int )

Use: This function determines if a number is a palindrome

Arguments: an integer, the number to be tested

Returns: a boolean value that indicates if the number is a 
		 palindrome or not
***************************************************************/
bool isPalindrome( int number )
{
 int reverseNum;
 
 reverseNum = reverse( number );   //calls reverse() funtion 
 
 if ( reverseNum == number)        //compares the standard number with the reversed version
  number = true;
 else 
  number = false;
 
 return ( number );
}


/***************************************************************
Function:  bool isPrime( int )

Use: This function determines if a number is a prime number

Arguments: an integer, the number to be tested

Returns: a boolean value that indicates if the number is or
         is not prime
***************************************************************/
bool isPrime( int number )
{
  int count = 2;
  int half = (number / 2);
  
  while ( count <= half )
	{
		if (number % count == 0)  //divides number by count to determine remainder
		   
		   return (false);
		
		count++;
	}
	
 return ( true );
}

/***************************************************************
Function:  void numerology()    +Extra Credit

Use: This function takes in user input (dates) to determine the
	 person's numerology

Arguments: Nothing

Returns: Nothing 
***************************************************************/
void numerology ()
{
 int month, day, year, lifePath=0;
 
   while (lifePath > 2060 or lifePath==0)    //Loop checking for a valid date (before 12/31/2017)
   {
  	cout<<"Please enter your birthday in the form (mm/dd/yyyy): ";
 	cin >> month;
 	cin.ignore();
 	cin >> day;													  
 	cin.ignore();
 	cin >> year;
 	
 	lifePath = month + day + year;		//Adds month, day, and year into a workable, single integer
 	
 	if (lifePath > 2060)  
 	cout<<"YOU HAVE ENTERED AN INVALID DATE, PLEASE ENTER A DATE BEFFORE 12/31/2017\n\n";
   }
 	  while (lifePath >= 10)
 	   {
 	    	lifePath = sumDigits(lifePath);	 	//Cycles sumDigit Funciton until lifePath is < 10
	   }
	 
	 cout<<"\nYour Life Path number is: "<< lifePath <<endl;
	 cout<<"Your qualities are: ";
	 
	 switch (lifePath)     //Determines "Life Path" output
	 {
	 case 1: cout<<"individualistic, independent, and show leadership and drive\n";
	 	break;
	 case 2: cout<<"sensitive, tactful, diplomatic, and cooperative\n";
	 	break;
	 case 3: cout<<"creative and a good communicator\n";
	 	break;
	 case 4: cout<<"natural planner, fixer, and builder\n";
	 	break;
	 case 5: cout<<"energetic, adventurous, daring, and freedom-loving\n";
	 	break;
	 case 6: cout<<"responsible, loving, self-sacrificing, protective, and compassionate\n";
	 	break;
	 case 7: cout<<"gift for investigation, analysis, and keen observation\n";
	 	break;
	 case 8: cout<<"skills to lead, direct, organize and govern\n";
	 	break;
	 case 9: cout<<"helpful, compassionate, sophisticated and generous\n";
	 	break;
	 default: cout<<"THERE WAS A PROBLEM CALCULATING YOUR LIFE PATH, TRY AGAIN\n";
		break;
	}
}
