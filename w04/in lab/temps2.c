
/* 
Name: Priya Khatri      
Student Number: 110149176
Email: pkhatri4@myseneca.ca     
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 10 //max number of days
#include<stdio.h>

int main() //Start point
{
	int days;
	int i;
	int high_temps[MAX]; //array for high temp
	int low_temps[MAX]; //array for low temp

	printf("---=== IPC Temperature Calculator V2.0 ===---\n"); //title of application

	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days); //saves the inputted data into a variable. Use %d for integer

	if (days < 3 || days > 10) //condition
	{
		do {
			printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
			scanf("%d", &days);
		} while (days < 3 || days > 10); //will loop the line above until the condition is true
	}

	printf("\n");

	for(i = 0; i < days; i++) //loops until condition is true
	{
		printf("Day %d - High: ", (i+1));
		scanf("%d", &high_temps[i]);

		printf("Day %d - Low: ", (i+1));
		scanf("%d", &low_temps[i]);
	}

	printf("\nDay  Hi  Low\n");

	for (i = 0; i < days; i++)
	{
		printf("%d    %d    %d\n", (i + 1), high_temps[i], low_temps[i]);
	}

	return 0; //return exit
}