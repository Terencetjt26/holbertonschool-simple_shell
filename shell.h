#ifndef SHELL_H
#define SHELL_H

/* LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

/* STRUCTURES */
/**
 * struct sh_t - structure pour les données du shell
 * @args: arguments de la commande
 * @status: statut de la dernière commande exécutée
 * @buffer: ligne lue depuis l'entrée standard
 */
typedef struct sh_t
{
	char **args;
	int status;
	char *buffer;
} sh_t;

/**
 * struct builtin_t - structure pour les commandes internes
 * @name: nom de la commande interne
 * @f: pointeur vers la fonction qui implémente la commande
 */
typedef struct builtin_t
{
	char *name;
	int (*f)(sh_t *data);
} builtin_t;

/* PROTOTYPES */
void display_prompt(void);
int read_user_input(sh_t *data);
int handle_builtin_commands(sh_t *data);
int process_input(sh_t *data);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
int _empty(char *buffer);
void *_calloc(unsigned int nmemb, unsigned int size);
int execute_command(char **args);
char **tokenize(char *buffer);
char *get_path(char *command);
char *_getenv(char *name);
int _env(sh_t *data);
int _atoi(char *s);
char *_strdup(const char *str);

/* Builtin handlers */

int handle_builtin(sh_t *data);
int builtin_exit(sh_t *data);
int builtin_cd(sh_t *data);

extern char **environ;

#endif /* SHELL_H */
