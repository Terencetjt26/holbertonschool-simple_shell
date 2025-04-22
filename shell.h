#ifndef MAIN_H
#define MAIN_H

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
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _empty(char *buffer);
char **_split(char *str, char *sep);
void *_calloc(unsigned int nmemb, unsigned int size);
int execute_command(char **args);
char **tokenize(char *buffer);
char *get_path(char *command);
char *get_env(char *name);
void _env(void);
int _atoi(char *s);
void display_prompt(void);
int process_input(sh_t *data);

/* Builtin handlers */

int handle_builtin(sh_t *data);
int builtin_exit(sh_t *data);
int builtin_cd(sh_t *data);
int builtin_env(sh_t *data);

extern char **environ;

#endif /* MAIN_H */
