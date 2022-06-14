/***************************************************************
CSCI 240         Program 3    Fall 2017

Programmer: Bryan Butz

Section: CSCI 240  2pm-3:15pm

Date Due: 9/22/17

Purpose: Calculate course averages while incorperating If/Else 
		 Statements
***************************************************************/

#include <iostream>
#include <iomanip>
using namespace std; 

float programAverage;
float testAverage;
float courseAverage;
float testScoreSum;
float maxPoints;
int quizzesTaken;
int quizScoreSum;
int lowScoreSum;
char letterGrade;


int main()
{
cout <<"Extra Credit 1 and 2 Attempted\n";
	//Prompting for user information
cout <<"Please enter program average: ";
cin >>programAverage;
cout <<"\nPlease enter the sum of all test scores taken: ";
cin >>testScoreSum;
cout <<"Please enter the maximum test points available: ";
cin >>maxPoints;
cout <<"\nPlease enter the number of quizzes taken: ";
cin >>quizzesTaken;
cout <<"Please enter the sum of all quiz scores taken: ";
cin >>quizScoreSum;

if ( quizzesTaken > 2)
{
	cout <<"Please enter the sum of the two lowest quiz scores: ";
	cin >>lowScoreSum;
}

	//calculating test average
if ( quizzesTaken > 2)
{
 testAverage= (testScoreSum + quizScoreSum - lowScoreSum) / (maxPoints + (10 * (quizzesTaken - 2))) * 100;
}
else
{ 
 testAverage= (testScoreSum + quizScoreSum) / (maxPoints + (10 * quizzesTaken)) * 100;
}

cout <<"\n***********************\n";
cout <<"Grade Calculator\n\n";
cout << left << setw(5) << "Program Average ";
cout << setw(5) << right << fixed << setprecision(2)<< programAverage << endl;
cout << left << setw(5) << "Test Average    "; 
cout << setw(5) << right << fixed << setprecision(2)<< testAverage << endl<<endl;
	
	//calculating Course Average
courseAverage = (programAverage * 0.3) + (testAverage * 0.7);

cout << left << setw(5) <<"Course Average  ";
cout << setw(5) << right << fixed << setprecision(2)<< courseAverage << endl;

   //Calculating letter grade
if ( testAverage < 55.0 or programAverage < 55.0)
{
cout << "\nGrade: F - the program or test average is below 55%";
}
else
{
if (courseAverage <= 100 and courseAverage >= 90)
letterGrade='A';
else
	{
	if (courseAverage < 90 and courseAverage >= 80)
	letterGrade='B';
	else
		{
		if (courseAverage <= 80 and courseAverage >= 70)
		letterGrade='C';
		else
			{
			if (courseAverage <= 70 and courseAverage >= 60)
			letterGrade='D';
			else
				if (courseAverage <60 )
				letterGrade='F';
			}
		}
	}
cout << "\nGrade: " << letterGrade;
}

cout <<"\n***********************";

return 0;
}
