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
void execArgs(char *file, char *argv[])
{
	int i = 0;
	char *newArgv[MAX_ARGS + 1];

	execve(file, argv, environ);

	if (errno == ENOEXEC)
	{
		for (i = 0; argv[i]; i++)
		{
		}
		if (i >= MAX_ARGS)
		{
			exit(EXIT_FAILURE);
		}
		newArgv[0] = "sh";
		newArgv[1] = file;
		for (i = 1; argv[i] != 0; i++)
		{
			newArgv[i + 1] = argv[i];
		}
		newArgv[i + 1] = NULL;
		execve("/bin/sh", newArgv, environ);
	}
}
/**
 * __execvp - implentation of the "execvp" function
 *
 * @name: char pointer
 * @argv: argument vector
 * * * * *
 * ENOENT - No such file or directory (POSIX.1-2001)
 * EACCES - Permission denied (POSIX.1-2001)
 * * * * *
 * Return: -1
 */
int __execvp(char *name, char *argv[])
{
	char *path = pEnv("PATH");
	char fullName[MAX_NAME_SIZE + 1];
	char *first = NULL, *last = NULL;
	int size = 0, noAccess = 0;

	if (_strchr(name, '/') != 0)
	{
		execArgs(name, argv);
		exit(127);
	}
	if (!path)
		path = "/usr/local/bin:/bin:/usr/bin:/usr/local/games:/usr/games";
	for (first = path; ; first = last + 1)
	{
		for (last = first; (*last != 0) && (*last != ':'); last++)
		{
		}
		size = last - first;
		_strncpy(fullName, first, size);
		if (last[-1] != '/')
			fullName[size++] = '/';
		_strcpy(fullName + size, name);
		execArgs(fullName, argv);
		if (errno == EACCES)
		{
			noAccess = 1;
		}
		else if (errno != ENOENT)
			break;
		if (*last == 0)
		{
			if (noAccess)
			{
				errno = EACCES;
			}
			break;
		}
	}
	return (-1);
}
int ejecutar(char **token, char *var2)
{
	pid_t pid;
	int ejemplo;

	pid = fork();
	if (pid == 0)
	{
	ejemplo = _execvp(token[0], token);
	if (ejemplo)
	{
	printf("Error");
	exit(1);
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
