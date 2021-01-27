// Programmer: 			Zachary William Preston
// Date:			2021 January 21
// Course:			Introduction to System Programming and Operating Systems
// Description:			This program is a recreation of the grep command on the linux
//				terminal, and will search through the contents of each line
//				in a file, and will print the line if the substring is prsent,
//				otherwise will skip the line

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_ERROR "wgrep: cannot open file"
#define SEARCH_ERROR "wgrep: searchterm [file...]"
#define TEST_FILE "test.txt"
#define TEST_WORD "program"

// Function Prototypes
void getEachLine(char *, char *);
void isSubstring(char *, char *);

// Main Function = function invocation happens here, using the argc, and argv variables, if there
//		   is only 1 argument, then an error message will appear on the terminal. If there
//		   are 2 arguments, the user will be prompted to type in a string to be searched.
//		   Finally, if there are 3 or more arguments, then the files will be opened one
//		   at a time, and the contents will be searched for the substring
int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf( "%s\n", SEARCH_ERROR );
	} else if (argc == 2) {
		char string[200];
		printf( "Enter a string: " );
		scanf( "%[^\n]%*c", string );
		isSubstring(string, argv[1]);
		printf( "\n" );
	} else {
		int i = 2;
		while (i < argc) {
			printf( "                         File Name = %s\n", argv[i] );
			printf( "--------------------------------------------------------------------\n" );
			getEachLine(argv[i], argv[1]);
			printf( "\n\n\n" );
			i++;
		}
	}
	return EXIT_SUCCESS;
}

// getEachLine = will open the file and gather the contents of each line, after which will
// 		 be entered into another function that will check whether the substring is
//		 present in the line or not
void getEachLine(char *fileName, char *word) {
	char *line = NULL;
	size_t lineSize = 0;
	ssize_t length;
	FILE *file = fopen(fileName, "r");
	if (file == NULL) {
		printf( "%s\n", FILE_ERROR );
		exit(1);
	} else {
		length = getline(&line, &lineSize, file);
		while (length >= 0) {
			isSubstring(line, word);
			length = getline(&line, &lineSize, file);
		} free(line);
		fclose(file);
	}
}

// isSubstring = will take the line from the contents and will check whether the substring
//		 is present in the line or not. Uses the strstr() function from string.h
//		 header file. If present, the line will be printed to the screen.
void isSubstring(char *string, char *subString) {
	char *result = strstr(string, subString);
	if (result != NULL)
		printf( "%s", string );
}
