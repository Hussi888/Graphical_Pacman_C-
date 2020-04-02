#include "mygraphics.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
using namespace std;

const int rows = 32;  //Number Of Rows
const int column = 28; //Number of Columns
int pacROW = 15, pacCOLUMN = 0; //Position of pacman in row & column position
int ghostROW = 16, ghostCOLUMN = 14; //Position of ghost1 in row & column position
int i = 0, j = 0; //Initialisation of Rows & Columns 
char key; //Initialising For function getKeyS();
int score = 0;

void getKeyS(); //Function Prototypes
void Ghost();
bool ghostUP();
bool ghostDOWN();
bool ghostLEFT();
bool ghostRIGHT();


char level[rows][column] =
{
	{ 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1 },
	{ 1, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46,  1,  1, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46,  1 },
	{ 1, 46,  1,  1,  1,  1, 46,  1,  1,  1,  1,  1, 46,  1,  1, 46,  1,  1,  1,  1,  1, 46,  1,  1,  1,  1, 46,  1 },
	{ 1,  79,  1,  1,  1,  1, 46,  1,  1,  1,  1,  1, 46,  1,  1, 46,  1,  1,  1,  1,  1, 46,  1,  1,  1,  1,  79,  1 },
	{ 1, 46,  1,  1,  1,  1, 46,  1,  1,  1,  1,  1, 46,  1,  1, 46,  1,  1,  1,  1,  1, 46,  1,  1,  1,  1, 46,  1 },
	{ 1, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46,  1 },
	{ 1, 46,  1,  1,  1,  1, 46,  1,  1, 46,  1,  1,  1,  1,  1,  1,  1,  1, 46,  1,  1, 46,  1,  1,  1,  1, 46,  1 },
	{ 1, 46,  1,  1,  1,  1, 46,  1,  1, 46,  1,  1,  1,  1,  1,  1,  1,  1, 46,  1,  1, 46,  1,  1,  1,  1, 46,  1 },
	{ 1, 46, 46, 46, 46, 46, 46,  1,  1, 46, 46, 46, 46,  1,  1, 46, 46, 46, 46,  1,  1, 46, 46, 46, 46, 46, 46,  1 },
	{ 1,  1,  1,  1,  1,  1, 46,  1,  1,  1,  1,  1, 000,  1,  1, 000,  1,  1,  1,  1,  1, 46,  1,  1,  1,  1,  1,  1 },
	{ 1,  1,  1,  1,  1,  1, 46,  1,  1,  1,  1,  1, 000,  1,  1, 000,  1,  1,  1,  1,  1, 46,  1,  1,  1,  1,  1,  1 },
	{ 1,  1,  1,  1,  1,  1, 46,  1,  1, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,  1,  1, 46,  1,  1,  1,  1,  1,  1 },
	{ 1,  1,  1,  1,  1,  1, 46,  1,  1, 000,  1,  1, 000, 000, 000, 000,  1,  1, 000,  1,  1, 46,  1,  1,  1,  1,  1,  1 },
	{ 1,  1,  1,  1,  1,  1, 46,  1,  1, 000,  1, 000, 000, 000, 000, 000, 000,  1, 000,  1,  1, 46,  1,  1,  1,  1,  1,  1 },
	{ 1,  1,  1,  1,  1,  1, 46,  1,  1, 000,  1, 000, 000, 000, 000, 000, 000,  1, 000,  1,  1, 46,  1,  1,  1,  1,  1,  1 },
	{ 074, 000, 000, 000, 000, 000, 46, 000, 000, 000,  1, 000, 000, 000, 000, 000, 000,  1, 000, 000, 000, 46, 000, 000, 000, 000, 000, 000 },
	{ 1,  1,  1,  1,  1,  1, 46,  1,  1, 000,  1, 000, 000, 000, 000, 000, 000,  1, 000,  1,  1, 46,  1,  1,  1,  1,  1,  1 },
	{ 1,  1,  1,  1,  1,  1, 46,  1,  1, 000,  1, 000, 000, 000, 000, 000, 000,  1, 000,  1,  1, 46,  1,  1,  1,  1,  1,  1 },
	{ 1,  1,  1,  1,  1,  1, 46,  1,  1, 000,  1,  1, 000, 000, 000, 000,  1,  1, 000,  1,  1, 46,  1,  1,  1,  1,  1,  1 },
	{ 1,  1,  1,  1,  1,  1, 46,  1,  1, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,  1,  1, 46,  1,  1,  1,  1,  1,  1 },
	{ 1,  1,  1,  1,  1,  1, 46,  1,  1, 000,  1,  1,  1,  1,  1,  1,  1,  1, 000,  1,  1, 46,  1,  1,  1,  1,  1,  1 },
	{ 1, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46,  1,  1, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46,  1 },
	{ 1, 46,  1,  1,  1,  1, 46,  1,  1,  1,  1,  1, 46,  1,  1, 46,  1,  1,  1,  1,  1, 46,  1,  1,  1,  1, 46,  1 },
	{ 1, 46,  1,  1,  1,  1, 46,  1,  1,  1,  1,  1, 46,  1,  1, 46,  1,  1,  1,  1,  1, 46,  1,  1,  1,  1, 46,  1 },
	{ 1,  79, 46, 46,  1,  1, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46,  1,  1, 46, 46,  79,  1 },
	{ 1,  1,  1, 46,  1,  1, 46,  1,  1, 46,  1,  1,  1,  1,  1,  1,  1,  1, 46,  1,  1, 46,  1,  1, 46,  1,  1,  1 },
	{ 1,  1,  1, 46,  1,  1, 46,  1,  1, 46,  1,  1,  1,  1,  1,  1,  1,  1, 46,  1,  1, 46,  1,  1, 46,  1,  1,  1 },
	{ 1, 46, 46, 46, 46, 46, 46,  1,  1, 46, 46, 46, 46,  1,  1, 46, 46, 46, 46,  1,  1, 46, 46, 46, 46, 46, 46,  1 },
	{ 1, 46,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 46,  1,  1, 46,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 46,  1 },
	{ 1, 46,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 46,  1,  1, 46,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 46,  1 },
	{ 1, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46,  1 },
	{ 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1 }
}; //Level 2D Array

char ghost = level[ghostROW][ghostCOLUMN]; //Putting ghost within the array
char ghostblack = ghost[&ghostROW][&ghostCOLUMN]; //Putting black body underneath to remove any carries
int lives = 3; //Lives Counter
clock_t startTime = 0, endTime = 0; //Timer for dots functions
bool superDOT = false; //Power up dot for Pacman
bool Dot = false; //Bool check for all food(dot)



int main() {
	
	HANDLE  hConsole;
	int k = 14; //Colour constant
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k); //Colouring yellow
	char key = 0; //For function getKeyS();
	int Dots = 30; //Total number of food(dots)
	bool Counting = false; //Bool check for all rows and columns

	do {
		gotoxy(0, 0); //Start at (0,0)
		Ghost(); //Ghost Printing and its motion
		Ghost2(); //Ghost Printing and its motion
		for (i = 0; i <= 31; i++) { //Loop for Rows Printing
			for (j = 0; j <= 27; j++) { //Loop for Columns Printing
			
				cout << level[i][j]; //Printing Array
				if (j == 27) {
					cout << endl; //Move to next row
				}
				if (j == 27 && i == 31) { //Bool true for all rows & columns
					Counting = true;
				}
			}
		}
		getKeyS(); //Taking in movement from keys
		cout << "lives Left " << lives << endl; //Printing Remaining Lives
		cout << "Score is " << score << endl; //Printing Score
		
	} while (lives >= 0); //Repeat until lives equals/less then 0

	system("pause");
	return 0;
};

bool ghostUP() {
	char ghostUp = level[ghostROW - 1][ghostCOLUMN]; //Moving to upper row  
	if (ghostUp != 1) { //Check if a wall is not present on upper row
		if (ghostUp == 46 || ghostUp == 117) { //Check for food(dot) in current block of pacman
			level[ghostROW - 1][ghostCOLUMN] = 87; //Putting the food(dot) back in the array
			level[ghostROW][ghostCOLUMN] = ghostblack; //Erasing the the trail left of ghost
			ghostROW--;//Decrement in row for again checking 
		}
		else {  //Check if ghost ate pacman
			Dot = false; //Reimburse all all dots
			level[ghostROW][ghostCOLUMN] = 000; //Return ghost to its original position
			level[ghostROW - 1][ghostCOLUMN] = 87; //Move ghost to upper row
			ghostROW--;//Decrement to again check if ghost ate pacman or not
		}
		return true; //If both condition false then move on
	}
	else {
		return false; //Otherwise stop
	}
}


bool ghostDOWN() {

	char ghostDown = level[ghostROW + 1][ghostCOLUMN]; //Moving to down row
	if (ghostDown != 1) { //Check if a wall is not present on down row
		if (ghostDown == 46 || ghostDown == 117) { //Check for food(dot) in current block of pacman
			level[ghostROW + 1][ghostCOLUMN] = 87; //Move ghost to down row
			level[ghostROW][ghostCOLUMN] = ghostDown; //Erasing the trail of ghost
			ghostROW++; //Increment in row to again check
		}
		else { //Check if ghost ate pacman
			level[ghostROW][ghostCOLUMN] = 000; //Return ghost to its original position
			level[ghostROW + 1][ghostCOLUMN] = 87; //Move ghost to down row
			ghostROW++; //Increment in row to again check
		}
		return true; //If both condition false then move on
	}
	else {
		return false; //Otherwise stop
	}
}

bool ghostLEFT() {
	char ghostLeft = level[ghostROW][ghostCOLUMN - 1]; //Moving to left column
	if (ghostLeft != 1) { //Check if a wall is not present on left column
		if (ghostLeft == 46 || ghostLeft == 117) { //Check for food(dot) in current block of pacman
			level[ghostROW][ghostCOLUMN - 1] = 87; //Move ghost to left column
			level[ghostROW][ghostCOLUMN] = ghostLeft; //Erasing the trail of ghost
			ghostCOLUMN--; //Decrement in row for again checking 
		}
		else { //Check if ghost ate pacman
			level[ghostROW][ghostCOLUMN] = 000; //Return ghost to its original position
			level[ghostROW][ghostCOLUMN - 1] = 87; //Move ghost to left column
			ghostCOLUMN--; //Decrement in row for again checking 
		}
		return true; //If both condition false then move on
	}
	else {
		return false; //Otherwise stop
	}

}

bool ghostRIGHT() {
	char ghostRight = level[ghostROW][ghostCOLUMN + 1]; //Moving to right column
	if (ghostRight != 1) { //Check if a wall is not present on right column
		if (ghostRight == 46 || ghostRight == 117) { //Check for food(dot) in current block of pacman
			level[ghostROW][ghostCOLUMN + 1] = 87; //Move ghost to right column
			level[ghostROW][ghostCOLUMN] = ghostRight; //Erasing the trail of ghost
			ghostCOLUMN++; //Increment in row for again checking 
		}
		else {  //Check if ghost ate pacman
			level[ghostROW][ghostCOLUMN] = 000; //Return ghost to its original position
			level[ghostROW][ghostCOLUMN + 1] = 87; //Move ghost to right column
			ghostCOLUMN++; //Increment in row for again checking 
		}
		return true; //If both condition false then move on
	}
	else {
		return false; //Otherwise stop
	}

}

void Ghost() {
	if (superDOT) { //If pacman ate SuperDot
		if (pacROW > ghostROW) { //Check if pacman is in upper row of ghost
			!ghostUP(); //Change ghostUP to false
		}
		else if (pacROW < ghostROW) { //Check if pacman is in down row of ghost
			!ghostDOWN();  //Change ghostDOWN to false
		}
		if (pacCOLUMN > ghostCOLUMN) { //Check if pacman is in left column of ghost
			!ghostLEFT(); //Change ghostLEFT to false
		}
		else if (pacCOLUMN < ghostCOLUMN) { //Check if pacman is in right column of ghost
			!ghostRIGHT(); //Change ghostRIGHT to false
		}
	}
	
	else {
		if (pacROW < ghostROW) { //Check if ghost is in upper row of pacman		
			!ghostUP(); //Change ghostUP to false
		}
		else if (pacROW > ghostROW) { //Check if ghost is in down row of pacman
			!ghostDOWN(); //Change ghostDOWN to false
		}
		if (pacCOLUMN < ghostCOLUMN) { //Check if ghost is in left column of pacman
			!ghostLEFT(); //Change ghostLEFT to false
		}
		else if (pacCOLUMN > ghostCOLUMN) { //Check if ghost is in right column of pacman
			!ghostRIGHT(); //Change ghostRIGHT to false
		}
	}
	if (pacCOLUMN == ghostCOLUMN && pacROW == ghostROW && superDOT) { //Check if Pacman caught the ghost and reset position
		level[ghostROW][ghostCOLUMN] = 074; //Repalace position of ghost with pacman
		ghostROW = 16; //Revert ghost ROW position to starting one
		ghostCOLUMN = 14; //Revert ghost COLUMN position to starting one
		level[16][14] = 87; //Changing number back to Ghost's one & reseting ghost's position
	}
	else if (pacCOLUMN == ghostCOLUMN && pacROW == ghostROW) { //RESET PACMAN POSITION if not superDOT and it dies
		lives--; //Decrement in Lives
		level[pacROW][pacCOLUMN] = 000; //Replacing ghost number with pacman
		level[ghostROW][ghostCOLUMN] = 000; //Sending ghost back to its original number 
		pacROW = 15; //Revert pacman ROW position to starting one
		pacCOLUMN = 0; //Revert pacman column position to starting one
		ghostROW = 16; //Revert ghost ROW position to starting one
		ghostCOLUMN = 14; //Revert ghost COLUMN position to starting one
		level[15][0] = 074; //Assigning original number to PAcman
		level[16][14] = 87; //Assigning Original number to GHost
	}
}

void getKeyS() {
	key = _getch(); //Using get character funtion to take input
	char pacTemp = '<'; //Assingning this shape to PAcman
	if (key == 0 || key == -32) { //Check if any wrong key is pressed
		key = _getch(); //Now again take input

		if (key == 72) { //Check when up key is pressed
			if (level[pacROW - 1][pacCOLUMN] != 1) { //Check if wall is not there for pacman
				if (level[pacROW - 1][pacCOLUMN] == 79) { //Check if superDot is there
					startTime = clock(); //Start the timer
					endTime = clock();
					superDOT = true; //Return true for superDot
				}
				if (level[pacROW - 1][pacCOLUMN] == 46) { //Check for PAcman eating dots(food)
					score++;
				}
				level[pacROW][pacCOLUMN] = 000; //Change previous position black
				level[pacROW - 1][pacCOLUMN] = 118; //Change pacman to PACup ASCII
				pacROW--; //Decrement in column to again check
			}
		}
		else if (key == 75) { //Check when left key is pressed
			if (level[pacROW][pacCOLUMN - 1] != 1) { //Check if wall is not there for pacman
				if (level[pacROW][pacCOLUMN - 1] == 79) { //Check if superDot is there
					startTime = clock(); //Start the timer
					endTime = clock();
					superDOT = true; //Return true for superDot
				}
				if (level[pacROW][pacCOLUMN-1] == 46) { //Check for PAcman eating dots(food)
					score++;
				}
				level[pacROW][pacCOLUMN] = 000; //Change previous position black
				level[pacROW][pacCOLUMN - 1] = 076; //Change pacman to PACleft ASCII
				pacCOLUMN--; //Decrement in column to again check
			}
		}
		else if (key == 77) { //Check when right key is pressed
			if (level[pacROW][pacCOLUMN + 1] != 1) { //Check if wall is not there for pacman
				if (level[pacROW][pacCOLUMN + 1] == 79) { //Check if superDot is there
					startTime = clock(); //Start the timer
					endTime = clock();
					superDOT = true; //Return true for superDot
				}
				if (level[pacROW][pacCOLUMN + 1] == 46) { //Check for PAcman eating dots(food)
					score++;
				}
				level[pacROW][pacCOLUMN] = 000; //Change previous position black
				level[pacROW][pacCOLUMN + 1] = 074; //Change pacman to PACright ASCII
				pacCOLUMN++; //Increment in column to again check
			}
		}
		else if (key == 80) { //Check when down key is pressed
		
			if (level[pacROW + 1][pacCOLUMN] != 1) { //Check if wall is not there for pacman
				if (level[pacROW + 1][pacCOLUMN] == 79) { //Check if superDot is there
					startTime = clock(); //Start the timer
					endTime = clock();
					superDOT = true; //Return true for superDot
				}
				if (level[pacROW + 1][pacCOLUMN] == 46) { //Check for PAcman eating dots(food)
					score++;
				}
				level[pacROW][pacCOLUMN] = 000; //Change previous position black
				level[pacROW + 1][pacCOLUMN] = 94; //Change pacman to PACdown ASCII
				pacROW++; //Increment in column to again check
			}
		}
	}
}




