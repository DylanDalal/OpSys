#include "main.h"
#include <stdio.h>
#include <string.h>

int main() {
	int cont = 0;
	tokenlist *a = new_tokenlist();
	tokenlist *b = new_tokenlist();
	tokenlist *c = new_tokenlist();
	while(cont == 0) {
		// push prompt; parse standard input
		tokenlist *temp = parser();

		// "input" is an array of substrings, each substring
		// holding one of the words in the input

		tokenlist *input = environment_variables(temp);
		// so I think I need to deallocate the pointer memory
		// but its not working?

		// Exit
		if (strcmp(input->items[0], "exit") == 0) {
			cont = 1;
			if (a->items[0] == NULL) {
				printf("No valid commands were executed in this shell.\n");
			}
			else if (b->items[0] == NULL) {
				printf("The last valid command was:\n1. ");
				int i;
				for (i = 0; i < a->size; i++)
					printf("%s ", a->items[i]);
				printf("\n");
			}
			else if (c->items[0] == NULL) {
				printf("The last valid commands were:\n1. ");
				int i;
				for (i = 0; i < a->size; i++)
					printf("%s ", a->items[i]);
				printf("\n2. ");
				for (i = 0; i < b->size; i++)
					printf("%s ", b->items[i]);
				printf("\n");
			}
			else {
				printf("The last valid commands were:\n1. ");
				int i;
				for (i = 0; i < a->size; i++)
					printf("%s ", a->items[i]);
				printf("\n2. ");
				for (i = 0; i < b->size; i++)
					printf("%s ", b->items[i]);
				printf("\n3. ");
				for (i = 0; i < c->size; i++)
					printf("%s ", c->items[i]);
				printf("\n");
			}
		}
		if (input->items[0] != NULL) {
			c = b;
			b = a;
			a = input;
		}
		if (cont == 1)
			break;
	}
}

	// Debugging: will need to be removed later
	//		printf("Input: ");
	//
	//		for (int i = 0; i < input->size; i++) {
	//			printf("%s ", input->items[i]);
	//		}


