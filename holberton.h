#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#define SIZE 1024
#define MAX_NAME_SIZE 1000
#define MAX_ARGS 1000

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define SEPARATORS " ,!¡¿?\'\"\n\t"

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

#endif
