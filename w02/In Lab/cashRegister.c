// This is my in Lab 2 assignment
//Name: Priya Khatri
//Student number: 110149176

#include <stdio.h>


int main()
{
	double amt; //classify the varibles
	int loonie;
	int quart;
	float bal;

	printf("Please enter the amount to be paid: $"); //print out this sentence to show the output
	scanf("%lf", &amt);

	loonie = amt;
	bal = amt - loonie;

	printf("Loonies required: %d, balance owing $%.2f\n", loonie, bal); //calculating the number of loonies to pay the amount due
	if ((bal >= 0.25) && (bal < 0.50)) // if the balance comes more than or equal to 0.25 and less than 0.50
	{
		quart = 1; //if its 1 quarter
		bal = bal - 0.25;
	}

	else if ((bal >= 0.50) && (bal < 0.75)) // or if else between 0.50 and 0.75
	{
		quart = 2;
		bal = bal - 0.50;
	}

	else if ((bal >= 0.75) && (bal < 1.00)) // or between 0.75 and a loonie
	{
		quart = 3;
		bal = bal - 0.75;
	}

	printf("Quarters required: %d, balance owing $%.2f\n", quart, bal); // print out this statement showing the balance

	return(0); // return value must be 0 
}