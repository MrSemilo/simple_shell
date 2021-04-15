#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define SEPARATORS " ,!¡¿?\'\"\n\t"

int main(void);
void espacio(char *line, char **token);
int ejecutar(char **token);
int line_validator(char *tok[]);

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);

#endif
