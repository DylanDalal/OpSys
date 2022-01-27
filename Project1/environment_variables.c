/* 
  Every program runs in its own environment. In the bash shell, 
  you can type 'env' to see a list of all your environmental variables. 
  Your job is to replace every token that starts with a dollar sign 
  character into its corresponding value. For example, tokens [“echo”, 
  “$USER”] should expand to [“echo”, “abbinant”]. The output should look like: 
  > echo $USER
    abbinant  
  You can do this using the getenv() function. On how to use getenv, 
  read its man page. Note that this expansion happens no matter the command.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

tokenlist *environment_variables(tokenlist *tokens) {  
	for (int i = 0; i < tokens->size; i++) {
		if (tokens->items[i][0] == '$')	{
			char *env_var = getenv(tokens->items[i] + 1);
			if (env_var != NULL) {
				tokens->items[i] = env_var;
			}
		} else if (tokens->items[i][0] == '~') {
			const char *path = tokens->items[i] + 1;
			const char *hom = getenv("HOME");
			char *dir;
			dir = malloc(strlen(path)+strlen(hom)+1);
			strcpy(dir, hom);
			//strcat(dir, "/");
			strcat(dir, path);
			tokens->items[i] = dir;
		} else if (tokens->items[i][0] == 'l' && tokens->items[i][1] == 's') {
			
			const char* path = tokens->items[i] + 1;
			const char* home = getenv("PATH");

			//make copy of path (cant edit returned string must make copy)
			char* hom;
			hom = malloc(sizeof(char) * (strlen(home) + 1));
			strcpy(hom, home);


			  
			
			char* const parmList[] = { "/bin",  NULL};

			

			//split up this string after every :
			
			char* dir;
			dir = malloc(strlen(path) + strlen(hom) + 1);
			char* token = strtok(hom, ":");
			int i = 0;
			while (token != NULL) {
				//parmList[i] = token;
				
				i++;
				//strcat(dir, token);
				//strcat(dir, "\n");
				// 
				//printf(" %s\n", token); 
				token = strtok(NULL, ":");
			}
			//Yo
			
			
			execvp(tokens->items[0], parmList);
				

			


			//strcpy(dir, hom);
			//strcat(dir, "/");
			//strcat(dir, path);
			
			tokens->items[i] = dir;
			
		}
	}

	return tokens;
}
