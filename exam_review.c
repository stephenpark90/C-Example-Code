//QUESTION 2: KEY/VALUE PAIR

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


/*instructors method
int exam_q2(int **list, size_t listLen, int key)
{

  if(list == NULL)
  {
   return -1;  //check to make sure list array is valid
  }

  for(int i = 0; i < listLen; i++) //goes through each row
  {
    if(list[i][0] == key)
	{
	  return list[i][1]; //returns the value of the key at this point  
	}
  }

    return -1; //return -1 if key is not found
}
*/






//QUESTION 3: STRUCTURE
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




/*instructors method
struct q3structure
{
  char a[21];
  unsigned int b;
  float c;
  int d[6];
  unsigned int e;
}; //create the structure

void *exam_q3()
{
  struct q3structure *struct1 = malloc(sizeof(struct q3structure)); //allocate on the heap
  
  int temp[6] = {3, 5, 7, 11, 13, 17}; //creates the integer array on the stack

  memset(struct1, 0, sizeof(struct q3structure)); //clears memory

  strcpy(struct1->a, "q3_struct);
  struct1->b = 0xdeadbeef;
  struct1->c = 1776.0704;
  memcpy(struct1->d, temp, sizeof(temp)); //copies the integer array
  struct1->e = 0xFFFFFFFF;

 return struct1; //returns the pointer to the memory without freeing
}
*/







//QUESTION 4: OPEN FILE WITH PATH IN PATH. READ LINE FROM FILE GIVEN BY LINE NUMBER

int exam_q4(const char *path, const int lineNumber, char *buffer)
{
  char temp[101]; //create a temporary array and account for null terminator
  int lineread = 1; //line you are reading

  FILE *fp = fopen(path, "r"); //open the file from path

  if(fp == NULL) //if file is not valid, return -1
  {
    return -1;
  }

  while(fgets(temp, sizeof(temp), fp) != NULL) //loop through the file until NULL, and copy to temp
  {
    if(lineread == lineNumber) //if the line you are at is the lineNumber, then execute code
    {
	strncpy(buffer, temp, 63); //copy line from temp into buffer and assign the buffer size
	fclose(fp);
	return strlen(buffer); //return the length of string we put into buffer
    }
    lineread++; //increment to the next line to read
  }

  fclose(fp);
  return -1; //if the line is not found, return -1
}






//QUESTION 5: FUNCTION THAT READS SINGLE LINE FROM STDIN

int exam_q5()
{
  char input[65]; //since we read 64 bytes, we need 65 to account for null terminator

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

/*Instructor's method
int exam_q5()
{
  char buffer[65];   //create buffer of 65 since we read 64 bytes and need to account for null terminator
  fgets(buffer, sizeof(buffer), stdin);   //automatically inserts new line at the end. no while loop
  if(strstr(buffer, "ERROR ") == buffer)  //this checks to see if "ERROR " is located at beginning
  {
	fprintf(stderr, "%s", buffer);
  }
  else
  {
	fprintf(stdout, "%s", buffer);
  }
  return 0-;
}
*/




//QUESTION 6: MIN/MAX ARRAY

int exam_q6(int *list, int size, int *minimum, int *maximum)
{
  //Add your code here

  *minimum = list[0]; //set to the first entry to list array
  *maximum = list[0];

  for(int i = 0; i < size; i++) //loop through each item in the list array
  {
	if(list[i] < *minimum) //if current item is less than minimum, it becomes the new min
	{
	*minimum = list[i];
	}
	if (list[i] > *maximum) //if current item is greater than current maximum, it becomes the new max
	{
	*maximum = list[i];
	}
  }

	printf("Maximum = %d\n", &maximum);
	printf("Minimum = %d\n", &minimum);

  return 0;
}

/*Instructor's method

int exam_q6(int *list, int size, int *minimum, int *maximum)
{
  *minimum = *maximum = list[0];

  for(int i = 0; i < size; i++)
  {
	if(list[i] < *minimum)
	{
	  *minimum = list[i];
	}
	if(list[i] > *maximum)
	{
	  *maximum = list[i];
	}
  }

 return 0;
}
*/





//QUESTION 7: SWAP

void exam_q7(int *leftPtr, int *rightPtr)
{
  //Add your code here

	int temp = *leftPtr;
	*leftPtr = *rightPtr;
	*rightPtr = temp;

	printf("int leftside = %d\nint rightside = %d", leftPtr, rightPtr);
}






//QUESTION 8: BITWISE
/*validate the input to exam_q8
  ensure var1 is between 0 and 7, inclusive, else set bit 0x1 in the return.
 ensure format is a *valid pointer* to a string of length > 5, else set bit 0x2 in the return.
 ensure print is a valid number either 0 or 1 *as numbers not characters*, else set bit 0x4 in the return.
 ensure the most significant bit (0x80000000) is set to 1 in var4, else set bit 0x8 in the return.
 ensure strVar a *valid pointer* and is one of the list: ("17", "19", "23", "29", "31"), else set      
  bit 0x10 in the return */
unsigned int exam_q8(int var1, char *format, unsigned int print, unsigned int var4, char *strVar)
{
  unsigned int returnVal = 0;
  
  if(var1 < 0 || var1 > 7)
  {
	returnVal |= 0x1;
  }
  if(format == NULL || strlen(format) <= 5)
  {
	returnVal |= 0x2;
  }
  if(print != 0 && print != 1)
  {
	returnVal |= 0x4;
  }
  if((var4 & 0x80000000) == 0)
  {
	returnVal |= 0x8;
  }
  if(strVar == NULL || 
    (strcmp(strVar, "17") != 0 && 
     strcmp(strVar, "19") != 0 && 
     strcmp(strVar, "23") != 0 && 
     strcmp(strVar, "29") != 0 && 
     strcmp(strVar, "31") != 0) )
  {
	returnVal |= 0x10;
  }
return returnVal;

}






//QUESTION 9: QSORT

static int cmpint(const void *p1, const void *p2)
{
  return *((int*)p1) - *((int*)p2); 
}


void exam_q9(int *intList, size_t listLen)
{

  qsort(intList, listLen, sizeof(int), cmpint);
  return; //dont need to include this return since the return type is void
}

/*
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
*/





//Question 10: Getopt

int main(int argc, char *argv[])
{
  int opt;
  int operation = 0;
  int number1 = 0; number 2 = 0;

  while((opt = getopt(argc, argv, "asmd")) != -1)
  {
    switch(opt)
    {
	case 'a':
	operation = 1; //add
	break;
	case 's':
	operation = 2; //subtract
	break;
	case 'm':
	operation = 3; //multiply
	break;
	case 'd':
	operation = 4; //divide
	break;
	default: 
	fprintf(stderr, "Usage: %s", 
	return 1;
	
    }
  }
  number1 = atoi(argv[optind]);
  number2 = atoi(argv[optind+1]); //first option after 

  if(operation == 1) //add
  {
	printf("%d\n", number1 + number2);
  }
  else if(operation == 2) //subtract
  {
	printf("%d\n", number1 - number2);
  }
  else if(operation == 3) //multiply
  {
	printf("%d\n", number1 * number2);
  }
  else if(operation == 4) //divide
  {
	if(number2 == )
	{
	  printf("NAN\n");
	}
	printf("%d\n", number1 / number2);
  }
return 0;
}



