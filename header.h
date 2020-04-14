#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

/**
 * struct history - command history.
 * @cmd: command.
 * @next : next node in the list.
 * Description: singly linked list node structure.
 */
typedef struct history
{
	char *cmd;
	struct history *next;
} his;


int magic(char *, int, his**, char **, char**);
int words(char *, char);
void _print(char *);
void print_error(char *);
char **split(char *, char, int);
void free_mat(char **);
void path(char **, char **, char *);
void _strcat(char *, char *);
void _strcpy(char *, char *);
char *_strdup(char *);
int _strlen(char *);
int test_built_in(char *, char **, his **);
int _strcmp(char *, char *);
void _exec(char **, char **, char **, int, int);
void csignal(int);
int _putchar(char);
void print_number(int);
int lines(char *);
int history(char *, his **);
void _print_history(his **, char **);
void print_list(his **, int, int);
void print_file(char *, int, int);
void write_his(his **, char **);
void free_list(his **);
char *find_home_path(char **);
int list_length(his **);
void free_all(char *, his **, char **);
char *strip(char *);
char *strip_built_in(char *);

#endif
