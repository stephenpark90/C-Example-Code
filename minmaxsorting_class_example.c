#include <stdio.h>
#include <stdint.h>


int main()
{
	unsigned char arr[] = {1, 15, 18, 4, 199, 45, 63, 82, 85, 186, 244};
	unsigned char minimum = UINT8_MAX;//the UINT8 refers to the max num allowed for unsigned char, which is 255
	unsigned char maximum = 0;	//set the minimum and maximum to the opposite of what they will be


	/* the sizeof(variable) divided by the sizeof(first instance of variable) gives us the size of the array
	this cannot be used for pointers because the size of a pointer is 8 bytes. This can only be used
	if the values are actually defined. if you are given a pointer, you should also be given the size
	which is passed to the second part of the for loop*/
	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		if(arr[i] < minimum)
		{	//if the current value in the array is less than the minimum, it will become the minimum
			minimum = arr[i];
		}
		if(arr[i] > maximum)
		{	//if the current value in the array is greater than the max, it will become the max
			maxmimum = arr[i];
		}
	}

	printf("Minimum %u\n", minimum);
	printf("Maximum %u\n", maximum);
	return 0;
}

//the above is the same as below. the difference is in the size - see the for loop

int main()
{
        unsigned char arr[] = {1, 15, 18, 4, 199, 45, 63, 82, 85, 186, 244};
        size_t arrLen = sizeof(arr)/sizeof(arr[0]);

	unsigned char minimum = UINT8_MAX;  //set the minimum and maximum to the opposite of what they will be
        unsigned char maximum = 0;


        for(int i = 0; i < arrLen; i++) 
        { 
                if(arr[i] < minimum)
                {       //if the current value in the array is less than the minimum, it will become the minimum
                        minimum = arr[i]; 
                }
                if(arr[i] > maximum)
                {       //if the current value in the array is greater than the max, it will become the max
                        maxmimum = arr[i]; 
                }
        }

        printf("Minimum %u\n", minimum);
        printf("Maximum %u\n", maximum);
        return 0;
}





}
