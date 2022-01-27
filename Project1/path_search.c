//#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "main.h"


extern void path_search(tokenlist *tokens) {
	// determine if the input is a built-in function against test
	if (strcmp(tokens->items[0], "echo") == 0) {
		echo(tokens);
	}
//	else if (strcmp(tokens, "jobs") == 0) {
//		echo(tokens);
//	} else if (strcmp(tokens, "cd") == 0) {
//		cd(tokens);
//	}
	else { /* Path Search */
		// Split input into the command and its arguments. Assumes one-word command.
		pid_t pid;
		const char* cmd = tokens->items[0];
		char** args = tokens->items + 1;
		printf("\n\n%s\n%s\n", args[0], args[1]);
		// Get the $PATH string and copy it to make it editable.
		const char* temp = getenv("PATH");
		char* full = malloc(sizeof(char) * (strlen(temp) + 1));
		strcpy(full, temp);

		// Split $PATH string into tokenized expression on the colon.
		char* path = strtok(full, ":");

		// "found" variable updates to both stop the while loop and
		int found = 0;

		// Cycle through $PATH tokens to find the function.
		while(path != NULL && found == 0) {
			// Create "Copy" path that holds the concatenated possible path to the command.
			char* copy = malloc(strlen(path) + strlen(cmd) + 5);
			strcpy(copy, path);
			strcat(copy, "/");
			strcat(copy, cmd);
			printf("%s", copy); // Error checking to show the paths

			// Execv returns -1 if it fails
			if (execv(copy, args) != -1) {
				printf("Found command at %s", path); // error checking
				found = 1;
			}
			//free(copy);
			path = strtok(NULL, ":");
		}

		if (found == 0) {
			printf("Command '%s' not found.\n", cmd);
		}
	}
}
