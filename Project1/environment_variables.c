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
/*

#include "main.h"