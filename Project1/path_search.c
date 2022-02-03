//#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "main.h"


int path_search(tokenlist *tokens) {
	// determine if the input is a built-in function against test
	if (strcmp(tokens->items[0], "echo") == 0) {
		echo(tokens);
	}

	else if (strcmp(tokens->items[0], "cd") == 0) {
		char s[100];
		//Printing the current working directory
		printf("%s\n", getcwd(s, 100));
		//Changing the current working directory to the previous directory
		chdir("..");
		//Printing the now current working directory
		printf("%s\n", getcwd(s, 100));
	}
	else if (strcmp(tokens->items[0], "jobs") == 0) {
		FILE* fp = popen("ps -C shell --format '%P %p'", "r");
		if (fp == NULL)
		{
			printf("ERROR!\n");
		}

		char parentID[256];
		char processID[256];
		while (fscanf(fp, "%s %s", parentID, processID) != EOF)
		{
			printf("PID: %s  Parent: %s\n", processID, parentID);

			// Check the parentID to see if it that of your process
		}

		pclose(fp);
	}
	else if (strcmp(tokens->items[0], "exit") == 0) {
		return 0;
	}
	else { /* Path Search */
		pid_t pid;
		pid = fork();
		int status;

		//if fork did not work
		if (pid == -1) {
			printf("FORK ERROR");
			exit(EXIT_FAILURE);
			return -1;
		}
		//if fork worked
		else if (pid == 0) {
			// Split input into the command and its arguments. Assumes one-word command.
			const char* cmd = tokens->items[0];
			char** args = tokens->items + 1;
			// Get the $PATH string and copy it to make it editable.
			const char* temp = getenv("PATH");
			char* full = malloc(sizeof(char) * (strlen(temp) + 1));
			strcpy(full, temp);

			// Split $PATH string into tokenized expression on the colon.
			char* path = strtok(full, ":");

			// "found" variable updates to stop the while loop
			int found = 0;

			// Cycle through $PATH tokens to find the function.
			while (path != NULL && found == 0) {
				// Create "Copy" path that holds the concatenated possible path to the command.
				char* copy = malloc(strlen(path) + strlen(cmd) + 5);
				strcpy(copy, path);
				strcat(copy, "/");
				strcat(copy, cmd);

				// Execv returns -1 if it fails
				if (execv(copy, args) != -1) {
					printf("Found command at %s", path); // error checking
					found = 1;
					return 0;
				}
				//free(copy);
				path = strtok(NULL, ":");
			}

			if (found == 0) {
				printf("Command '%s' not found.\n", cmd);
				return -1;
			}

		}
		//delete fork
		else {
			waitpid(pid, &status, 0);
		}

	}
	return 0;
}
