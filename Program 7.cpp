/***************************************************************
CSCI 240         Program 7     Fall 2017

Programmer: Bryan Butz

Section: CSCI 240  2pm-3:15pm

Date Due: 11/03/17

Purpose: Building, printing, and sorting with arrays
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

double randDouble();
int buildArray( double [] );
void printArray( double [], int , string );
void sortArray( double [], int );

const double lowerBound = 0.0;
const double upperBound = 100.0;
const int minValue = 2;
const int maxValue = 49;
const int maxPerLine = 10;
int randNum;
int size;
int i=0;
int j=0;
string title = "Unsorted Random Numbers";


int main()
{

    double array1[50], array2[50];	
    srand(7); 
	
	size = buildArray(array1);               //Begin Array sequence 1
	
	cout<<"There are "<<size<<" values in the first array\n";
	
	printArray(array1, size, title);
	sortArray(array1, size);   
	title = "Sorted Random Numbers";
	printArray(array1, size, title);
	
	size = buildArray(array2);               //Begin Array sequence 2
	
	cout<<"\nThere are "<<size<<" values in the second array\n";
	title = "Unsorted Random Numbers";
	
	printArray(array2, size, title);
	sortArray(array2, size);
	title = "Sorted Random Numbers";
	printArray(array2, size, title);
	
return 0;	
}

/***************************************************************
Function:  int buildArray( double [] )

Use: This function fills an arraay of doubles with a random
	 number of random values

Arguments: Takes an array of doubles

Returns: An integer, the number of values that were placed in 
	 	 the array
***************************************************************/
int buildArray( double array1[] )
{
	
	int randVal = minValue + (rand() % maxValue);   //Generates a number between 2 & 50
	
	for(i=0; i < randVal; i++)         //Fills array with random values
	{
	  array1[i] = randDouble();	
	}
	
return (randVal);	
}

/***************************************************************
Function:  void printArray( double [], int, string )

Use: This function displays the numeric information in an array
	 of doubles

Arguments: An array of doubles that holds numbers to be displayed,
	 	   an integer that holds the number of values to be dis-
	 	   played, and a string that holds the title

Returns: Nothing
***************************************************************/
void printArray( double array1[], int size , string sorted)
{
	i=0;
	cout<<endl<< sorted <<endl<<endl;
	cout<<"------------------------------------------------------------\n";
	
	  while (i < size)
	   {
          for (j=0; j < maxPerLine && i < size; j++)     //Prints array while keeping no more than 10 per line
          {
		    cout<<right<<setw(5)<<fixed<<setprecision(1)<< array1[i]<<" ";   
		    i++;
          }
          cout<<endl;
	   }
	
}

/***************************************************************
Function:  void sortArray( double [], int )

Use: This function uses an algorithm to sorth the array in 
	 ascending order

Arguments: An array of doubles that holds the numbers to be sorted,
		   and an integer that holds the number of values to be 
		   sorted

Returns: Nothing
***************************************************************/
void sortArray( double array1[], int size)
{
	
double low;

for (int swapped =0; swapped != 1; swapped++)
 {
   swapped = 0;

   for (i =1; i < size; i++)     //starts at 1 and compares with previous entry
   {
      if (array1[i-1] > array1[i])    //moves larger values along
      { 
         low = array1[i];             //New low
         array1[i] = array1[i-1];
         array1[i-1] = low;          
         swapped = 1;              
      }
   }
 } 
	
}

/***************************************************************
Function:  doube randDouble()

Use: This funciton generates a random double value within a 
	 specific range

Arguments: None

Returns: A double, the randomly generated number
***************************************************************/
double randDouble()
{
randNum = rand();
double random = lowerBound + ( randNum / (RAND_MAX / (upperBound - lowerBound)));

return random;
}
