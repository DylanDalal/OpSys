/*
  Background Processing:
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
    /*
    
#include main.h
