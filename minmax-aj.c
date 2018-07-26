#include <stdio.h>

/*
    Implement the 4 versions of the following functions
    such that they calculate the minimum and maximum
    values of the given array.

    From main, add calls (and variable declarations if
    needed) to the 4 versions.
*/

void extremes_v1(int* arr, size_t size, int* min, int* max) // Provided pointers to garbage.
{
  for (size_t i = 0; i < sizeof(arr); i++)
  {
    *min = arr[0];
    *max = arr[0];
    if (arr[i] < *min)
    {
      *min = arr[i]; // Reassign with our new-found min.
    }
    else if (arr[i] > *max)
    {
      *max = arr[i]; // Reassign with our new-found max.
    }
  }
}

int extremes_v2(int* arr, size_t size, int* min)
{
  *min

  if(arr[i] > max)
    max = arr[i];
  if(arr[i] < *min)
    *min = arr[i];
}

struct Extreme
{
    int min;
    int max;
};

struct Extreme extremes_v3(int* arr, size_t size)
{
    struct Extreme ext;
    ext.*min = arr[0];
    ext.*max = arr[0];
   for (size_t i; i < size; i++)
   { 
    if (arr[i] < e->)
    {
      *min = arr[i]; 
    }
    else if (arr[i] > *max)
    {
      *max = arr[i]; 
    }
  }
}

void extremes_v4(int* arr, size_t size, struct Extreme* ext)
{
 (*ext).min = arr[0];
 ext->max = arr[0];

 for (size_t i = 0; i < size; i++)
 {
   if(arr[i] > ext->max)
     ext->max = arr[i];
   if(arr[i] < ext->min)
     ext->min = arr[i];
 }
}

int main(void)
{
    int arr[] = { 3,5,4,1,2 };
    int min, max;

    // Should print "1, 5" 4 times preceded by the version 

    // Call v1 here
    extremes_v1(arr, 5, &min, &max ); // Can't use sizeof instead of 5 because sizeof is 20. Sizeof returns the total bytes of all elements (int is 4 bytes). Could do sizeof(arr)/sizeof(int).
    printf("v1: %d, %d\n",min,max);

    // Call v2 here
    max = extremes_v2(arr, sizeof(arr)/sizeof(int), &min);
    printf("v2: %d, %d\n", min, max);

    // Call v3 here
    struct Extreme e = extremes_v3(arr,sizeof(arr)/sizeof(int));
    printf("v3: %d, %d\n",e.min, e.max);

    // Call v4 here
    struct Extreme e4;
    extremes_v4(arr, sizeof(arr)/sizeof(int), &e4);
    printf("v4: %d, %d\n",e4.min, e4.max);

    return 0;
}
