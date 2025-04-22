#ifndef MAIN_H
#define MAIN_H

/* LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* PROTOTYPES */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _empty(char *buffer);
char **_split(char *str, char *sep);
void *_calloc(unsigned int nmemb, unsigned int size);
char **tokenize(char *buffer);
char *get_path(char *command);
char *get_env(char *name);
void _env(void);

extern char **environ;

#endif /* MAIN_H */
