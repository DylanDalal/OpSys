/*
  Implentation of echo command.
  ◦Outputs whatever the user specifies 
  ◦Example:
    > echo ABC $USER abc ABC
    ABC abbinant abc ABC 
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>

void echo(tokenlist *tokens) {
	int i;
	int pipe = 0;
	FILE *fptr;
	char filename[100], c;

	for (i = 1; i < tokens->size; i++) {
		if (strcmp(tokens->items[i], "|") == 0) {
			pipe = i+1;
			break;
		} else
			printf("%s ", tokens->items[i]);
	}
	if (pipe != 0) {
		fptr = fopen(tokens->items[pipe], "r");
	    if (fptr == NULL) {
	        printf("Cannot open file \n");
	        exit(0);
	    }
	    c = fgetc(fptr);
	    while (c != EOF)
	    {
	    	printf ("%c", c);
	    	c = fgetc(fptr);
	    }
	    fclose(fptr);

	}
	printf("\n");
}
