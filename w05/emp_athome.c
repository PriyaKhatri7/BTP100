/* Name: Priya Khatri
Stu number: 110149176
email: pkhatri4@myseneca.ca
Lab: at home 5
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 4// Define Number of Employees "SIZE" to be 4

struct Employee// Declare Struct Employee
{
	int id_num, age;
	double salary;
};


/* main program */
int main(void) {

	int i, option = 0, counter = 0, entered_id, check_id3 = 0, check_id4 = 0, change_salary, remove_id; //Initialization of variables.

	printf("---=== EMPLOYEE DATA ===---\n\n");

	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero

	struct Employee emp[SIZE] = { { 0 } };

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");

			break;
		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 

			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0
			for (i = 0; i < SIZE; i++) //Prints the employee info whenever condition is met
			{
				if (emp[i].id_num > 0)
					printf("%6d%9d%11.2lf\n", emp[i].id_num, emp[i].age, emp[i].salary);
			}

			printf("\n");

			break;
		case 2:	// Adding Employee
				// @IN-LAB

			printf("Adding Employee\n");
			printf("===============\n");

			if (counter == SIZE)
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");

			else //Asks user for employee info
			{
				printf("Enter Employee ID: ");
				scanf("%d", &emp[counter].id_num);

				printf("Enter Employee Age: ");
				scanf("%d", &emp[counter].age);

				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[counter].salary);

				printf("\n");

				if (emp[counter].id_num > 0)
					counter++;
			}


			// Check for limits on the array and add employee 
			// data accordingly. 

			break;
		case 3: //Update Employee Salary

			printf("Update Employee Salary\n");
			printf("======================\n");

			do  //loops until user inputs matching id number
			{
				printf("Enter Employee ID: ");
				scanf("%d", &entered_id);

				for (i = 0; i < SIZE; i++)
				{
					if (entered_id == emp[i].id_num)
					{
						check_id3 = 1;
						change_salary = i;
						break;
					}
				}
				if (entered_id == emp[i].id_num)
				{
					printf("*** ERROR: Employee ID not found! ***");
					printf("\n");
				}

			} while (check_id3 == 0);
			
			printf("The current salary is %.2lf\n", emp[change_salary].salary);
			printf("Enter Employee New Salary: ");
			scanf("%lf", &emp[change_salary].salary);
			
			printf("\n");
			break;
		case 4: //Remove Employee

			printf("Remove Employee\n");
			printf("===============\n");

			do
			{
				printf("Enter Employee ID: ");
				scanf("%d", &entered_id);

				for (i = 0; i < SIZE; i++)
				{
					if (entered_id == emp[i].id_num)
					{
						check_id4 = 1;
						remove_id = i;
					}

					if (entered_id == emp[i].id_num)
					{
					printf("*** ERROR: Employee ID not found! ***");
					printf("\n");
					}

				}

			} while (check_id4 == 0);

			printf("Employee %d will be removed\n", entered_id);

			emp[remove_id].id_num = 0;

			counter--;

			printf("\n");
			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);


	return 0;
}



//PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
111       34   78980.88
112       41   65000.00

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/
