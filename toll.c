#include "holberton.h"


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
