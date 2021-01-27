// Programmer:			Zachary William Preston
// Date:			2021 January 21
// Course:			Intro to Systems Programming and Operating Systems
// Description:			Program to spoof the cat command on the linux terminal
//				which will print the contents of a file to the terminal
//				screen.

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#define FILE_ERROR "wcat: cannot open file"
#define ARGC_ERROR "wcat: no input file"
#define TEST_FILE1 "hello.txt"
#define TEST_FILE2 "goodbye.txt"

// Function Prototypes
int getFileLength(char *);
void getFileChar(char *, char *, int);

// Main Function = Calls in argc, and argv. Argc is the argument count of the command line entry,
//		   whereas argv is the vector of arguments input by the user in the command. Uses
//		   the for loop to iterate through the argument vector until all have been printed.
int main(int argc, char *argv[]) {
	if (argc <= 1) {
		printf( "%s\n", ARGC_ERROR );
		exit(0);
	} else {
		for (int i = 1; i < argc; i++) {
			int length = getFileLength(argv[i]);
			char *contents = (char *) malloc (length * sizeof(char));
			getFileChar(argv[i], contents, length);
			printf( "                            File Name = %s\n", argv[i] );
			printf( "------------------------------------------------------------------------\n" );
			printf( "%s\n\n\n", contents );
		}
	}
	return EXIT_SUCCESS;
}

// getFileLength = gets the number of characters of the file, and then returns it as an integer. If
//		 the file cannot open, then prints an error message to the screen and then aborts
//		 the program. Otherwise, iterates the file, reading each character and increments
//		 length by one, finally closing the file and returning the length.
int getFileLength(char *fileName) {
	FILE *file = fopen(fileName, "r");
	if (file == NULL) {
		printf( "%s\n", FILE_ERROR );
		exit(1);
	} else {
		int length = 0;
		while (getc(file) != EOF)
			length++;
		fclose(file);
		return length;
	}
}

// getFileChar = gets the contents of the file, and stores them in the contents pointer, that was
//		 memory allocated in the for loop using the previous function, finally adding a
//		 null character \0 at the end of the array.
void getFileChar(char *fileName, char *contents, int length) {
	FILE *file = fopen( fileName, "r" );
	if (file == NULL) {
		printf( "%s\n", FILE_ERROR );
		exit(1);
	} int i = 0;
	while (i < length) {
		contents[i] = getc(file);
		i++;
	} fclose(file);
	contents[i] = '\0';
}
