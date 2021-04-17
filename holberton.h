#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#define SEPARATORS " ,!¡¿?\'\"\n\t"
#define MAX_NAME_SIZE 1000
#define MAX_ARGS 1000

int main(void);
void espacio(char *line, char **token);
int ejecutar(char **token, char *var2);
int line_validator(char *tok[]);
void libre(int sigint);

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _execvp(char *name, char *argv[]);
char *_strchr(char *s, char c);
char *pEnv(char *name);
void execArgs(char *file, char *argv[]);
char *_strncpy(char *dest, char *src, int n);
int compr_avanz(char **tokens, char *var2);
void _env(char *tok[]);
int _cd(char *tok[]);
void errors(char __attribute__((unused)) **error);
extern char **environ;

#endif
