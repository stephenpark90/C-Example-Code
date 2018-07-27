#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 


/*
	This is an example of a simple 2 operand calculator using getopt(); 
*/

int main(int argc, char ** argv){


	/*
		Initialize all of the flags to 0 (false) 
	*/
	int add = 0; 
	int subtract = 0; 
	int multiply = 0; 
	int divide = 0; 


	/*
		Loop through all of the argument flags: 
	*/
	int c; 
	//Note that there are no colons after any of the flags (they don't require arguments) 
	//For instance, you use ./get -a 2 2, where -a doesn't take any argument. 
	while((c = getopt(argc,argv,"asmd"))!=-1){
		switch(c){
			case 'a': 
				if(subtract || multiply || divide)
					return 1; 
				add = 1; 
				//printf("Adding\n");
				break; 
			case 's': 
				if(add || multiply || divide)
					return 1; 
				subtract = 1; 
				//printf("Subtracting\n");
				break; 
			case 'm': 
				if(add || subtract || divide)
					return 1; 
				multiply = 1; 
				//printf("Mult\n");
				break; 
			case 'd': 
				if(add || subtract || multiply)
					return 1;
				divide = 1; 
				//printf("Div\n");
				break; 
			case '?': 
				return 1; 
				//printf("Don't know what that is.\n");
				break; 
		}
	}


	//If there aren't two numbers after the flags
	if(argc - optind < 2){
		printf("You need 2 operands!\n");
		return 1;
	}

	//Get the operands, which are the arguments given after the flags. 
	int num1 = atoi(argv[optind]);
	int num2 = atoi(argv[optind+1]);
	

	//Check which flag is set to true, and return the result of that operation
	if(add)
		printf("The sum of %d and %d is %d\n",num1,num2,num1 + num2);
	if(subtract)
		printf("%d minus %d is %d\n",num1,num2,num1 - num2);
	if(multiply)
		printf("The product of %d and %d is %d\n",num1,num2,num1 * num2);
	if(divide){
		if(num2 == 0){
			printf("You can't divide by zero.\n");
			return 1; 
		}else
			printf("%d divided by %d is %d\n",num1,num2,num1 / num2);
	}
	return 0;
}
