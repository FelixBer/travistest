#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "printhello.h"

extern char *nameptr;
extern char *ucnameptr;


int main(int argc, char *argv[])
{
	int i;
	if(argc<=1) { fprintf(stderr, "Missing argument\n"); exit(1); }

	nameptr = argv[1];
	ucnameptr = malloc(strlen(nameptr)+1);	
        if(!ucnameptr) { fprintf(stderr, "out of memory\n"); exit(1); }
	
	for(i=0; i<strlen(nameptr)+1; i++) {
		ucnameptr[i] = toupper(nameptr[i]);
	}
	printhello(2);	

	int pid = getpid();
	char str[1024];
	snprintf(str, 1024, "/proc/%d/maps", pid);
	FILE *f = fopen(str, "r");
	if(!f) return 1;
	char ch;
	while((ch=fgetc(f))!=EOF) { printf("%c", ch); }
}

