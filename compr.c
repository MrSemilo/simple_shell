#include "holberton.h"
/**
 *line_validator - validates if the function receives an exit, env or cd
 *
 *@tok: recives the value of  the funcion token.
 *
 *Return: return(0)  if the line validator is  exit, env or cd. else return (1)
 *
 */

int compr_avanz(char *tok[])
{

	if (tok[0] == NULL)
	{
		return (2);
	}
	if (_strcmp("exit", tok[0]) == 0)
	{
		 exit(2);
	}
	if (_strcmp("env", tok[0]) == 0)
	{
		_env(tok);
	}
	if (_strcmp("cd", tok[0]) == 0)
	{
		_cd(tok);
	}
	else
		execute(tok, line);
	return (1);
}
