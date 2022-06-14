/***************************************************************
CSCI 240         Program 4    Fall 2017

Programmer: Bryan Butz

Section: CSCI 240  2pm-3:15pm

Date Due: 9/29/17

Purpose: Randomly generate number sets and determine if they're 
		 even or odd
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std; 

int executionNum;
int randNum;
int evenCount;
int oddCount;
int zeroes;
int totalNum;
int totalOdd;
int totalEven;
int totalZeroes;
const int MIN_GROUP_SIZE = 2;
const int MAX_GROUP_SIZE = 19;
const int MAX_GROUP_RANGE = 100;

int main()
{
 srand(1);
 
     //Loop 1: For Loop
executionNum = MIN_GROUP_SIZE + (rand() % MAX_GROUP_SIZE);
cout <<"The program will generate " << executionNum <<" numberes using a for loop\n"; 
 
int i;
for (i = 1; i <= executionNum; i++)
{
 randNum = rand() % MAX_GROUP_RANGE;
 cout << "   " << randNum;
 if (randNum == 0)
 {
  zeroes++;
 }
 else
 {
 	if ((randNum % 2) == 1)
 	{
 	oddCount++;	
	}
	else
	{
	 if ((randNum % 2) == 0)
	 evenCount++;
	}
 }
}
	//Adding to totals
totalNum = totalNum + executionNum;
totalEven = totalEven + evenCount;
totalOdd = totalOdd + oddCount;
totalZeroes = totalZeroes + zeroes;

cout<<"\n\nThere were "<< evenCount <<" even numbers, "<< oddCount <<" odd numbers, and " << zeroes <<" zeroes in the group of numbers.\n\n";
 

     //Loop 2: While Loop
executionNum = MIN_GROUP_SIZE + (rand() % MAX_GROUP_SIZE);
cout <<"\nThe program will generate " << executionNum <<" numberes using a while loop\n"; 

	//Reset Values
i=1;
zeroes=0;
oddCount=0;
evenCount=0;

while (i <= executionNum)
{
  randNum = rand() % MAX_GROUP_RANGE;
  cout<<"   "<< randNum;
  
   if (randNum == 0)
 {
  zeroes++;
 }
 else
 {
 	if ((randNum % 2) == 1)
 	{
 	oddCount++;	
	}
	else
	{
	 if ((randNum % 2) == 0)
	 evenCount++;
	}
 }
 
  i++;
}
	//Adding to totals
totalNum = totalNum + executionNum;
totalEven = totalEven + evenCount;
totalOdd = totalOdd + oddCount;
totalZeroes = totalZeroes + zeroes;

cout<<"\n\nThere were "<< evenCount <<" even numbers, "<< oddCount <<" odd numbers, and " << zeroes <<" zeroes in the group of numbers.\n\n";

     //Loop 3: Do While Loop
executionNum = MIN_GROUP_SIZE + (rand() % MAX_GROUP_SIZE);
cout <<"\nThe program will generate " << executionNum <<" numberes using a do/while loop\n"; 

	//Reset Values
i=1;
zeroes=0;
oddCount=0;
evenCount=0;

do
{
 randNum = rand() % MAX_GROUP_RANGE;
 cout<<"   "<< randNum;
  
   if (randNum == 0)
 {
  zeroes++;
 }
 else
 {
 	if ((randNum % 2) == 1)
 	{
 	oddCount++;	
	}
	else
	{
	 if ((randNum % 2) == 0)
	 evenCount++;
	}
 }


i++;	
}
while ( i <= executionNum);

	//Adding to totals
totalNum = totalNum + executionNum;
totalEven = totalEven + evenCount;
totalOdd = totalOdd + oddCount;
totalZeroes = totalZeroes + zeroes;

	//Visual number representation (Extra Credit)
cout<<"\n\nThere were "<< evenCount <<" even numbers, "<< oddCount <<" odd numbers, and " << zeroes <<" zeroes in the group of numbers.\n\n";

i=1;
cout<<"Overall, there were "<< totalNum << " numbers\n";
cout<<right<<setw(4)<< totalEven << " were even    ";
while (i <= totalEven)
{
	cout<< "*";
	i++;
}

i=1;
cout<<"\n"<<right<<setw(4) << totalOdd << " were odd     ";
while (i <= totalOdd)
{
	cout<< "*";
	i++;
}

i=1;
cout<<"\n"<<right<<setw(4)<<totalZeroes<< " were zeroes  ";
while (i <= totalZeroes)
{
	cout<< "*";
	i++;
}

return 0;
}
