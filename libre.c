#include "holberton.h"

void libre(int sigint)
{
	if (sigint == SIGINT)
	{
	write(STDOUT_FILENO, "\n$ ", 3);
	}
}
