#include "holberton.h"
/**
* espacio - Funcion espacio.
* @line: var.
* @token: var.
* Return: 0.
*/
void espacio(char *line, char **token)
{
	int conta = 0;
	char *var4 = NULL;

	var4 = strtok(line, SEPARATORS);
	token[conta] = var4;

	if (!token)
		exit(1);

	for (conta = 1; var4 != NULL; conta++)
	{
		var4 = strtok(NULL, SEPARATORS);
		token[conta] = var4;
	}
}

/**
 *ejecutar - check  if the command recived is true.
 *
 *@token: recives the value of  the funcion token.
 *
 *Return: return (1).
 */

int ejecutar(char **token, char *var2)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(token[0], token, NULL) == -1)
		{
			
		perror("Error opening the file");
			exit(EXIT_FAILURE)
        	
		}
	free(var2);
	exit(0);
	}
	else if (pid < 0)
	{
		perror("ERROR");
		return (0);
	}
	else
		wait(NULL);
	return (0);
}
