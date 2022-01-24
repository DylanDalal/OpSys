1. Finish Parser:
   "Code will be provided to parse the command string into 
    separate tokens, but you will need to build upon this 
    code for further parsing."
    
2. Environment Variables:
   "Replace every token that starts with a dollar sign character 
    into its corresponding value."
    
3. Prompt:
   "The prompt should indicate the absolute working directory, 
    the user name, and the machine name. You can do this by 
    expanding the $USER, $MACHINE, $PWD environment variables."
   Tilde Expansion:
   "In Bash, tilde (~) may appear at the beginning of a path, 
    and it expands to the environment variable $HOME."
   $Path Search:
   "When you enter “ls” in Bash, the shell executes the program at 
    '/usr/bin/ls'. This is a simple search of a predefined list of 
    directories. This list of directories is defined in the environment 
    variable called $PATH. When the command does not include a (/) or 
    is not a built-in function (part 10), you will need to search every 
    directory specified in $PATH. $PATH is  just a string where the 
    directories are delimited by a colon. So you will need to perform 
    some string operations."
    
4. External Command Execution:
   "Either the command included a slash or you had to carry out the 
   $PATH search, you now have a path to the program you are trying to 
   execute. To put it simply, we have to fork() and execute the command 
   in the child process using execv()."
   
5. I/O Redirection:
   "CMD > FILE
     ◦ CMD writes its standard output to FILE
     ◦ Create FILE if it does not exist 
     ◦ Overwrite FILE if it does exist 
    CMD < FILE
     ◦ CMD receives its standard input from FILE
     ◦ Signal an error if FILE does not exist or is not a file"
     
6. Piping: 
   "Instead of redirecting the I/O with a file, piping redirects 
    the output of the first command with the input of the second command.
    CMD1 | CMD2
     ◦ CMD1 redirects its standard output to CMD2's standard input
    CMD1 | CMD2 | CMD3
     ◦ CMD1 redirects its standard output to CMD2's standard input
     ◦ CMD2 redirects its standard output to CMD3's standard input"
    We're only required to handle two pipes but handling infinite pipes 
    gets us extra credit.

7. Background Processing:
   "Up to this point, the shell waited to prompt for more user input 
   when there were any external commands running. Background processing 
   is a way to tell your shell to not wait for the external command to 
   finish.
   CMD &
    ◦ Execute CMD in the background
    ◦ When execute starts, print [Job number] [CMD’s PID]
    ◦ When execution completes, print [Job number]+ [CMD’s command line]
   CMD1 | CMD2 & 
    ◦ Execute CMD1 | CMD2 in the background
    ◦ When execution starts, print [Job number] [CMD2's PID]
    ◦ When execution completes, print [Job number]+ [CMD1 | CMD2 command line] 
   Must support redirection with background processing:
    ◦ CMD > FILE &
    ◦ CMD < FILE &
    ◦ CMD < FILE_IN > FILE_OUT &
    ◦ CMD > FILE_OUT < FILE_IN & "
    
 8. Built-in Functions:
   "exit
    cd
    echo
    jobs"
