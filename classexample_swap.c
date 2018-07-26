#include<stdio.h>
#include<string.h>

void orderParms(short *p1, short *ps)
{
	if(*p1 < *p2) //deference the pointers to obtain value of p1 and p2
	{//do nothing
	}
	else
	{
	//swap the values pointed to by the pointers
	short temp = *p1;   //set a temporary value
	*p1 = *p2; //this will swap the value pointed to by p2, and set it to what p1 points to
	*p2 = temp; //the value that p2 is pointing to will be replaced by what temp is holding, which is p1
	}
}

int main()
{
	short p1 = 10;
	short p2 = 20;

	orderParms(&p1, &p2);
	printf("First is %d second is %d\n", p1, p2);

	p1 = 99;
	p2 = 50;

	orderParms(&p1, &p2);
	printf("First is &d second is %d\n", p1, p2);

	return 0;
}
