/***************************************************************
CSCI 240         Program 2    Fall 2017

Programmer: Bryan Butz

Section: CSCI 240  2pm-3:15pm

Date Due: 9/15/17

Purpose: Calculate course averages while incorperating more 
		 variables
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


int main()
{
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
cout <<"Please enter the sum of the two lowest quiz scores: ";
cin >>lowScoreSum;

	//calculating test average
testAverage= (testScoreSum + quizScoreSum - lowScoreSum) / (maxPoints + (10 * (quizzesTaken - 2))) * 100;

cout <<"\n***********************\n";
cout <<"Grade Calculator\n\n";
cout << left << setw(5) << "Program Average ";
cout << setw(5) << right << fixed << setprecision(2)<< programAverage << endl;
cout << left << setw(5) << "Test Average    "; 
cout << setw(5) << right << fixed << setprecision(2)<< testAverage << endl<<endl;

	//calculating Course Average
programAverage = programAverage * 0.3;
testAverage = testAverage * 0.7;
courseAverage = programAverage + testAverage;

cout << left << setw(5) <<"Course Average  ";
cout << setw(5) << right << fixed << setprecision(2)<< courseAverage;
cout <<"\n***********************";

return 0;
}
