/***************************************************************
CSCI 240         Program 1     Fall 2017

Programmer: Bryan Butz

Section: CSCI 240  2pm-3:15pm

Date Due: 9/8/17

Purpose: This program calculates and displays a course average for
         the CSCI 240 course.
***************************************************************/

#include <iostream>
#include <iomanip>
using namespace std; 

float programAverage;
float testAverage;
float sum;

int main()
{
cout <<"Please enter program average: ";
cin >>programAverage;
cout <<"Please enter test average: ";
cin >>testAverage;

cout <<"\n***********************\n";
cout <<"Grade Calculator\n\n";
cout << left << setw(5) << "Program Average ";
cout << setw(5) << right << programAverage << endl;
cout << left << setw(5) << "Test Average    "; 
cout << setw(5) << right << testAverage << endl<<endl;

programAverage = programAverage * 0.3;
testAverage = testAverage * 0.7;
sum = programAverage + testAverage;

cout << "Course Average " << sum;
cout <<"\n***********************";

return 0;
}
