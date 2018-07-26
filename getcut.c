#include <unistd.h>
#include <stdio.h>
#include <string.h> // see strtok()
#include <stdlib.h>

int main(int argc, char** argv)
{
    /* 
        Create a program that behaves similarly to the
        cut command. Support -d and -f options and
        optionally a filename. To reduce the scope of 
        the problem, limit the -f argument to a 
        single field.
    */

  int field = 0;
  char *delimiter = NULL;
  int option;
  opterr = 0;
  FILE *file;
  char filename[];
  
  while ((option = getopt(argc, argv, "f:d:")) != -1) // The : after the letters mean input is expected as an argument after those flags. The -1 just has to be there for the function to work.
  { 
    // Determine which options to use based on the flags present.
    switch (flag)
    {
      case 'f' :
        field = optarg; // Use the field option since the flag is present.
      break;

      case 'd' :
        delimiter = optarg;  // Use the delimiter option since the flag is present.
      break;

      default:
        abort();
    }
  }
  if ((field != NULL) && (delimiter != NULL))
  {
    
  }
  else
  {
    //error
  }
  if (argv[optind] != NULL) // If there is an optional filename,
  {
    filename = argv[optind];
    file = fopen(filename, r);
  }

  return 0;
}
