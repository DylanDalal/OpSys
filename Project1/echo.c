/*
  Implentation of echo command.
  ◦Outputs whatever the user specifies 
  ◦Example:
    > echo ABC $USER abc ABC
    ABC abbinant abc ABC 
  */
#include <stdio.h>
#include <main.h>

void echo(tokenlist *tokens) {
	for (int i = 1; i < tokens->size; i++) {
		printf("%s ", tokens->items[i]);
	}
	printf("\n");
}
