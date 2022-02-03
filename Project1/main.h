#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

/* Types */
typedef struct {
	int size;
	char **items;
} tokenlist;

/* Declarations */

// Parser
extern tokenlist *parser();
extern void free_tokens(tokenlist *tokens);
char *get_input(void);
extern tokenlist *get_tokens(char *input);
extern tokenlist *new_tokenlist(void);

extern int is_valid(tokenlist *tokens);

// Environment Variables
extern tokenlist *environment_variables(tokenlist *tokens);

// Path Search
extern int path_search(tokenlist *tokens);

// Built-in Functions
extern void echo(tokenlist *tokens);
//extern void cd(tokenlist *tokens);
//extern void jobs(tokenlist *tokens);
extern int exitShell(tokenlist **a, tokenlist **b, tokenlist **c, tokenlist **input);


#endif
