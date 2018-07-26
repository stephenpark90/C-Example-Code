#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	// ./test param1 param2 param2 param4 = 5 parameters (the name of the program is at position 0)

	unsigned int returnCode = 0;

	if (argc >5)
	{
		returnCode = returnCode | 0b10000000; 
		/*the above code states if there are more than 5 parameters, change the most significant bit to 1.
		so this should print out 128*/
		printf("%d\n",returnCode); 
	}
	if (argc > 1 && atoi(argv[1]) > 100)
	{
		returnCode = returnCode | 0b1;
		/*the above code states, for any parameter above the first, and if the first parameter is 
		greater than 100, change the least significant bit to 1. so this should print 129*/ 
		printf("%d\n",returnCode); 
	}

	// Checks the value of a specific bit
	if(argc > 2 && ((unsigned int) atoi(argv[2])) & 0x2)
	{
		returnCode = returnCode | 0x800;
                printf("%u\n",returnCode); 
	}


	printf("Return Code is ox%x\n", returnCode);
	return 0;
}
