/* -------------------------------------------
Name: Priya Khatri
Student number: 110149176
Email: pkhatri4@myseneca.ca
Section:
Date: 11/16/2018
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include  "contacts.h"
#include "contactHelpers.h"

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause()
{
	printf("(Press Enter to Continue)");
	clearKeyboard();

}

// getInt function definition goes here: 
int getInt()
{
	char c;
	int i, check = 1, rc;
	do {
		rc = scanf("%d%c", &i, &c);

		if (rc == 0 || c != '\n')
		{

			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			clearKeyboard();
		}

		else check = 0;
	} while (check == 1);
	return i;
}


// getIntInRange function definition goes here:
int getIntInRange(low, high)  //receiving min=100 and high=500 from tstintiger
{
	int value, check = 1;
	do
	{
		value = getInt();
		if (value < low || value > high)
		{
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", low, high);

		}
		else check = 0;
	} while (check == 1);
	return value;
}
// yes function definition goes here:
int yes()  // this function checks the inserted data and return value that allowed to proceed more or exit ther by returning 1 or 0//
{
	char a, b;
	scanf("%c%c", &a, &b);

	while ((a != 'Y' || a != 'y' || a != 'N' || a != 'n') && b != '\n')
	{

		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		clearKeyboard();
		scanf("%c%c", &a, &b);
	}
	if ((a == 'Y' || a == 'y') && b == '\n')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


// menu function definition goes here:
int menu()

{
	int choice;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");

	do
	{
		choice = getIntInRange(0, 6); 
		if (choice > 6 || choice < 0)
		{
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
		}
	} while (choice > 6 || choice < 0);

	return choice;
}




// contactManagerSystem function definition goes here:
void contactManagerSystem()
{
	int valid = 0;
	int e, f;
	while (valid == 0) {
		e = menu();
		printf("\n");
		switch (e)
		{
		case 1:
			printf("<<< Feature 1 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 2:
			printf("<<< Feature 2 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 3:
			printf("<<< Feature 3 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 4:
			printf("<<< Feature 4 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 5:
			printf("<<< Feature 5 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 6:
			printf("<<< Feature 6 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			f = yes();
			if (f == 1) 
			{
				printf("\nContact Management System: terminated\n");
				valid = 1;
				break;
			}
			else {
				printf("\n");
				break;
			}
		default:
			break;
		}
	}
}


