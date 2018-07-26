#include <stdio.h>

/*
    Implement swap such that the values pointed to by
    a and b are swapped.
*/

void swap(unsigned short* a, unsigned short* b)
{
  unsigned short tmp = *a; // Assign a tmp variable to be whatever is in memory location a.
  *a = *b; // Make the value in location a to be whatever is in b.
  *b = tmp; // Make the value in location b to be the tmp variable.
}

/*
  Note: A memory location cannot be another memory location. The bottom example does not work because the memory locations are completely different. You have to assign it a value.
  void swap(unsigned short* a, unsigned short* b)
{
  unsigned short* tmp = a; // Memory location tmp cannot possible equal memory location a. They are two different memory locations which each hold different values (right now tmp holds garbage). 
  a = b;
  b = tmp; 
}
*/

int main(void)
{
    unsigned short a = 3;
    unsigned short b = 7;
    swap(&a,&b);

    // should print "7, 3"
    printf("%u, %u\n",a,b);
    return 0;
}
