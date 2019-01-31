/*
     Name:      Priya Khatri
     Student#:  110149176
 
*/

#define _CRT_SECURE_NO_WARNINGS


// Paste your in-lab code below and upgrade it to the at-home specifications

// Start your code below:

int main()

{
	//first I need to classify the variables
	double amount;
	int loonies;
	int quarters;
	float balance;
	double GST;
	int pennies;
	int nickles;
	int dimes;

	//printing out the statement that should be displayed here
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);

	//for the loonies
	loonies = amount;
	balance = amount - loonies;
	printf("Loonies required: %d, balance owing $%.2f\n", loonies, balance);

	//quarters section
	if ((balance >= 0.25) && (balance<0.50))
	{
		quarters = 1;
		balance = balance - 0.25;
	}
	else if ((balance >= 0.50) && (balance < 0.75))
	{
		quarters = 2;
		balance = balance - 0.50;

	}
	else if ((balance >= 0.75) && (balance < 1.00))
	{
		quarters = 3;
		balance = balance - 0.75;
	}

	printf("Quarters required: %d, balance owing $%.2f\n", quarters, balance);



	return(0);
}
