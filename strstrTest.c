#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *array1 = "Hello there, how are you";
	char *array2 = "Hello";
	char *array3 = "there";
	char *array4 = "what";
	char *final;
	char *final2;
	final = strstr(array1, array2);
	final2 = strstr(array1, array4);
	printf( "%s\n", final );
	if (final2 == NULL)
		printf( "Not a substring\n" );
	else
		printf( "%s\n", final2 );
	return EXIT_SUCCESS;
}
