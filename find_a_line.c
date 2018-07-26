#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int line_Finder(char* buffer, int lineNumber);

int main()
{
	char buffer[128];
	printf("Size of buffer: %d\n",sizeof(buffer));
	line_Finder(buffer, 6);
}


int line_Finder(char* buffer, int lineNumber)
{
	FILE* fp = fopen("test.txt", "r");
	if(fp == NULL)
	{
		fprintf(stderr, "The fopen function failed!\n");
		return 1;
	}

	int counter = 1;
	char line[128] = {0};
	while (fgets(line, sizeof(line), fp) != NULL)
	{
		if(strstr(line, "Stephen") == line)
		{
			memset(buffer, 0, 64);
			strncpy(buffer, line, 63);
			fclose(fp);
			printf("%s", line);
			return strlen(buffer);
		}
		counter++;
	}
	fclose(fp);
	return 1;

}
