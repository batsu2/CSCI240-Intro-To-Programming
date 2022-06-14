/***************************************************************
CSCI 240         Program 9     Fall 2017

Programmer: Bryan Butz

Section: CSCI 240  2pm-3:15pm

Date Due: 12/01/17

Purpose: Build parabolas and display information about them
		 while incorperating classes and methods
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath> 

using namespace std;

class Parabola
{
  public:
  	Parabola();           //Default constructor
	Parabola(double, double, double);  //Constructor
	
	void printEquation();    //prints the equation   example: 1.0x^2 + 4.0x + -5.0	
	
	void printConcavity();  //checks aCoeff to print "upward" or "downward"
	
	void printVertex();    //calls calcX() and calcY() and prints x and y coordinates
	                       //the vertex is the point where the parabola changes directions
	                       
	double calcX();       //returns the x coordinate
	double calcY();       //returns the y coordinate
	
	void printRoots();   //calls calcRoots and prints the number of roots 
						 //as well as the roots themselves
	                     
	int calcRoots( double &, double & );   //calls calDiscrim to get a value
										   //if positive is returned, 2 roots are calculated
										   //if 0, calculate left argument root
										   //if negative, do nothing with root calculations
	
	double calcDiscrim();   //passes back a value to calcRoots that calls this method
	void print();   //print calls the other print methods above, print roots, equation, etc
	
	
  private:
  	double aCoeff, bCoeff, cCoeff;
};



int main()
{
	cout<<" *** The first parabola ***\n\n";
	Parabola Parab1(1, 4, -5);                 
	Parab1.print();                           //Prints all information
	
	cout<<" *** The second parabola ***\n\n";
	Parabola Parab2(1, 0, 25);
	Parab2.print();                           //Prints all information
	
	cout<<" *** The third parabola ***\n\n";
	Parabola Parab3(-1, 2, -1);
	Parab3.printEquation();
	Parab3.printConcavity();                  //Prints only the equation and concavity 
	cout<<endl;
	
	cout<<" *** The fourth parabola ***\n\n";
	Parabola Parab4(-12, -2, 3);
	Parab4.printRoots();                      //Prints only the roots
	cout<<endl;
	
	cout<<" *** The fifth parabola ***\n\n";
	Parabola Parab5(12, 2, 3);
	Parab5.printEquation();                   //Prints only the equation and vertex coordinates
	Parab5.printVertex();
	
return 0;
}

/***************************************************************
Method:  Parabola()

Use: This is the default constructor method

Arguments: None

Returns: Nothing
***************************************************************/
Parabola:: Parabola()
{
   aCoeff = 0;
   bCoeff = 0;
   cCoeff = 0;
}

/***************************************************************
Method:  Parabola(double, double, double)

Use: This is the contructor for the Parabola class

Arguments: 3, double values representing the a-coefficient,
		   b-coefficient, and c-coefficient

Returns: Nothing
***************************************************************/
Parabola:: Parabola(double newACoeff, double newBCoeff, double newCCoeff)
{
   aCoeff = newACoeff;
   if (aCoeff == 0)     //If passed in 'A' value is 0, changes to 1
     aCoeff = 1;
   bCoeff = newBCoeff;
   cCoeff = newCCoeff;
}

/***************************************************************
Method:  void printEquation()

Use: Displays the parabola in the form of a quadratic equation
	 (ex. x^2+4x+4)

Arguments: None

Returns: Nothing
***************************************************************/
void Parabola:: printEquation()
{
	cout<<fixed<<setprecision(1)<< aCoeff <<"x^2 + "<< bCoeff<< "x + "<< cCoeff<<endl;  //Prints in the form Ax^2 + Bx + C 
}

/***************************************************************
Method:  void printConcavity()

Use: Displays the direction that the parabola opens

Arguments: None

Returns: Nothing
***************************************************************/
void Parabola:: printConcavity()
{
	if ( aCoeff > 0)     //If aCoeff is positive
	cout<<"   The parabola opens UPWARD\n";
	else if ( aCoeff < 0)   //If aCoeff is negative
	cout<<"   The parabola opens DOWNWARD\n";
}

/***************************************************************
Method:  void printVertex

Use: Displays the x & y-coordinate of the vertes of the parabola

Arguments: None

Returns: Nothing
***************************************************************/
void Parabola:: printVertex()
{
	cout<<"   Vertex Coordinates: ("<< calcX() <<", "<< calcY() <<")\n";  //calls calcX() and calcY() to output the vertex coordinates
}

/***************************************************************
Method:  double calcX()

Use: Calculates and returns the x-coordinate of the parabola's
	 vertex

Arguments: None

Returns: A double, the x-coordinate
***************************************************************/
double Parabola:: calcX()
{
	double xValue = - bCoeff / ( 2 * aCoeff );
	return xValue;
}

/***************************************************************
Method:  double calcY()

Use: Calculates and returns the y-coordinate of the parabolas
	 vertex

Arguments: None

Returns: A double, the y-coordinate
***************************************************************/
double Parabola:: calcY()
{
	cout<<fixed<<setprecision(3);
	double xValue = calcX();
    double yValue = ( aCoeff * ( xValue * xValue)) + (bCoeff * xValue) + cCoeff;
	return yValue;	
}

/***************************************************************
Method:  void printRoots()

Use: Displays the roots of the parabola (if they exist)

Arguments: None

Returns: Nothing
***************************************************************/
void Parabola:: printRoots()
{
	double root1, root2;
	int totalRoots = calcRoots(root1, root2);  //calls calcRoots and sends down refrences to determine
											   //the number of roots as well as the roots themselves
	
	if (totalRoots == 2)   //if discriminate is positive (number of roots is 2)
	{
	 cout<<fixed<<setprecision(3)<<"   There are two real roots with X-Coordinates "<<root1<<" and "<<root2<<endl;	
	}
	else if (totalRoots == 1)  //if discriminate is 0 (number of roots is 1)
	{
	cout<<fixed<<setprecision(3)<<"   There is one real root with X-Coordinate "<<root1<<endl;	
	}
	else     //if discriminate is negative (no roots)
	{
	cout<<"   There are NO real roots\n";	
	}
}

/***************************************************************
Method:  int calcRoots( double &, double & )

Use: Calculates the roots for a parabola (if they exist), and 
	 returns the nubmer of roots

Arguments: 2, a double refrence of root 1 and a double refrence of root 2

Returns: An integer, the number of roots
***************************************************************/
int Parabola:: calcRoots( double &root1Ref, double &root2Ref )
{
 	if (calcDiscrim() > 0)         //calls calcDiscrim and checks if it is positive
 	{
 	 root1Ref = ( -bCoeff + sqrt( calcDiscrim() )) / ( 2 * aCoeff );   
	 root2Ref = ( -bCoeff - sqrt( calcDiscrim() )) / ( 2 * aCoeff );
	 return 2;	
	}
	else if (calcDiscrim() == 0)   //calls calcDiscrim and checks if it equals 0
	{
	 root1Ref = ( -bCoeff + sqrt( calcDiscrim() )) / ( 2 * aCoeff );	
	 return 1;
	}
	else                      //all other cases (negative discriminate) results in no roots
	{
	 return 0;	
	}
}

/***************************************************************
Method:  double calcDiscrim()

Use: Calculates the value of the discriminant

Arguments: None

Returns: Double value, the value of the discriminate 
***************************************************************/
double Parabola:: calcDiscrim()
{
   double discrim = ( bCoeff * bCoeff )- 4 * aCoeff * cCoeff;
   return discrim;	
}

/***************************************************************
Method:  void print()

Use: Displays everything related to the parabola

Arguments: None

Returns: Nothing
***************************************************************/
void Parabola:: print()
{
	printEquation();
	printVertex();
	printConcavity();
	printRoots();
	cout<<endl;
}
