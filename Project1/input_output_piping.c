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
     /*
     
#include "main.h"
