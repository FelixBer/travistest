#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *nameptr;
char *ucnameptr;

void printhello(int n)
{
	char *helloptr = "Hello ";
	for(int i=0; i<n; i++) {
		printf("%s%s: %s\n", helloptr, nameptr, ucnameptr);
	}
	printf("Pointers: %p %p %p\n", ucnameptr, nameptr, helloptr);
	printf("varptrs: %p %p\n", &nameptr, &helloptr);
	printf("funcptrs: %p %p\n", &printhello, &printf);
	printf("funcptrs: %p %p\n", printhello, printf);
}

