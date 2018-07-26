#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char ** argv)
{
	char name[] = "Name";
	char *greeting = "Hello to %s\n";
	char *output = malloc(sizeof(char) * 128); //allocate memory to the string "output"
	int primes[] = {1,2,3,5,7,11,13,17};
	if(output == NULL)
	{
		printf("Failed to allocate buffer\n");
		return 1;
	}

	sprintf(output, greeting, name); //sprintf inserts the name into %s, and stores it in output
	printf(output);

	for(int i = 0; i < sizeof(primes)/sizeof(primes[0]); i++)
	{
		printf("Prime %d\n", primes[i]);
	}

	free(output);
	return 0;
}
