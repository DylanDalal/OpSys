Dylan Dalal
   Parser
   Environment Variables
   Prompt
   Tilde Expansion
   $Path Search
   External Command Execution
   Exit
   echo

Reece Gabbett
   Parser
   External Command Execution
   $Path Search
   cd
   jobs

Ben Bao
   I/O Redirection
   Piping
   Background Processing
      
How to compile executable:
   navigate to directory; 'make'

Contents:
   main.h
      - declarations of most/all functions
   main.c
      - inside of main() function: takes the parser function and passes it to environmental_variables() function, handles exit conditions (poorly)
   parser.c
      - pretty much the given parser implementation; some functions made public so they can be accessed elsewhere. edited the prompt
   environment_variables.c
      - implements code for environment variables and tilde expansion by analyzing first character of tokens. passes given tokenlist to path_search
   path_search.c
      - checks first token to see if it is a built-in command or if a path search is needed. if a path search fails it returns -1. this was supposed to be used for validation check, but, it didn't work. so instead i wrote valid_commmand underneath it.
   echo.c
      - implemention of echo command
   input_output_piping.c
      - IO redirection
  
How to compile your executables using your Makefile
   'make' in the directory
   ./shell
   
Known bugs and unfinished portions of the project
   "exit" does not exit on first try if you have inputtted in an invalid command
   
Special considerations or anything I should know when grading your solution
   i love u jeffrey
   
