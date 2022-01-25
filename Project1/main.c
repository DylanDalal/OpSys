#include "main.h"
#include <stdio.h>

int main() {

	while(1) {
		// parse standard input
		tokenlist *input = parser();
		// "input" is an array of substrings, each substring
		// holding one of the words in the input
		tokenlist *input2 = environment_variables(input);

		// Leave this for last
		free_tokens(input);
	}
}
