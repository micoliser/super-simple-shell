#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

typedef struct path
{
	char *str;
	struct path *next;
} path_l;

int my_strlen(char *);
int my_isdigit(char *);
int my_strcmp(char *, char *);
char *my_strdup(char *);
char *my_strcpy(char *, char *);
char *my_strcat(char *, char *);
void get_signal(int);
void reverse_str(char *string);
void my_memcpy(void *, const void *, unsigned int);

ssize_t _getline(char **buffer, size_t *n, FILE *file);
char **_strtok(char *str, char *del);
char **get_commands(char *buffer, size_t n);
void free_arr(char **arr);
char *_getenv(const char *name);
void print_path_dir(void);
path_l *add_node_end(path_l **head, const char *str);
size_t print_list(const path_l *h);
path_l *path_to_list(void);
void free_list(path_l *head);

#endif
