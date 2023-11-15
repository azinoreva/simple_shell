#include "main.h"

/**
* get_path - takes path from promt and checks if path is valid. Returns
* the valid path, else null
* @command: the partial path of to be checked if valid
* Return: return a pointer to the path string, else NULL
*/
char *get_path(char *command)
{
	char *path = getenv("PATH");
	char *dir = NULL, *path_copy = NULL, *valid_path = NULL, *full_path = NULL;
	struct stat st;

	if ((path == NULL && command == NULL) || command == NULL)
	{
		perror("Unable to access the PATH or command environment variable.");
		return (NULL);
	}
	if (stat(command, &st) == 0) /*check if a path on its own*/
		return (_strdup(command));
	if (path == NULL)
		path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
	path_copy = _strdup(path);
	if (path_copy == NULL)
		return (NULL);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = malloc((_strlen(dir) + _strlen(command) + 2) * sizeof(char));
		if (full_path == NULL)
		{
			perror("malloc: ");
			return (NULL);
		}
		_strcpy(full_path, dir), _strcat(full_path, "/");
		_strcat(full_path, command);
		if (stat(full_path, &st) == 0)
		{
			valid_path = _strdup(full_path);
			free(full_path);
			break;
		}
		dir = strtok(NULL, ":");
		free(full_path);
	}
	free(path_copy);
	return (valid_path);
}
