int file_read (const char *path, const int lineNumber, const *buffer)
{
FILE *file= fopen(path,"r");
if(!file) {
	fprintf(stderr, "unable to open %s\n", path);
	return -1;
}
char temp[65];
int i = 1;
while(fgets(temp, 64, file) != NULL) {
	if(i++ == lineNumber) {
		memset(buffer, 0, 64);
		strncpy(buffer, temp, 64);
		fclose(file);
		printf("line size is %lu\n", strlen(buffer));
		return strlen(buffer);
	}
}
fclose(file);
printf("NOPE\n");
return -1;
