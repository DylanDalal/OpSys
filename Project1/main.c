#include "main.h"
#include <stdio.h>
#include <string.h>

int main() {

	while(1) {
		// push prompt; parse standard input
		tokenlist *temp = parser();
		// "input" is an array of substrings, each substring
		// holding one of the words in the input
		tokenlist *input = environment_variables(temp);
		// so I think I need to deallocate the pointer memory
		// but its not working?

		printf("Input: ");
		for (int i = 0; i < input->size; i++) {
			printf("%s ", input->items[i]);
		}
		printf("\n");

	}
}
