#include "holberton.h"

/**
 * *_strchr - check string for certain char
 * @s: char pointer
 * @c: char.
 *
 * Return: Always 0.
 */

char *_strchr(char *s, char c)
{
	while (*s++)
	{
		if (*s == c)
			return (s);
	}
	return (0);
}

/**
 * _strcmp - compares string s1 and s2
 *
 * @s1: value from main
 * @s2: value from main
 *
 * Return: value of difference
 */

int _strcmp(char *s1, char *s2)
{
	int counter, difference;

	for (counter = 0; s1[counter] != '\0' || s2[counter] != '\0'; counter++)
	{
		difference = s1[counter] - s2[counter];
		if (difference != 0)
			break;
	}
	return (difference);
}

/**
 * _strcpy - copy string
 * @dest: char
 * @src: char
 * Return: Always 0.
 */

char *_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (dest);
}

/**
 * _strlen - counts string length
 *
 * @s: value from main
 *
 * Return: Always 0 (Success)
 */

int _strlen(char *s)
{
	int counter = 0;

	while (s[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

int _execvp(char *name, char *argv[])
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

char *pEnv(char *name)
{
	char **envPtr;
	char *ptr;
	char *namePtr;

	for (envPtr = environ; *envPtr; envPtr++)
	{
		for (ptr = *envPtr, namePtr = name; *ptr == *namePtr;
		     ptr++, namePtr++)
		{
			if (*ptr == '=')
				break;
		}
		if ((*ptr == '=') && (!*namePtr))
			return (ptr + 1);
	}
	return (NULL);
}

void execArgs(char *file, char *argv[])
{
	int i = 0;
	char *newArgv[MAX_ARGS + 1];

	_execve(file, argv, environ);

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
		_execve("/bin/sh", newArgv, environ);
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
