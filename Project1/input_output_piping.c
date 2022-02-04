#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "main.h"

void IO_Redirection(tokenlist* tokens_ptr);

void O_Redirection(tokenlist* tokens_ptr);
void I_Redirection(tokenlist* tokens_ptr);
void Both_Redirection(tokenlist* tokens_ptr);

void O_Redirection(tokenlist* tokens_ptr) {
    token_list* tokens = new_tokenlist();
    int pos;

    for (int i = 0; i < tokens_ptr->size; i++) {
        if (tokens_ptr->items[i] == ">") {
            pos = i;
        }
    }

    char* ofile = tokens_ptr->items[pos + 1];

    for (i = 0; i < pos; i++) {
        add_token(tokens, tokens_ptr->items[i]);
    }

    char address[300];
    strcpy(address, "/usr/bin/");
    strcat(address, tokens_ptr->items[0])

    pid_t pid = fork();

    if (pid == 0) {
        int stdout = open(ofile, O_CREAT | O_TRUNC | O_RDWR);
        close(1);
        dup(stdout);
        close(stdout);

        execv(tokens_ptr->items[0], tokens->items);
    }

    else {
        waitpid(pid, NULL, 0);
    }
}

void I_Redirection(tokenlist* tokens_ptr) {
    token_list* tokens = new_tokenlist();
    int pos;

    for (int i = 0; i < tokens_ptr->size; i++) {
        if (tokens_ptr->items[i] == "<") {
            pos = i;
        }
    }

    char* ifile = tokens_ptr->items[pos + 1];

    for (i = 0; i < pos; i++) {
        add_token(tokens, tokens_ptr->items[i]);
    }

    pid_t pid = fork();

    if (pid == 0) {
        int stdin = open(ifile, O_RDONLY);
        close(0);
        dup(stdin);
        close(stdin);

        execv(tokens->items[0], tokens->items);
    }

    else {
        waitpid(pid, NULL, 0);
    }
}

void Both_Redirection(tokenlist* tokens_ptr) {
    token_list* tokens = new_tokenlist();

    int in_pos;
    int out_pos;

    char* ifile = tokens_ptr->items[pos + 1];
    char* ofile = tokens_ptr->items[pos + 1];

    for (int i = 0; i < tokens_ptr->size; i++) {
        if (tokens_ptr->items[i] == "<") {
            in_pos = i;
        }

        if (tokens_ptr->items[i] == ">") {
            out_pos = i;
        }
    }

    if (in_pos < out_pos) {

        for (i = 0; i < in_pos; i++) {
            add_token(tokens, tokens_ptr->items[i]);
        }

        pid_t pid = fork();

        if (pid == 0) {
            int stdin = open(ifile, O_RDONLY);
            int stdout = open(ofile, O_CREAT | O_TRUNC | O_RDWR);
    
            close(0);
            dup(stdin);
            close(stdin);

            close(1);
            dup(stdout);
            close(stdout);

            execv(tokens_ptr->items[0], tokens->items);
        }

        else {
            waitpid(pid, NULL, 0);
        }
    }

    else {

        for (i = 0; i < in_pos; i++) {
            add_token(tokens, tokens_ptr->items[i]);
        }

    }
}

void IO_Redirection(tokenlist* tokens_ptr) {

    bool in;
    bool out;

    for (int i = 0; i < tokens_ptr->size; i++) {
        if (tokens_ptr->items[i] == ">" || tokens_ptr->items[i] == "<") {

            if (i == tokens_ptr->size - 1) {
                printf("-bash: syntax error near unexpected token `newline'");
                return;
            }

            else if (i == 0) {
                printf("command not found");
                return;
            }

            if (tokens_ptr->items[i] == ">") {
                out == true;
            }
            
            if (tokens_ptr->items[i] == "<") {
                in == true;
            }

        }
    }

    if (out && !in) {
        O_Redirection(tokens_ptr);
    }

    if (in && !out) {
        I_Redirection(tokens_ptr);
    }

    if (in && out) {
        Both_Redirection(tokens_ptr);
    }
}


/*
  I/O:
   "CMD > FILE
     ◦ CMD writes its standard output to FILE
     ◦ Create FILE if it does not exist 
     ◦ Overwrite FILE if it does exist 
    CMD < FILE
     ◦ CMD receives its standard input from FILE
     ◦ Signal an error if FILE does not exist or is not a file"
   Piping:
   "Instead of redirecting the I/O with a file, piping redirects 
    the output of the first command with the input of the second command.
    CMD1 | CMD2
     ◦ CMD1 redirects its standard output to CMD2's standard input
    CMD1 | CMD2 | CMD3
     ◦ CMD1 redirects its standard output to CMD2's standard input
     ◦ CMD2 redirects its standard output to CMD3's standard input"
    We're only required to handle two pipes but handling infinite pipes 
    gets us extra credit.
     */
     
#include "main.h"
