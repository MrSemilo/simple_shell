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
