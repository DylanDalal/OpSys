//#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	else { // if not, path search



		const char* cmd = tokens->items[0];
		char** args = tokens->items + 1;
		char* full = getenv("PATH");
		printf("full: %s", full);
		char* path = strtok(full, ":");
		printf("path: %s", path);
		int cont = 0;
		while(path != NULL && cont == 0) {
//			printf("--");
			char *copy = malloc(strlen(path) + 1);
			strcpy(copy, path);
			strcat(copy, "/");
			strcat(copy, cmd);
			printf("%s\n", copy);
			//execv(path);
			free(copy);
			path = strtok(NULL, ":");
			printf("\n--4\n");

		}

//
//			//strcpy(dir, hom);
//			//strcat(dir, "/");
//			//strcat(dir, path);
//
//		tokens->items[i] = dir;
	}
}
