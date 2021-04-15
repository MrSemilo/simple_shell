#include "holberton.h"

void libre(int sigint)
{
/**	(void)sigint;
*
*	signal(SIGINT, libre);
*	write(STDOUT_FILENO, "\n$ ", 3);
*	fflush(stdout);
*/
	if (sigint == SIGINT)
	{
	write(STDOUT_FILENO, "\nCtrl+C\n", 8);
	}
}
