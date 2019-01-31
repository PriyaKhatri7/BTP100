/* -------------------------------------------
Name: Priya Khatri
Student number: 110149176
Email: pkhatri4@myseneca.ca
Section:
Date: 11/28/2018

----------------------------------------------
Assignment: 2
Milestone:  4
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


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}


// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
	printf("\n");
}


// getInt:
int getInt(void)
{
	char nl;
	int value;
	int rc;
	int keeptrying = 1;
	do {
	rc = scanf("%d%c", &value, &nl);
	if (rc == 0 || nl != '\n')
	{
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		clearKeyboard();
	}

	else keeptrying = 0;
} while (keeptrying == 1);
	return value; }



// getIntInRange:
int getIntInRange(int low, int high) //checks if inputted integer is within user defined range
{
		int choice = getInt();

		if (choice > high || choice < low) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", low, high);
			choice = getInt(); } 
	return choice;
}

int yes(void) //gets input from user and checks if it is a valid type of answer (yes or no)
{
	char i,j;
	scanf("%c%c", &i, &j);

	
	if ((i == 'Y' || i == 'y') && j == '\n')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
	

// menu:
int menu(void) //contains menu options and returns users choice
{
#define LOW 0
#define HIGH 6

	int menu;

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
	do {
		menu = getInt();
		if (menu > 6 || menu < 0) {
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
		}
	} while (menu > 6 || menu < 0);

	return menu;
}

// ContactManagerSystem:
void contactManagerSystem(void) //contains the various options available
{
	struct Contact contact[MAXCONTACTS] = //structure of information
	{
		{
			{ "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
		{
			{ "Maggie", "R.", "Greene" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9051112222", "9052223333", "9053334444" } },
		{
			{ "Morgan", "A.", "Jones" },
	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
	{ "7051112222", "7052223333", "7053334444" } },
		{
			{ "Sasha",{ '\0' }, "Williams" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9052223333", "9052223333", "9054445555" } },

	};

	int selection;
	int yn = 0;
	while (yn == 0) {
		selection = menu();
		switch (selection)
		{
		case 1:
			printf("\n");
			displayContacts(contact, MAXCONTACTS); //calls the function displayContacts
			pause();
			printf("\n");

			break;

		case 2:
			printf("\n");
			addContact(contact, MAXCONTACTS); //calls the function addContact
			pause();
			printf("\n");


			break;

		case 3:
			printf("\n");
			updateContact(contact, MAXCONTACTS); //calls the function updateContact
			pause();
			printf("\n");

			break;

		case 4:
			printf("\n");
			deleteContact(contact, MAXCONTACTS); //calls the function deleteContact
			pause();
			printf("\n");

			break;

		case 5:
			printf("\n");
			searchContacts(contact, MAXCONTACTS); //calls the function searchContacts
			pause();
			printf("\n");

			break;

		case 6:
			printf("\n");
			sortContacts(contact, MAXCONTACTS); //calls the function sortContacts
			printf("--- Contacts sorted! ---\n");
			pause();
			printf("\n");

			break;


		case 0:
			printf("\n");
			printf("Exit the program? (Y)es/(N)o: ");
			yn = yes();
			printf("\n");

			if (yn)printf("Contact Management System: terminated\n");

			break;
		default:
			break;
		}
	}
}



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

void getTenDigitPhone(char telNum[])
{
	scanf("%s", telNum);
	clearKeyboard();

	while (strlen(telNum) != 10) {
		printf("Enter a 10-digit phone number: "); // (String Length Function: validate entry of 10 characters)
		scanf("%s", telNum);
		clearKeyboard();
			
	}
}

// findContactIndex:
int findContactIndex(const struct Contact cellPhoneNum[], int size, const char inputtedNum[])
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (strcmp(cellPhoneNum[i].numbers.cell, inputtedNum) == 0) {
			return i;
		}
	}
	return -1;
}

// displayContactHeader
void displayContactHeader(void) //displays header
{
	printf("\n");
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int totalContacts) //displays footer
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", totalContacts);
}

// displayContact:
void displayContact(const struct Contact * contact) {

	printf(" %s", contact->name.firstName);

	if (strlen(contact->name.middleInitial) > 1) //if user want middle initial than enters middle name otherwise skip
	{
		printf(" %s", contact->name.middleInitial);
	}

	printf(" %s\n", contact->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);

	if (contact->address.apartmentNumber > 0) 
	{
		printf("Apt# %d, ", contact->address.apartmentNumber);
	}

	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}


// displayContacts:
void displayContacts(const struct Contact display[], int size) //displays valid contacts
{
	int i;
	int count = 0;
	displayContactHeader();

	for (i = 0; i < size; i++)
	{
		if (strlen(display[i].numbers.cell) != 0)
		{
			displayContact(&display[i]);
			count++;
		}
	}
	displayContactFooter(count);
}

// searchContacts:
void searchContacts(const struct Contact contact[], int size) {

	int contactIndex = -1;
	char searchNum[11] = { '\0' };

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(searchNum);

	contactIndex = findContactIndex(contact, MAXCONTACTS, searchNum);

	if (contactIndex != -1) {

		printf("\n");
		displayContact(&contact[contactIndex]);
		printf("\n");

	}

	else 
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}

}

// addContact:
void addContact(struct Contact add[], int size) //adds contact if there is space available
{
	int i; 
	for (i = 0; i < size; i++)
	{
		if (strlen(add[i].numbers.cell) == 0)
		{
			break;
		}
	}

	if (i == size) printf("*** ERROR: The contact list is full! ***\n");
	else 
	{
		printf("\n");
		getContact(&add[i]);
		printf("--- New contact added! ---\n");
		printf("\n");
	}
		
}

// updateContact:
void updateContact(struct Contact update[], int size) //updates a contact
{
	char phoneNumb[11];
	int foundIndex, yn;

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(phoneNumb);

	foundIndex = findContactIndex(update, size, phoneNumb);

	if (foundIndex == -1)
		printf("*** Contact NOT FOUND ***\n");

	else
	{
		printf("\n");
		printf("Contact found:");
		printf("\n");
		displayContact(&update[foundIndex]);
		yn = yes();
		printf("\n");

		if (yn == 1)
			getName(&update[foundIndex].name);

		printf("Do you want to update the address? (y or n): ");
		yn = yes();

		if (yn == 1)
			getAddress(&update[foundIndex].address);

		printf("Do you want to update the numbers? (y or n): ");
		yn = yes();

		if (yn == 1)
			getNumbers(&update[foundIndex].numbers);

		printf("--- Contact Updated! ---\n");
	}

}

// deleteContact:
void deleteContact(struct Contact delete[], int size) //deletes a contact
{
	char phoneNumb[11];
	int foundIndex, yn;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phoneNumb);

	foundIndex = findContactIndex(delete, size, phoneNumb);

	if (foundIndex == -1)
		printf("*** Contact NOT FOUND ***\n");

	else
	{
		printf("\n");
		printf("Contact found:\n");

		displayContact(&delete[foundIndex]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		yn = yes();

		if (yn == 1)
		{
			delete[foundIndex].numbers.business[0] = '\0';
			delete[foundIndex].numbers.cell[0] = '\0';
			delete[foundIndex].numbers.home[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}

	}

}

// sortContacts:
void sortContacts(struct Contact contact[], int size) {

	int i, j, k;
	struct Contact choice;

	for (i = 0; i < size; i++)
	{
		k = i;
		for (j = i + 1; j < size; j++)
			if (strcmp(contact[j].numbers.cell, contact[k].numbers.cell) < 0) {
				k = j;
			}
		if (k != i)
		{
			choice = contact[i];
			contact[i] = contact[k];
			contact[k] = choice;
		}
	}

	printf("--- Contacts sorted! ---\n\n");

}
