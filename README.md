# SIMPLE SHELL PROJECT

## INTRODUCTION
Simple shell is a command language interpreter that takes commands from the standard input and executes them. It's written in C language and in Betty coding style. It supports all the commands that can be found in the PATH environment variable.


## this project helped us understand how to :
- Get to know the basics of the shell.
- Use PID & PPID.
- Use system calls.
-  Execute programs.
- Create processes.
- Prioritise processes using Fork and wait.
- Get and use file information.
- Work with the system's environment and use its contents.
- Manipulate the system's environment: set, unset.
- Code your simple shell from scratch.

###How to use

- ** Just Compile all the c files using :**
`$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
- ** Lunch the shell using : **
`$ ./hsh`
- ** type your commands for e.g : **
`$ ls -la `

###Files

| File name | Functions  | Description                  |
| ------- | ----------------- | ------------------------------- |
|header.h| Prototypes |  Contains all the function's prototypes and the Structs.   |
| main.c  | `main()` | Contains the main program function.       |
| main.c  | `magic()` | Contains the magic program function.       |
|  split.c | `allocation()` `split()` |  Contains the split function and its tool.   |
|  str_tools.c | `_strcpy()` `_strcat()` `_strcmp()` `_strlen()` `_strdup()` |  Contains the tools functions.   |
|  tools.c | `test_built_in()` `words()`   |  Contains the tools functions.   |
|  list.c | `lines()` `list_length()`  |  Contains the tools functions.   |
|  print.c | `csignal()` `_putchar()` `_print()` `print_number()`   |  Contains the tools functions.   |
| history.c | `history()` `_print_history()` `print_list()` `print_file()` `write_his()` | Contains the history functions.       |
| free.c | `free_mat()` `free_list()` `free_all()` |  Contains the free functions.   |
|  exec.c | `_exec()` |  Contains the execution function.   |
|  path.c | `path()` `find_home_path()`  | Contains the path function.       |


###Functions

| Function name | Description                    |
| ------------- | ------------------------------ |
| `main()`      | The Shell's main function.       |
| `magic()`   | Where the magic is done.    |
| `_exec()`   | Executes commands    |
| `_print()`      | Display a string in the standard output.       |
| `_putchar()`      | Display a character in the standard output.       |
| `print_number()`      | Prints numbers in the standard output.     |
| `words()`      | Splits a string into words based on a delimiter and how many words in it.       |
| `path()`      | Finds the path of a given command.       |
| `find_home_path()`      | Finds the path of the user's home.       |
| `split()`      | Split a string into words and put them in a table.       |
| `allocation()`      | Allocate memory for words.       |
| `_strcpy()`      | Copies a string into another.       |
| `_strcat()`      | Concatinates two strings.       |
| `_strcmp()`      | Compare two strings.       |
| `_strlen()`      | Length of a string.       |
| `_strdup()`     | Duplicate a string to another.       |
| `test_built_in()`      | Tests if the comand is a built-in.       |
| `free_mat()`      | Frees a table's memory.       |
| `free_list()`      | Frees a list's memory.       |
| `free_all()`      | Frees all allocated memory.       |
| `csignal()`   | Handles the CTRL-C signal.    |
| `lines()`   | Number of commands in the history file.    |
| `list_length()`   | Number of commands of the curent session.   |
| `history()`   | Stores the commands of the curent session    |
| `_print_history()`   | Prints the commands history    |
| `print_list()`   | Prints the commands history of the curent session.    |
| `csignal()`   | Prints the commands history in the history file.    |
| `write_his()`   | Writes the commands history of the curent session in the history file.    |


----

###Libraries

- ` <stdio.h>`
- `<stdlib.h>`
- ` <string.h>`
- `<unistd.h>`
- `<fcntl.h>`
- `<sys/wait.h>`
- `<sys/stat.h>`
- `<sys/types.h>`
- `<signal.h>`

###Header files

- `<header.h>`

###Authors:

- **Taib Kefi  - [Mail](mailto:taibkefi@yahoo.fr "Yahoo") **
- **Mhamed Azouzi - [Mail](mailto:azouzimhamed@gmail.com "Gmail") **
