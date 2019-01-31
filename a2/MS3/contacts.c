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

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+




// +---------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2   |
// |        function definitions below...              |
// |                                                   |
// | *** See hint regarding the getNumbers function    |
// +---------------------------------------------------+


// getName:
void getName(struct Name* name)
{
	int option;

	printf("Please enter the contact's first name: ");
	scanf("%35[^\n]", name->firstName);
	clearKeyboard();
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	option = yes();  //validating the required value yes or no in yes function which returns 1 or 0 and options receive it. 
	if (option == 1)
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", name->middleInitial);
		clearKeyboard();
	}
	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]", name->lastName);
	clearKeyboard();

}



// getAddress:
void getAddress(struct Address * address)
{
	int valid;

	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();
	while (address->streetNumber <= 0)
	{
		printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
		address->streetNumber = getInt();
	}

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]s", address->street);
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	valid = yes();

	if (valid == 1)
	{
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();
		while (address->apartmentNumber <= 0)
		{
			printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
			address->apartmentNumber = getInt();
		}
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]s", address->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf("%40[^\n]s", address->city);

}



// getNumbers:
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable
void getNumbers(struct Numbers* numbers)
{

	int option;

	printf("Please enter the contact's cell phone number: ");
	scanf("%10s", numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	option = yes();              //calling yes function to validate whether to insert data or not
	if (option == 1)
	{
		printf("Please enter the contact's home phone number: ");
		scanf("%10s", numbers->home);
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	option = yes();
	if (option == 1)
	{
		printf("Please enter the contact's business phone number: ");
		scanf("%10s", numbers->business);
	}


}



// getContact
void getContact(struct Contact *contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);

}
