#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BankAccount
{
	int accountNumber;   //members of the structure BankAccount
	float balance;
	int lastCheckNumber;
	char accountHolder[50];
};


void printAcct(struct BankAccount *a)
{
	printf("Account # %d held by %s has a balance %0.2f and last used check# %d\n",
		a->accountNumber,
		a->accountHolder,
		a->balance,
		a->lastCheckNumber);
}



int main()
{						//there are three ways to set values to members of a structure
	struct BankAccount myAcct;
	myAcct.accountNumber = 12345678;
	myAcct.balance = 100.0;
	myAcct.lastCheckNumber = 123;
	strcpy(myAcct.accountHolder, "No Named Person");

	struct BankAccount joesAccount = {98765, 99.12, 456, "Joe the Plumber"};

	struct BankAccount *janesAccount = malloc(sizeof(struct BankAccount) * 1); //structure pointer
	janesAccount->accountNumber = 134679; //janesAccount-> is the same as (*janesAccount)
	janesAccount->balance = 123.00;
	janesAccount->lastCheckNumber = 321;
	strcpy(janesAccount->accountHolder, "Jane Doe");


	printAcct(&myAcct);	//use & to point to myAccount
	printAcct(&joesAccount);
	printAcct(janesAccount); //Janes account is already a pointer, so no need to point to it

	free(janesAccount);

 return 0;
}
