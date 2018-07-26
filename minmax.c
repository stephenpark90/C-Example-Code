#include <stdio.h>

void extremes_v1(int* arr, size_t size, int* min, int* max)
{
    *min = arr[0];
    *max = arr[0];

    for(size_t i = 0; i < size; i++)
    {
        if(arr[i] > *max)
            *max = arr[i];
        if(arr[i] < *min)
            *min = arr[i];
    }
}

int extremes_v2(int* arr, size_t size, int* min)
{    
    *min = arr[0];
    int max = arr[0];

    for(size_t i = 0; i < size; i++)
    {
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < *min)
            *min = arr[i];
    }
    return max;
}

struct Extreme
{
    int min;
    int max;
};

struct Extreme extremes_v3(int* arr, size_t size)
{
    struct Extreme ext;
    ext.min = arr[0];
    ext.max = arr[0];

    for(size_t i = 0; i < size; i++)
    {
        if(arr[i] > ext.max)
            ext.max = arr[i];
        if(arr[i] < ext.min)
            ext.min = arr[i];
    }
    return ext;
}

void extremes_v4(int* arr, size_t size, struct Extreme* ext)
{
    (*ext).min = arr[0]; // These are the same thing.
    ext->max = arr[0]; // These are the same thing.

    for(size_t i = 0; i < size; i++)
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

    //extremes_v1(arr,5,&min,&max);
    extremes_v1(arr,sizeof(arr)/sizeof(int),&min,&max);
    printf("v1: %d, %d\n",min,max);
    
    max = extremes_v2(arr,sizeof(arr)/sizeof(int),&min);
    printf("v2: %d, %d\n",min,max);

    struct Extreme something = extremes_v3(arr,sizeof(arr)/sizeof(int));
    printf("v3: %d, %d\n",something.min,something.max);

    struct Extreme somethingelse;
    extremes_v4(arr,sizeof(arr)/sizeof(int),&somethingelse);
    printf("v4: %d, %d\n",somethingelse.min,somethingelse.max);

    return 0;
}
