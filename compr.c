#include "holberton.h"
/**
 * compr_avanz - validates if the function receives an exit, env or cd
 *@var2: var2mmmmm
 *@tok: recives the value of  the funcion token.
 *
 *Return: return(0)  if the line validator is  exit, env or cd. else return (1)
 *
 */

int compr_avanz(char *tok[], char *var2)
{

	if (tok[0] == NULL)
	{
		return (2);
	}
	else if (_strcmp("exit", tok[0]) == 0)
	{
		exit(2);
	}
	else if (_strcmp("env", tok[0]) == 0)
	{
		_env(tok);
	}
	else if (_strcmp("cd", tok[0]) == 0)
	{
		_cd(tok);
	}
	else
		ejecutar(tok, var2);
	return (1);
}
