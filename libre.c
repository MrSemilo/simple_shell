#include "holberton.h"
/**
* libre - funtion
* @sigint: int
*/
void libre(int sigint)
{
	if (sigint == SIGINT)
	{
	write(STDOUT_FILENO, "\n$ ", 3);
	}
}
