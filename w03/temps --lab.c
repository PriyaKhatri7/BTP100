// Name: Priya Khatri
// Student Number: 110149176
// Email: pkhatri4@senecacollege.ca


#define _CRT_SECURE_NO_WARNINGS

#define NUMS 3
#include<stdio.h>



int main()
{

	int day;
	int high = 0;
	int low = 0;
	float average = 0.0;
	int runningtotal = 0;


	//declaring the title of the project
	printf("---=== IPC Temperature Analyzer ===---\n");


	// showing the Loop to repeat from day up to 4 times w/ (NUMS) 4
	for (day = 1; day <= NUMS; day++)
	{

		//enter in the value for high 
		printf("Enter the high value for day %d: ", day);
		scanf("%d", &high);

		printf("\n");

		//enter in the value for low 
		printf("Enter the low value for day %d: ", day);
		scanf("%d", &low);

		printf("\n");


		//Conditions for the while loop inside for loop
		while (high < low || high < -40 || high > 40)
		{
			//if its wrong then put this in 
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");

			printf("\n");

			printf("Enter the high value for day %d: ", day);
			scanf("%d", &high);

			printf("\n");

			printf("Enter the low value for day %d: ", day);
			scanf("%d", &low);

			printf("\n");
		}

		//Calculate the total then divide it by the total day inputs
		runningtotal = runningtotal + high + low;
	}
	average = (double)runningtotal /NUMS/2;
	printf("The average (mean) temperature was: %.2f\n", average);
	return 0;
}