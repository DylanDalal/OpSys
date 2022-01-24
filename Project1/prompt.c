/*
  "The prompt should indicate the absolute working directory, the user 
  name, and the machine name. You can do this by expanding the $USER, 
  $MACHINE, $PWD environment variables." Tilde Expansion: "In Bash, tilde 
  (~) may appear at the beginning of a path, and it expands to the 
  environment variable $HOME." $Path Search: "When you enter “ls” in 
  Bash, the shell executes the program at '/usr/bin/ls'. This is a 
  simple search of a predefined list of directories. This list of 
  directories is defined in the environment variable called $PATH. 
  When the command does not include a (/) or is not a built-in function 
  (part 10), you will need to search every directory specified in $PATH. 
  $PATH is just a string where the directories are delimited by a colon. 
  So you will need to perform some string operations.
  /*

#include "main.h"
