/*
Name: Priya Khatri
Student Number: 110149176
Email: pkhatri4@myseneca.ca
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#include<stdio.h>


int main() //Start point
{
	//initialize the variables
	int days;
	int i;
	int high_temps[MAX]; //array for high temp
	int low_temps[MAX]; //array for low temp
	int highest_day;
	int lowest_day;
	int days_avg;
	int highest_temp = 0;
	int lowest_temp = 0;
	float avg = 0;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n"); //title of application

	printf("Please enter the number of days, between 3 and 10, inclusive: "); //saves the inputted data into a variable. Use %d for integer
	scanf("%d", &days);

	if (days < 3 || days > 10) //condition
	{
		do {
			printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
			scanf("%d", &days);
		} while (days < 3 || days > 10); //will loop the line above until the condition is true
	}

	printf("\n");

	for (i = 0; i < days; i++) //loops until condition is true
	{
		printf("Day %d - High: ", (i + 1));
		scanf("%d", &high_temps[i]);

		printf("Day %d - Low: ", (i + 1));
		scanf("%d", &low_temps[i]);

		if (high_temps[i] > highest_temp) //this is going to check and compare each array element to get the highest temp value
		{
			highest_temp = high_temps[i];
			highest_day = i + 1;
		}
		if (low_temps[i] < lowest_temp) // going to check and compare for the lowest value
		{
			lowest_temp = low_temps[i];
			lowest_day = i + 1;
		}
	}

	printf("\nDay  Hi  Low\n");

	for (i = 0; i < days; i++) //loops until condition is false
	{
		printf("%d    %d    %d\n", (i + 1), high_temps[i], low_temps[i]);
	}

	printf("\nThe highest temperature was %d, on day %d\n", highest_temp, highest_day);
	printf("The lowest temperature was %d, on day %d\n", lowest_temp, lowest_day);

	printf("\nEnter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
	scanf("%d", &days_avg);

	do
	{
		if ((days_avg > 0 && days_avg < 1) || days_avg > 4)
		{
			do {
				printf("\nInvalid entry, please enter a number between 1 and 4, inclusive: ");
				scanf("%d", &days_avg);
			} while ((days_avg > 0 && days_avg) < 1 || days_avg > 4); //loops until valid number is inputted
		}
		if (days_avg >= 1 && days_avg <= 4)
		{
			for (i = 0; i < days_avg; i++)
				avg += high_temps[i] + low_temps[i];

			printf("\nThe average temperature up to day %d is: %.2f\n", days_avg, (avg / (days_avg * 2)));
		}

		printf("\nEnter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
		scanf("%d", &days_avg);

		avg = 0; //resets average counter

	} while ((days_avg >= 1 && days_avg <= 4) || ((days_avg > 0 && days_avg < 1) || days_avg > 4)); //loops until user wishes to quit (enters a negative number)

	if (days_avg < 0)
		printf("\nGoodbye!\n");

	return 0;
}