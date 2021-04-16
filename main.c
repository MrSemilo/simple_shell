#include "holberton.h"
/**
 * main - Funcion main.
 *
 *Return: return (0).
 */
int main(void)
{
	char *token[103];
	int var1;
	char *var2 = NULL;
	size_t var3 = 0;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		var1 = getline(&var2, &var3, stdin);
		if (var1 == EOF)
		{
			free(var2);
			return (0);
		}
	espacio(var2, token);
	ejecutar(token);
	}
	return (0);
}
