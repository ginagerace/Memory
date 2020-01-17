/* ------------------------------------------------
   prog2ggerac3.cpp
 
   Program #2: Memory game of guessing which X or O changed.
   Class: CS 141
   Author: Gina Gerace
   Lab: Tues 11am
   System:  C++ Windows DevC++

   Grading Rubric:

   50 Execution points
         5 Displays header info on screen when run
         5 Displays instructions
         5 Output is formatted as shown in sample output
         3 Handles both upper and lower case input
         2 Input of 'x' in first prompt exits program
         5 Input can be adjacent or have spaces between them
        15 Displayed boards all have odd parity in rows and columns
         5 Repeated input of 'r' gives new valid random board each time
         5 Gives appropriate end of program messages

   45 Programming Style (Given only if program runs substantially correctly)
         5 Program naming convention is followed
        10 Meaningful identifier names
        10 Comments: Has header.  Comments on each block of code
        10 Appropriate data and control structures (-20 if using arrays or strings)
        10 Code Layout: Appropriate indentation and blank lines
   ------------------------------------------------
*/

#include <iostream>    // For cin and cout
#include <cstdlib>     // For random number generator
#include <time.h>
using namespace std;

// Global variables
char p0,p1,p2,p3,p4,p5,
   	 p6,p7,p8,p9,p10,p11,
	 p12,p13,p14,p15,p16,p17,
	 p18,p19,p20,p21,p22,p23,
	 p24,p25,p26,p27,p28,p29,
	 p30,p31,p32,p33,p34,p35;
	 
// Function to print the board
void PrintBoard() 
{
	cout << endl << endl << "    1 2 3 4 5 6" << endl;
	cout << "  - - - - - - - -" << endl;
	cout << "A | "<<p0<<" "<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<" "<<p5<<" | A" << endl;
	cout << "B | "<<p6<<" "<<p7<<" "<<p8<<" "<<p9<<" "<<p10<<" "<<p11<<" | B" << endl;
	cout << "C | "<<p12<<" "<<p13<<" "<<p14<<" "<<p15<<" "<<p16<<" "<<p17<<" | C" << endl;
	cout << "D | "<<p18<<" "<<p19<<" "<<p20<<" "<<p21<<" "<<p22<<" "<<p23<<" | D" << endl;
	cout << "E | "<<p24<<" "<<p25<<" "<<p26<<" "<<p27<<" "<<p28<<" "<<p29<<" | E" << endl;
	cout << "F | "<<p30<<" "<<p31<<" "<<p32<<" "<<p33<<" "<<p34<<" "<<p35<<" | F" << endl;
	cout << "  - - - - - - - -" << endl;
	cout << "    1 2 3 4 5 6" << endl << endl;
}

// Function to randomely set characters to X or O	
char SetChar()
{
	int num = rand() % 2;
	char value;
	
	if (num == 0)
	{value = 'O';}
	else 
	{value = 'X';}	
	
	return value;
}	
 
 // Function to set all the rows
 void SetBoard() 
 {
 	p0 = SetChar(); p1 = SetChar(); p2 = SetChar(); p3 = SetChar(); p4 = SetChar(); p5 = SetChar();	
 	p6 = SetChar(); p7 = SetChar(); p8 = SetChar(); p9 = SetChar(); p10 = SetChar(); p11= SetChar();
	p12 = SetChar(); p13 = SetChar(); p14 = SetChar(); p15 = SetChar(); p16 = SetChar(); p17= SetChar();
	p18 = SetChar(); p19 = SetChar(); p20 = SetChar(); p21 = SetChar(); p22 = SetChar(); p23= SetChar();
	p24 = SetChar(); p25 = SetChar(); p26 = SetChar(); p27 = SetChar(); p28 = SetChar(); p29= SetChar();
	p30 = SetChar(); p31 = SetChar(); p32 = SetChar(); p33 = SetChar(); p34 = SetChar(); p35= SetChar();
 }
 
 // Function to check one row or column for odd parity
 bool CheckRowOrColumn(char a, char b, char c, char d, char e, char f)
 {
 	int counter = 0;
 	
 	if(a=='X')
 	{counter++;}
	if(b=='X')
 	{counter++;}
 	if(c=='X')
 	{counter++;}
 	if(d=='X')
 	{counter++;}
 	if(e=='X')
 	{counter++;}
 	if(f=='X')
 	{counter++;}
 	
 	if(counter%2 != 0)
 	{return true;}
 	else
 	{return false;}
 }
 
 // Function to check all the rows for odd parity
 bool CheckRows()
 {
 	int countRows = 0;
 	if(CheckRowOrColumn(p0,p1,p2,p3,p4,p5)==true)
  		{countRows++;}
	if(CheckRowOrColumn(p6,p7,p8,p9,p10,p11)==true)
 		{countRows++;} 		
 	if(CheckRowOrColumn(p12,p13,p14,p15,p16,p17)==true)
 		{countRows++;}
 	if(CheckRowOrColumn(p18,p19,p20,p21,p22,p23)==true)
 		{countRows++;}
 	if(CheckRowOrColumn(p24,p25,p26,p27,p28,p29)==true)
 		{countRows++;}
 	if(CheckRowOrColumn(p30,p31,p32,p33,p34,p35)==true)
 		{countRows++;}
 		
 	if(countRows==6)
 	{return true;}
 	else
 	{return false;}
 }

// Fuction to check all the columns for odd parity
bool CheckCols()
 {
 	int countCols = 0;
 	if(CheckRowOrColumn(p0,p6,p12,p18,p24,p30)==true)
 		{countCols++;}
 	if(CheckRowOrColumn(p1,p7,p13,p19,p25,p31)==true)
 		{countCols++;}
 	if(CheckRowOrColumn(p2,p8,p14,p20,p26,p32)==true)
 		{countCols++;}
 	if(CheckRowOrColumn(p3,p9,p15,p21,p27,p33)==true)
 		{countCols++;}
 	if(CheckRowOrColumn(p4,p10,p16,p22,p28,p34)==true)
 		{countCols++;}
 	if(CheckRowOrColumn(p5,p11,p17,p23,p29,p35)==true)
 		{countCols++;}
 		
 	if(countCols==6)
 	{return true;}
 	else
 	{return false;}
 }
 
 // Function to check board for odd parity
 void FinalizeBoard() 
 {
 	do {
 		SetBoard();
	} while((CheckRows() && CheckCols()) == false);
 }
 
 // Function to change a value from 'X' to 'O' or vice versa
 void SwitchValue(char& chosen)
 {
 	if (chosen == 'X')
 	{chosen = 'O';}
 	else
 	{chosen = 'X';}
 }
 
 // Function to change the value chosen by player
 void ChangeValue(char row, char col)
 {
 	if(row == 'A')				// Check if value was in row A
 	{
 		if(col == '1')
 		{SwitchValue(p0);}
 		else if(col == '2')
 		{SwitchValue(p1);}
 		else if(col == '3')
 		{SwitchValue(p2);}
 		else if(col == '4')
 		{SwitchValue(p3);}
 		else if(col == '5')
 		{SwitchValue(p4);}
 		else if(col == '6')
 		{SwitchValue(p5);}
	}
	else if(row == 'B')				// Check if value was in row B
 	{
 		if(col == '1')
 		{SwitchValue(p6);}
 		else if(col == '2')
 		{SwitchValue(p7);}
 		else if(col == '3')
 		{SwitchValue(p8);}
 		else if(col == '4')
 		{SwitchValue(p9);}
 		else if(col == '5')
 		{SwitchValue(p10);}
 		else if(col == '6')
 		{SwitchValue(p11);}
	}
	else if(row == 'C')				// Check if value was in row C
 	{
 		if(col == '1')
 		{SwitchValue(p12);}
 		else if(col == '2')
 		{SwitchValue(p13);}
 		else if(col == '3')
 		{SwitchValue(p14);}
 		else if(col == '4')
 		{SwitchValue(p15);}
 		else if(col == '5')
 		{SwitchValue(p16);}
 		else if(col == '6')
 		{SwitchValue(p17);}
	}
	else if(row == 'D')				// Check if value was in row D
 	{
 		if(col == '1')
 		{SwitchValue(p18);}
 		else if(col == '2')
 		{SwitchValue(p19);}
 		else if(col == '3')
 		{SwitchValue(p20);}
 		else if(col == '4')
 		{SwitchValue(p21);}
 		else if(col == '5')
 		{SwitchValue(p22);}
 		else if(col == '6')
 		{SwitchValue(p23);}
	}	
	else if(row == 'E')				// Check if value was in row E
 	{
 		if(col == '1')
 		{SwitchValue(p24);}
 		else if(col == '2')
 		{SwitchValue(p25);}
 		else if(col == '3')
 		{SwitchValue(p26);}
 		else if(col == '4')
 		{SwitchValue(p27);}
 		else if(col == '5')
 		{SwitchValue(p28);}
 		else if(col == '6')
 		{SwitchValue(p29);}
	}
	else if(row == 'F')				// Check if value was in row F
 	{
 		if(col == '1')
 		{SwitchValue(p30);}
 		else if(col == '2')
 		{SwitchValue(p31);}
 		else if(col == '3')
 		{SwitchValue(p32);}
 		else if(col == '4')
 		{SwitchValue(p33);}
 		else if(col == '5')
 		{SwitchValue(p34);}
 		else if(col == '6')
 		{SwitchValue(p35);}
	}
 }
 
int main()
{
	// Display identifying information
        cout <<  "Author: Gina Gerace" << endl << "Lab: Tues. 11am" << endl
             << "Program: #2, Memory Game" << endl
             << endl;
        
        // Display the instuctions
        cout << "Welcome to the memory game!" << endl << endl 
			<< "Look away from the board and have a helper enter r" << endl
        	<< "to refresh the board until they have a random board" << endl
        	<< "that they like.  Then you glance at it and try to" << endl
        	<< "imprint it in your mind.  Your helper will then select" << endl
        	<< "the number of a single piece to be flipped by choosing" << endl
        	<< "its row and column.  You then must try to guess which" << endl
        	<< "one it was. Enter x to exit the program." << endl << endl;
	
	// Create variables for user input
	char userLetter;
	char userNumber;
	char guessLetter;
	char guessNumber;
	bool stillPlaying = true;
	
	srand(time(NULL));
	
	FinalizeBoard();
	
	// Get user input and perform correct action	
	while (stillPlaying == true) 
	{
		PrintBoard();
		cout << "Enter r to randomize to board, or row and column to change a value -> ";
		cin >> userLetter;
		userLetter = toupper (userLetter);
		
		if (userLetter == 'R')
		{FinalizeBoard();}
		else if (userLetter == 'X')
		{exit(0);}
		else if ((userLetter == 'A') || (userLetter == 'B') || (userLetter == 'C') || (userLetter == 'D') || (userLetter == 'E') || (userLetter == 'F'))
		{
			cin >> userNumber;
			ChangeValue(userLetter, userNumber);
			stillPlaying = false;
		}
		
	}
	
	// Print 25 blank lines and then show the updated board
	for(int i=0; i<25; i++)
	{cout << endl;}
	PrintBoard();
	
	// Prompt user to guess what value was changed
	cout << "What piece do you think it was? -> ";
	cin >> guessLetter >> guessNumber;
	guessLetter = toupper (guessLetter);
	
	// Check if the guess was correct and print end of game message
	if((guessLetter==userLetter) && (guessNumber==userNumber))
	{cout << endl << "*** Congratulations, you did it! ***" << endl;}
	else 
	{cout << endl << "Sorry, it was " << userLetter << userNumber << ". Better luck next time." << endl;}
	
	cout << endl << "Thank you for playing.  Exiting..." << endl;
	
	
	return 0;
}
