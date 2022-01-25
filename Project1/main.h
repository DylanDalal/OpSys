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

// Environment Variables
extern tokenlist *environment_variables(tokenlist *tokens);

#endif
