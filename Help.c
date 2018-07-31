#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

/*
 * This is the final exam for C programming.
 * Enter your details below
 *
 * RANK: 2LT
 * NAME: Stephen Park
 * DATE: 20180731
 *
 * Add code to accomplish the task for each question.
 * Do not change the function prototypes given below.
 * You should include any header files needed by your answers. 
 * Ensure the question 10 function does *NOT* call the 
 *      exam_q* functions before submitting.
 * Follow instructions given by your instructor for submitting.
 * Do not move, remove, or modify the preprocessor statements (#ifdef/#endif)
 * You can perform a basic test of your code with "make checkit"
 * The basic test will *NOT* check all possibilities to be checked by grading.
 */


#ifndef SUPPRESS_EXAM_QUESTION_1

/* Question 1:
 * For exam_q1, correct the function so it properly 
 * computes the average of the three parameters 
 * Example call, exam_q1(1, 2, 3) should return 2
 * Test code:
 * float result = exam_q1(1.0, 2.0, 3.0);
 * if ((abs(result) - 2.0) > 0.001) printf("Incorrect\n");
 */
float exam_q1(int var1, int var2, int var3)
{
  //Your code here
  float sum = var1 + var2 + var3;
  float average = sum / 3;
  return average;
}

#endif //SUPPRESS_EXAM_QUESTION_1


#ifndef SUPPRESS_EXAM_QUESTION_2

/* Question 2:
 * A key/value pair is a set of data which matches an access parameter known
 * as a key to a data item known as a value.  Key/value pairs are commonly 
 * used to store variable data as a named value.  For instance, you may like
 * store configuration information on a service by named values. A sample of 
 * keys and values is presented below:
 * Key 			Value
 * "ServiceName"	"WebService"
 * "ServiceDesc"	"A web service for internal clients"
 * "Port"		"443"
 * "User"		"WebUser"
 *
 * When a caller requests "ServiceName", the response should be "WebService".
 * Likewise, when a caller requests "Port", the response should be "443".
 * 
 * Using a table similar in structure to q2_table as a 2 dimensional integer 
 * array, search for the first instance of the key, located at list[x][0] and 
 * return associated the value located at list[x][1]. If the key is not 
 * found, return -1.
 * 
 * int **list - an int array of length listLen with the second dimension 
 *              containing a key and value. The column dimension is 2.
 * int listLen - The length of (not sizeof) the row dimension of the list. 
 * int key - the key to match
 * 
 * Example call: if the list provided is q2_table and the provided key is 30,  
 * the value to be returned is 21.
 *                      key, value
 * int q2_table[][2] = {{15, 10}, 
 *                      {30, 21}, 
 *                      {1,  65},
 *                      {22, 16},
 *                      {0,   0}};
 * if (exam_q2(q2_table, 30, 21) != 21) printf("Incorrect\n");
 */
int exam_q2(int **list, size_t listLen, int key)
{
  //Add your code here
	int value;

  for (int i = 0; i < listLen; i++)
  {
    if(list[i][0] == key)
	{
 	return list[i][1];
	}
  }

  return -1;
}

#endif //SUPPRESS_EXAM_QUESTION_2

#ifndef SUPPRESS_EXAM_QUESTION_3

/* Question 3:
 * Create a data structure holding the following types in the listed order:
 * The name of the members is not important, the order, type, and value are.
 * Do not change the order listed below.
 * Order Description                               Value
 *    1. char array with 21 elements:              "q3_struct"
 *    2. unsigned integer:                         0xdeadbeef
 *    3. floating point decimal:                   1776.0704
 *    4. integer array with 6 elements containing: 3, 5, 7, 11, 13, 17
 *    5. unsigned integer:                         0xFFFFFFFF
 *  
 * Next, create an instance of the structure on the heap, 
 * set the value of the members to the values listed above, and
 * return the pointer to the heap memory without freeing it.
 * 
 * struct what_you_called_your_struct *test = exam_q3();
 * if (strncmp((char*)test, "q3_struct") != 0) printf("Incorrect\n");
 * The next members depend on your structure but should be laid out in memory:
 * q3_struct.....|deadbeef|1776.0704|3..5..7..11..13..17|FFFFFFFF
 * 
 */

struct q3structure
{
  char c[21];
  unsigned int a;
  float f;
  int array[6];
  unsigned int b;

};

void *exam_q3()
{
  //Add your code here

	struct q3structure *struct1 = malloc(sizeof(struct q3structure));

	strcpy(struct1->c, "q3_struct");
	struct1->a = 0xdeadbeef;
	struct1->f = 1776.0704;
	struct1->array[0] = 3;
	struct1->array[1] = 5;
	struct1->array[2] = 7;
	struct1->array[3] = 11;
	struct1->array[4] = 13;
	struct1->array[5] = 17;
	struct1->b = 0xFFFFFFFF;

  return struct1;
}

#endif //SUPPRESS_EXAM_QUESTION_3

#ifndef SUPPRESS_EXAM_QUESTION_4

/* Question 4:
 * Open the file with the path in path
 * Read the line from the file given by line number (the first line in 
 *     the file is numbered 1)
 * Copy the line data into buffer (the buffer is 64 bytes total)
 * Return the number of bytes placed into the buffer excluding the NULL 
 *     terminating byte or 
 * Return -1 if a failure occurred such as file not found or line not in file.
 * 
 * NOTE: Do not modify "buffer" unless a valid read and response is occuring.
 *       Consider it to be a constant that would only be updated by 
 *       a read from the file.
 *       The file is generated dynamically and each line will include <= 100 bytes.
 * 
 *
 * char buffer[101];
 * if (exam_q4("StudentExam.dat", 7, buffer) != 63 || 
 *     strcmp(buffer, "Really long line in the file that should be handled by the stud") != 0)
 * { printf("Incorrect\n");
 * }
 */

int exam_q4(const char *path, const int lineNumber, char *buffer)
{
  //Add your code here

	char temp[128];
	int line = 1;
	FILE* fp = fopen(path, "r");

	if(fp == NULL)
	return -1;

	while(fgets(temp, 64, fp) != NULL)
	{
		if(line == lineNumber)
		{
		memset(buffer, 0, 64);
		strncpy(buffer, temp, 64);
		return strlen(buffer);
		}
		line++;
	}
	fclose(fp);
	return 0;
}


#endif //SUPPRESS_EXAM_QUESTION_4

#ifndef SUPPRESS_EXAM_QUESTION_5

/* Question 5:
 * Create a function body which reads a *single line* from standard 
 * input (stdin), processes it, and returns.  The maximum length of
 * the input should be 64 bytes.  If the string begins with "ERROR "
 * the entire line should be written to the standard error stream
 * (stderr). If the line does not begin with "ERROR " the entire line
 * should be written to standard output (stdout). Ensure only one
 * newline character is present in the output. Do not write 
 * anything else to stdout or stderr. Return 0 from the function.
 * 
 * Example call, if the text read from standard input is:
 * "My test\n"
 * your function should output:
 * "My test\n"
 * to standard output and return 0.
 *
 * If the text read from standard input is:
 * "ERROR Failed to open file\n"
 * your function should output:
 * "ERROR Failed to open file\n"
 * to standard error and return 0.
 */
int exam_q5()
{
  //Add your code here

  char input[64];

	while(fgets(input, sizeof(input), stdin) != NULL);
	if(strstr(input,"ERROR "))
	{
	fputs(input, stderr);
	}
	else
	{
	fputs(input, stdout);
	}

  return 0;
}

#endif //SUPPRESS_EXAM_QUESTION_5

#ifndef SUPPRESS_EXAM_QUESTION_6

/* Question 6:
 * Create a function which will take the following parameters:
 * int *intArray - A signed integer array (one dimension).
 * int arrayLength - The length of the array.
 * minimum - The integer in the list with the lowest value.
 * maximum - The integer in the list with the highest value.
 * The return value of this function should be 0.
 * 
 * The function should locate the minumum and maximum values in intArray and
 * set the minimum and maximum value pointers accordingly.  
 *
 * Example call, If called with:
 * int list[6] = {10, 45, 23, 97, 101, 1};
 * int min, max;
 * exam_q6(list, 6, &min, &max);
 * if (min != 1 || max != 101) printf("Incorrect\n");
 */

int exam_q6(int *list, int size, int *minimum, int *maximum)
{
  //Add your code here

  *minimum = list[0];
  *maximum = list[0];

  for(int i = 0; i < size; i++)
  {
	if(list[i] < *minimum)
	{
	*minimum = list[i];
	}
	if (list[i] > *maximum)
	{
	*maximum = list[i];
	}
  }

	printf("Maximum = %d\n", &maximum);
	printf("Minimum = %d\n", &minimum);

  return 0;
}

#endif //SUPPRESS_EXAM_QUESTION_6

#ifndef SUPPRESS_EXAM_QUESTION_7

/* Question 7:
 * Swap the values pointed to by the two parameters.
 * 
 * Example call:
 * int leftSide = 1568;
 * int rightSide = 5479;
 * exam_q7(&leftSide, &rightSide);
 * if (leftSide != 5479 || rightSide != 1568) printf("Incorrect\n");
 */

//Add your code for Question 7 here
void exam_q7(int *leftPtr, int *rightPtr)
{
  //Add your code here

	int temp = *leftPtr;
	*leftPtr = *rightPtr;
	*rightPtr = temp;


	printf("int leftside = %d\nint rightside = %d", leftPtr, rightPtr);

}

#endif //SUPPRESS_EXAM_QUESTION_7


#ifndef SUPPRESS_EXAM_QUESTION_8

/* Question 8:
 * Validate the input to exam_q8
 * ensure var1 is between 0 and 7, inclusive, else set bit 0x1 in the return.
 * ensure format is a *valid pointer* to a string of length > 5, else set bit 0x2 in the return.
 * ensure print is a valid number either 0 or 1 *as numbers not characters*, else set bit 0x4 in the return.
 * ensure the most significant bit (0x80000000) is set to 1 in var4, else set bit 0x8 in the return.
 * ensure strVar a *valid pointer* and is one of the list: ("17", "19", "23", "29", "31"), else set bit 0x10 in the return.
 * 
 * Example call:
 * if (exam_q8(1, "42", 1, 0, "6") != 0x1A) printf("Incorrect\n");
 */
unsigned int exam_q8(int var1, char *format, unsigned int print, unsigned int var4, char *strVar)
{
  //Add your code here
  unsigned int returnVar = 0;

	if(var1 < 0 || var1 > 7)
	{
	returnVar |= 0x1;
	}
	if(*format < 5)
	{
	returnVar |= 0x2;
	}
	if(print != atoi(0) || print != atoi(1))
	{
	returnVar |= 0x4;
	}
	if((var4 & 0b80000000) == 0)
	{
	returnVar |= 0x8;
	}
	if(*strVar == (17 || 19 || 23 || 29 || 31))
	{
	returnVar | 0x10;
	}

  return 0;
}

#endif //SUPPRESS_EXAM_QUESTION_8

#ifndef SUPPRESS_EXAM_QUESTION_9

/* Question 9:
 * Given the integer list in intList with a length of listLen, sort the
 * integers into ascending order. For instance if the list contained
 * {12, 45, -4, -32, 1024, 0, 55}, upon return of your function, the list 
 * should be {-32, -4, 0, 12, 45, 55, 1024}.
 * You may use qsort or write your own sorting algorithm.
 * 
 * int array[] = {12, 45, -4, -32, 1024, 0, 55};
 * size_t arrayLen = sizeof(array)/sizeof(int);
 * exam_q9(array, arrayLen);
 * if (array[0] != -32 || array[1] != -4 || array[2] != 0 || array[6] != 1024) printf("Incorrect\n");
 */

void exam_q9(int *intList, size_t listLen)
{
  //Add your code here

	int compare_int(const void* a, const void* b)
	{
		if( *(int*)a == *(int*)b)
		return 0;
		return *(int*)a < *(int*)b ? -1 : 1;
	}

	qsort(intList, listLen, sizeof(int), compare_int);

	int i = 0;
	while(i < listLen)
	{
		printf("%d\n", intList[i]);
		i++;
	}

}

#endif //SUPPRESS_EXAM_QUESTION_9

#ifndef SUPPRESS_EXAM_QUESTION_10

/* Question 10:
 * Write an *entry point function* which will process command line arguments 
 * in the following way:
 * Usage:
 * program (-a|-s|-m|-d) [--] number1 number2
 * The program should use the supplied operation and perform the requisite 
 * mathematical operation on the two provided numbers. The arguments should
 * only be integers, positive and negative.  Write the result to standard
 * output and exit.  No other operations or output should be performed. 
 * NOTE: Your entry point function should not call any of the exam_q* 
 * functions. The standard, successful return value should be returned upon
 * successful completion. Invalid command line arguments should return a value
 * signifying an improper termination. Attempts to divide by zero should
 * be caught and output "NAN" but still return successfully.
 * You may use getopt or create your own processor (see NOTE below).
 *
 * NOTE: getopt requires a parameter of "--" to ignore further processing 
 * of parameters as options and instead leave them as positional parameters.
 * getopt will ignore this parameter but you will need to process this 
 * parameter if writing your own parameter processor. This *will* be used to 
 * test negative numbers. See the last example below.
 *
 * Some examples of successful calls are:
 * program -a 2 3 
 *   will output: "5\n"
 *
 * program -s 5 2 
 *   will output: "3\n"
 *
 * program -m 2 3 
 *   will output: "6\n"
 *
 * program -d 6 3 
 *   will output: "2\n"
 *
 * program -m -- -5 3
 *   will output "-15\n"
 */

//Add your code for Question 10 here
int main(int argc, char *argv[])
{
  //Add your code here

	int add = 0;
	int subtract = 0; 
	int multiply = 0; 
	int divide = 0; 

	int c; 

	while((c = getopt(argc,argv,"a:s:m:d:"))!=-1){
		switch(c){
			case 'a': 
			if(subtract || multiply || divide)
				return 1; 
			add = 1; 
			break; 

			case 's': 
			if(add || multiply || divide)
				return 1; 
			subtract = 1; 
			break; 
			case 'm': 
			if(add || subtract || divide)
					return 1; 
			multiply = 1; 
			break; 
			case 'd': 
			if(add || subtract || multiply)
				return 1;
			divide = 1; 
			break; 
			case '?': 
			return 1; 
			break; 
		}
	}

	if(argc - optind < 2){
		printf("You need 2 operands!\n");
		return 1;
	}
	int number1 = atoi(argv[optind]);
	int number2 = atoi(argv[optind+1]);
	if(add)
		printf("%d\n", number1 + number2);
	if(subtract)
		printf("%d\n",number1 - number2);
	if(multiply)
		printf("%d\n",number1 * number2);
	if(divide){
		if(num2 == 0){
			printf("You can't divide by zero.\n");
			return 1; 
		}else
			printf("%d\n",number1 / number2);
	}

	return 0;

}


  return 0;
}

#endif //SUPPRESS_EXAM_QUESTION_10





