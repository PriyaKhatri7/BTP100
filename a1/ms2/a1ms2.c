/* -------------------------------------------
Name: Priya Khatri
Student number: 11014976
Email: pkhatri4@myseneca.ca
Section: 
Date: 10/30/2018
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

int main (void)
{
    // Declare variables here:
	struct Name c_name= {{'\0'}};
	struct Address c_address = {  '\0', {0}  };
	struct Numbers c_num = {{'\0'}};
	char ansr; // variable for users input when asked if they want to input certain info

    // Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");

    // Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", c_name.firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %[^\n]c", &ansr);
	
	if (ansr == 'y' || ansr == 'Y') //Checks if user inputted a yes
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %[^\n]", c_name.middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]s", c_name.lastName);

    // Contact Address Input:

	printf("Please enter the contact's street number: ");
	scanf(" %d", &c_address.streetNumber);

	printf("Please enter the contact's street name: ");
	scanf(" %[^\n]s", c_address.street);

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &ansr);

	if (ansr == 'y' || ansr == 'Y')
	{
		printf("Please enter the contact's apartment number: ");
		scanf(" %d", &c_address.apartmentNumber);
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]d", c_address.postalCode);

	printf("Please enter the contact's city: ");
	scanf(" %41[^\n]c", c_address.city);

    // Contact Numbers Input:
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &ansr);

	if (ansr == 'y'|| ansr == 'Y')
	{
		printf("Please enter the contact's cell phone number: ");
		scanf("%21s", c_num.cell);
	}
	
	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &ansr);

	if (ansr == 'y' || ansr == 'Y')
	{
		printf("Please enter the contact's home phone number: ");
		scanf("%21s", c_num.home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &ansr);

	if (ansr == 'y' || ansr == 'Y')
	{
		printf("Please enter the contact's business phone number: ");
		scanf("%21s", c_num.business);
	}
	printf("\n");
    // Display Contact Summary Details
	printf("Contact Details\n");
	printf("---------------\n");
	printf("Name Details\n");
	printf("First name: %s", c_name.firstName);
	printf("\nMiddle initial(s): %s", c_name.middleInitial);
	printf("\nLast name: %s", c_name.lastName);
	printf("\n\n");
	printf("Address Details\n");
	printf("Street number: %d", c_address.streetNumber);
	printf("\nStreet name: %s", c_address.street);
	printf("\nApartment: %d", c_address.apartmentNumber);
	printf("\nPostal code: %s", c_address.postalCode);
	printf("\nCity: %s", c_address.city);
	printf("\n\n");
	printf("Phone Numbers:\n");
	printf("Cell phone number: %s", c_num.cell);
	printf("\nHome phone number: %s", c_num.home);
	printf("\nBusiness phone number: %s", c_num.business);
	printf("\n\n");
	
    // Display Completion Message

	printf("Structure test for Name, Address, and Numbers Done!\n");

    return 0;
}

/*  SAMPLE OUTPUT:
    
Contact Management System
-------------------------
Please enter the contact's first name: Tom
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Wong
Please enter the contact's last name: Song
Please enter the contact's street number: 20
Please enter the contact's street name: Keele
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 40
Please enter the contact's postal code: A8A 4J4
Please enter the contact's city: Toronto
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 905-111-6666
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 705-222-7777
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-333-8888

Contact Details
---------------
Name Details
First name: Tom
Middle initial(s): Wong
Last name: Song

Address Details
Street number: 20
Street name: Keele
Apartment: 40
Postal code: A8A 4J4
City: Toronto

Phone Numbers:
Cell phone number: 905-111-6666
Home phone number: 705-222-7777
Business phone number: 416-333-8888

Structure test for Name, Address, and Numbers Done!
*/