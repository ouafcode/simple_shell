## SIMPLE SHELL - ALX PROJECT
### Project objectives
- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?

### Compilation

````
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
````
### Testing
##### In interactive mode
````
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
````
##### In non interactive mode
````
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
````
### Objectif 👍
task 0
betty checks executed
task 1
Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)
task 2
Handle command lines with arguments
task 3
Handle the PATH
fork must not be called if the command doesn’t exist
task 4
Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit
task 5
Implement the env built-in, that prints the current environment
task 6 advanced
Write your own getline function
Use a buffer to read many chars at once and call the least possible the read system call
You will need to use static variables
You are not allowed to use getline
task 7 advanced
You are not allowed to use strtok
task 8 advanced
handle arguments for the built-in exit
Usage: exit status, where status is an integer used to exit the shell
task 9 advanced
Implement the setenv and unsetenv builtin commands
setenv
Initialize a new environment variable, or modify an existing one
Command syntax: setenv VARIABLE VALUE
Should print something on stderr on failure
unsetenv
Remove an environment variable
Command syntax: unsetenv VARIABLE
Should print something on stderr on failure
task 10 advanced
Implement the builtin command cd:
Changes the current directory of the process.
Command syntax: cd [DIRECTORY]
If no argument is given to cd the command must be interpreted like cd $HOME
You have to handle the command cd -
You have to update the environment variable PWD when you change directory
man chdir, man getcwd
task 11 advanced
Handle the commands separator ;
task 12 advanced
Handle the && and || shell logical operators
task 13 advanced
Implement the alias builtin command
Usage: alias [name[='value'] ...]
alias: Prints a list of all aliases, one per line, in the form name='value'
alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value
task 14 advanced
Handle variables replacement
Handle the $? variable
Handle the $$ variable
task 15 advanced
Handle comments (#)
task 16 advanced
Usage: simple_shell [filename]
Your shell can take a file as a command line argument
The file contains all the commands that your shell should run before exiting
The file should contain one command per line
In this mode, the shell should not print a prompt and should not read from stdin
