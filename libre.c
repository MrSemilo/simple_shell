#include "holberton.h"

void libre(int sigint)
{
	if (sigint == SIGINT)
	{
	write(STDOUT_FILENO, "\nCtrl+C\n", 8);
	}
}
