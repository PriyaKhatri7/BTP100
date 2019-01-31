/* -------------------------------------------
Name: Priya Khatri
Student number: 110149176
Email: pkhatri4@myseneca.ca
Section:
Date: 11/28/2018
----------------------------------------------
Assignment: 2
Milestone:  3
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>


// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}


// pause:
void pause()
{
	printf("(Press Enter to Continue)");
	clearKeyboard();

}

// getInt:
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


// getIntInRange:
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


// yes:
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


// menu:
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


// contactManagerSystem:
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


// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char telNum[])
{
    int needInput = 1;

    while (needInput == 1) {
        scanf("%10s", telNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(telNum) == 10)
            needInput = 0;
        else
            printf("Enter a 10-digit phone number: ");
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i, a = 0;
	for (i = 0; i < size; i++)
	{
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
			a = i;
	}
	if (a == 0)
		a = -1
	
	return a; 
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void) //displays header
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}



// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int totalContacts) //displays footer
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", totalContacts);
}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact) //displays contact info
{

	if (strcmp(contact->name.middleInitial, "") != 0)
		printf(" %s %s %s", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	else
		printf(" %s %s", contact->name.firstName, contact->name.lastName);

	printf("\n");

	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

	if (contact->address.apartmentNumber > 0)
		printf("       %d %s, Apt# %d, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);
	else
		printf("       %d %s, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);

}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact display[], int size) //displays valid contacts
{
	int i, a = 0;
	displayContactHeader();

	for (i = 0; i < size; i++)
	{
		if (strlen(display[i].numbers.cell) > 0)
		{
			displayContact(&display[i]);
			a++;
		}
	}

	displayContactFooter(a);

}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact search[], int size) //searches for a valid contact
{
	int a = 0;
	char n[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(n);

	a = findContactIndex(search, size, n);


	if (a == -1)
		printf("*** Contact NOT FOUND ***\n");
	else
	{
		printf("\n");
		displayContact(&search[a]);
		printf("\n");
	}

}


// addContact:
// Put empty function definition below:
void addContact(struct Contact add[], int size) //adds contact if there is space available
{
	int i, a = -2;
	for (i = 0; i < size; i++)
	{
		if (strlen(add[i].numbers.cell) == 0)
		{
			a = i;
			break;
		}
	}

	if (a > -1)
	{
		getContact(&add[a]);
		printf("--- New contact added! ---\n");
	}
	else
		printf("*** ERROR: The contact list is full! ***\n");
}



// updateContact:
// Put empty function definition below:
void updateContact(struct Contact update[], int size) //updates a contact
{
	char n[11];
	int a, b, c, d;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(n);

	a = findContactIndex(update, size, n);


	if (a == -1)
		printf("*** Contact NOT FOUND ***\n");
	else
	{
		printf("\n");
		printf("Contact found:");
		printf("\n");
		displayContact(&update[a]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		b = yes();

		if (b == 1)
			getName(&update[a].name);

		printf("Do you want to update the address? (y or n): ");
		c = yes();

		if (c == 1)
			getAddress(&update[a].address);

		printf("Do you want to update the numbers? (y or n): ");
		d = yes();

		if (d == 1)
			getNumbers(&update[a].numbers);

		printf("--- Contact Updated! ---\n");
	}

}

// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact delete[], int size) //deletes a contact
{
	char a, n[11];
	int b;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(n);

	b = findContactIndex(delete, size, n);

	if (b == -1)
		printf("*** Contact NOT FOUND ***\n");
	else
	{
		printf("\n");
		printf("Contact found:\n");

		displayContact(&delete[b]);

		printf("\nCONFIRM: Delete this contact? (y or n): ");
		a = yes();

		if (a == 1)
		{
			delete[b].numbers.cell[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}

	}

}

// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact sort[], int size) //sorts the contacts by cell phone number
{
	int i, a;
	struct Contact c;

	for (i = 0; i < size - 1; i++)
	{
		for (a = i + 1; a < size; a++)
		{
			if (strcmp(sort[i].numbers.cell, sort[a].numbers.cell) > 0)
			{
				c = sort[i];
				sort[i] = sort[a];
				sort[a] = c;
			}
		}
	}
}

