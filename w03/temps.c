// Name: Priya Khatri
// Student Number: 110149176
// Email: pkhatri4@senecacollege.ca


#define _CRT_SECURE_NO_WARNINGS
#define NUMS 4
#define MAX_TEMP 40
#define MIN_TEMP -40 
#include<stdio.h>

int main()
{
		//Initialization of variables
		float total_high[NUMS];
		float total_low[NUMS];
		float added_up = 0;
		float average; 
		float highest_temp = 0;
		float lowest_temp = 0;
		int i;
		int highest_day;
		int lowest_day; 

	printf("---=== IPC Temperature Analyzer ===---");

	for (i = 0; i < NUMS; i++) //Loops the statements for user to input high and low temps
	{
		printf("\nEnter the high value for day %d: ", (i + 1));
		scanf("%f", &total_high[i]);

		printf("\nEnter the low value for day %d: ", (i + 1));
		scanf("%f", &total_low[i]);

		while (total_high[i] < total_low[i] || total_high[i] > MAX_TEMP || total_low[i] < MIN_TEMP) //Repeats statements if inputted data is true with any of these conditions
		{
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");

			printf("\nEnter the high value for day %d: ", (i + 1));
			scanf("%f", &total_high[i]);

			printf("\nEnter the low value for day %d: ", (i + 1));
			scanf("%f", &total_low[i]);
		}

		added_up += total_high[i] + total_low[i];

		if (total_high[i] > highest_temp) //Checks and compares highest temp value
		{
			highest_temp = total_high[i];
			highest_day = i + 1;
		}
		if (total_low[i] < lowest_temp) //Checks and compares to get lowest temp value
		{
			lowest_temp = total_low[i];
			lowest_day = i + 1;
		}
	}

	average = added_up / (NUMS * 2); //Calculate mean
	printf("\nThe average (mean) temperature was: %.2f\n", average);
	printf("The highest temperature was %.0f, on day %d", highest_temp, highest_day);
	printf("\nThe lowest temperature was %.0f, on day %d\n", lowest_temp, lowest_day);

	return 0;
}