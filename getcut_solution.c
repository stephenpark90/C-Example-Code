#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int opt;
    char delims[] = { '\t','\0' };
    int field = 0;

    while((opt = getopt(argc,argv,"d:f:")) != -1)
    {
        switch(opt)
        {
            case('d'):
                delims[0] = *optarg;
                break;
            case('f'):
                field = atoi(optarg); // atoi converts a string to a number. Example: -f3 converts the string "3" to an int 3. 
                break;
        }
    }

    FILE* fp = NULL;
    if(optind >= argc) // If there is more than one string in the input, then it is more than just a filename. It's an array, so use stdin.
        fp = stdin;
    else
        fp = fopen(argv[optind],"r");

    char linebuf[1024];
    while(fgets(linebuf,sizeof(linebuf),fp) != NULL)
    {
        char* p = strtok(linebuf,delims);
        for(int i = 1; i < field; i++) // Start at 1 because there can't be 0 fields. 
            p = strtok(NULL,delims);
        printf("%s\n",p);
    }

    if(fp != stdin) // Close if the fp is a file and not stdin. 
        fclose(fp);

    return 0;
}
