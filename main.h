#ifndef _MAIN_
#define _MAIN_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

ssize_t _getline(char **buffer, size_t *n, FILE *file);
char **_strtok(char *str, char *del);
char **get_commands(char *buffer, size_t n);
void free_arr(char **arr);
char *_getenv(const char *name);

#endif
