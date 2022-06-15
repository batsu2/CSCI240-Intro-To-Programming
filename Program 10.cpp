/***************************************************************
CSCI 240         Program 10     Fall 2017

Programmer: Bryan Butz

Section: CSCI 240  2pm-3:15pm

Date Due: 12/08/17

Purpose: Use the seller class to alter and display information
		 while incorperating cstrings
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>  

using namespace std;

class Seller
{
public:
  Seller();
  Seller( const char [], const char[], const char [], double );
    
  void print();

  void setFirstName( const char [] );
  void setLastName( const char [] );
  void setID( const char [] );
  void setSalesTotal( double );

  double getSalesTotal();

private:
  char firstName[20];
  char lastName[30];
  char ID[7];
  double salesTotal;
};


int main()
{
   Seller sell1("Bryan", "Butz", "CSI240", 1234.56);      
   Seller sell2;                                     //Calls the default constructor
   Seller sell3("", "Johnson", "TOOBIG999", 876.34);      
   Seller sell4("Jame", "Hellwig", "ULTWAR", 13579.11);
   Seller sell5("Roderick", "Toombs", "PIPER4", 24680.24);
   
   cout<<"*** The first Seller object ***\n";       //Seller 1: Displays all information
   sell1.print();
   cout<<endl;
   
   cout<<"\n*** The second Seller object ***\n";     //Seller 2: Calls default constructor, prints,
   sell2.print();                                    //then fills in the first name, last name, ID, 
   sell2.setFirstName("Terry");                      //and sales total then reprints
   sell2.setLastName("Bollea"); 
   sell2.setID("HULK96");
   sell2.setSalesTotal(246.80);
   
   sell2.print();
   cout<<endl;
   
   cout<<"\n*** The third Seller object ***\n";        //Seller 3: Prints, then will alter the 
   sell3.print();                                      //seller's first name and ID, then reprints
   sell3.setFirstName("Dwayne");
   sell3.setID("ROCK89");
   
   sell3.print();
   cout<<endl;
   
   cout<<"\n*** The fourth Seller object ***\n";      //Seller 4: Calls the getSalesTotal method 
   sell4.getSalesTotal();                             //and only prints the seller's sales total
   cout<<endl;
   
   cout<<"\n*** The fifth Seller object ***\n";      //Seller 5: Prints, then replaces the first name,
   sell5.print();                                    //last name, and ID to nothing. Sales total is changed
   sell5.setFirstName("");                           //to a false value, should output as 3 "None"s and "$0.00"
   sell5.setLastName("");
   sell5.setID("");
   sell5.setSalesTotal(-19.88);
   sell5.print();
   cout<<endl;
   
return 0;	
}

/***************************************************************
Method:  Seller()

Use: This is the default constructor method

Arguments: None

Returns: Nothing
***************************************************************/
Seller::Seller()
{
	setFirstName("None");
	setLastName("None");
	setID("ZZZ000");
	setSalesTotal(0);
}

/***************************************************************
Method:  Seller(const char [], const char[], const char [], double)

Use: This is the constructor for the Seller class

Arguments: 4, a character array representing the first name, a 
		   character array representing the last name, a character
		   array representing the ID, and a double representing the
		   sales total

Returns: Nothing
***************************************************************/
Seller::Seller(const char newFirstName[], const char newLastName[], const char newID[], double newSalesTotal)
{
   setFirstName(newFirstName);
   setLastName(newLastName);
   setID(newID);
   setSalesTotal(newSalesTotal);
   
}

/***************************************************************
Method:  Print()

Use: Displays the Seller information

Arguments: None

Returns: Nothing
***************************************************************/
void Seller::print()
{
	char name[40] = "";
	strcat(name, lastName);     //Concatenates both first and last name
	strcat(name,", ");          //along with a comma to retain a clean format
	strcat(name, firstName);
	cout<<left<<setw(35)<<name<<ID<<"               $"<<fixed<<setprecision(2)<<salesTotal<<endl;
}

/***************************************************************
Method:  void setFirstName(const char newFirstName[])

Use: This changes a Seller's first name

Arguments: 1, an array of characters representing the Seller's
		   first name

Returns: Nothing
***************************************************************/
void Seller::setFirstName(const char newFirstName[])
{
	if( strlen( newFirstName ) > 0 )   //Measures and compares first name's length
    {
        strcpy( firstName, newFirstName );   //If valid, changes to passed in value
    }
     else
    {
       strcpy( firstName, "None" );         //If fed in value is blank, changes to "None"
    }
}

/***************************************************************
Method:  void setLastName(const char newLastName[])

Use: This changes the Seller's last name

Arguments: 1, an array of characters representing the Seller's
		   last name

Returns: Nothing
***************************************************************/
void Seller::setLastName(const char newLastName[])
{
	if( strlen( newLastName ) > 0 )    //Measures and compares last name's length
    {
        strcpy( lastName, newLastName );  //If valid, changes to passed in value
    }
     else
    {
       strcpy( lastName, "None" );      //If fed in value is blank, changes to "None"
    }
}

/***************************************************************
Method:  void setID(const char newID[])

Use: This changes a Seller's ID number

Arguments: 1, an array of characters that represent the Seller's
		   ID number

Returns: Nothing
***************************************************************/
void Seller::setID(const char newID[])
{
	if( strlen( newID ) > 0 && strlen( newID ) < 7 )  //Measures and compares ID's length
    {
        strcpy( ID, newID );      //If valid, changes to passed in value
    }
     else
    {
       strcpy( ID, "ZZZ000" );     //If ID's length isn't a valid length, changes to "ZZZ000"
    }
}

/***************************************************************
Method:  void setSalesTotal(double newSalesTotal)

Use: This changes a Seller's sales total

Arguments: 1, a double that represents the Seller's sales total

Returns: Nothing
***************************************************************/
void Seller::setSalesTotal(double newSalesTotal)
{
	if(  newSalesTotal >= 0 )      //Checks for bogus values (less than 0)
    {
        salesTotal = newSalesTotal;    //If valid, changes to passed in value
    }
     else
    {
       salesTotal = 0;        //If passed in value is negative, changes to 0
    }
}

/***************************************************************
Method:  double getSalesTotal()

Use: This returns a Seller's sales total data

Arguments: None

Returns: 1, a double representing the sales total
***************************************************************/
double Seller::getSalesTotal()
{
	cout<<"Sales total is $"<<salesTotal;
	cout<<endl;
}

