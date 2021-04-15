#  Simple Shell 🚀

_holberton project on shell_

## Description

The objective of this project is to create from scratch a simple UNIX command interpreter with limited functionality but applying the core concepts of a more robust shell. In simple words, the shell is a program that takes commands from the keyboard and gives them to the operating system to perform. It incorporates many features and generally executes other commands.

* How does a shell work.
* What is a PID and a ppid, and how to use them.
* How to manipulate the environment of the current process.
* What is the difference between a function and a system call.
* How to create processes.
* How does the shell use the ```PATH``` to find the programs.
* How to execute another program with the ```execve``` system call.
* How to suspend the execution of a process until one of its children terminates.

### Compilation
You can compile the files using this command to check that there are no errors:
```
$ gcc -Wall -pedantic -Werror Wextra *.c -o hsh
```

### Usage
Enter the interactive mode after compilation:
```bash
$ ./hsh
 simple@shell $ /bin/ls
 README.md exec.c holberton.h main.c prompt.c
 simple@shell $
 simple@shell $ exit
$
```
---

## Contribution:heavy_check_mark:
Create a new branch with the name of your feature or fix and make a pull request to develop branch explaining your work.

---

# AUTHORS ✒️
* Adrian Guerra.
* Camilo Valencia.
