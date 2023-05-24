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
