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

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contactHelpers.h"
#include <string.h>


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

void getName(struct Name * name) {

	int Choice = 0;

	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", name->firstName);  //Receives first name upto 30 characters
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	//calling yes function to get user's choice. Recieving 1 for yes and 0..........
	Choice = yes();

	//Using if statement to get middle initial(s) by validating with yes function where return is 'y' or 1....
	if (Choice == 1)
	{

		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", name->middleInitial);
		clearKeyboard();
	}
	else {

		*name->middleInitial = '\0';

	}

	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]", name->lastName);// Receives last name....
	clearKeyboard();

}

// getAddress:
void getAddress(struct Address * address) {

	int Choice = 0;

	printf("Please enter the contact's street number: ");
	//Using getInt function to conform that user used  integer value
	address->streetNumber = getInt();

	while (address->streetNumber <= 0) // when street number is negative it ask again to enter positive number........
	{

		printf("Please enter the contact's street number: ");
		address->streetNumber = getInt();

	}


	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]", address->street);
	clearKeyboard();


	printf("Do you want to enter an apartment number? (y or n): ");

	Choice = yes();  //calling yes function to get user's choice. Recieving 1 for yes and 0 for no


	if (Choice == 1)  //Using if statement to get apartment number, if user's choice is yes
	{

		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();  //using getInt function to make sure that user insert integer value


		while (address->apartmentNumber <= 0) //checking user's input for the apartment number is an positivie number
		{
			//If negative than it ask again to insert value......
			printf("Please enter the contact's apartment number: ");
			address->apartmentNumber = getInt();

		}

	}
	else {

		address->apartmentNumber = 0;

	}

	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]", address->postalCode);// takes 7 character for postal code including spaces
	clearKeyboard();  //clears buffers

	printf("Please enter the contact's city: ");
	scanf("%40[^\n]", address->city);
	clearKeyboard();

}

// getNumbers:
void getNumbers(struct Numbers * numbers) 
{
	int Choice = 0;

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);//receives 10 digit cell number after validation in gettendigit function...

	printf("Do you want to enter a home phone number? (y or n): ");
	//calling yes function to get user's choice. Recieving 1 for yes and 0 for no
	Choice = yes();

	if (Choice == 1)  // receives home phone number, if user's choice is yes
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
		//clearKeyboard();
	}
	else
		numbers->home[0] = '\0';

	printf("Do you want to enter a business phone number? (y or n): ");
	Choice = yes();//calling yes function 

				   //if choice is true than
	if (Choice == 1) {

		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
		//clearKeyboard();
	}
	else
		numbers->business[0] = '\0';
}

// getContact:
void getContact(struct Contact * contact) {

	getName(&(contact->name));

	getAddress(&(contact->address));

	getNumbers(&(contact->numbers));

}