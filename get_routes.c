#include "shell.h"
/**
 * append_path - function that concatenates the path and the command
 * @path: path given
 * @comands: comands givev
 * Return: concatenation
 */
char **get_routes(char **commands, char **env)
{
    char *path = NULL, **dir_path = NULL, *token = NULL;
    int num_dir = 0, w, i, len_comm = 0, len_dir = 0, k , j;
    path = get_path_id(env);
    for (w = 0; path[w] != '\0'; w++)
	{
	    if (path[w + 1] == ':' || path[w + 1] == '\0')
		    num_dir++;
	}
    dir_path = malloc(sizeof(char *) * (num_dir + 1));
    if (dir_path == NULL)
        return (NULL);
    i = 0;
	token = strtok(path, ":");
	while (token != NULL)
	{
        len_dir = _strlen(token);
        len_comm = _strlen(commands[0]);
		dir_path[i] = malloc(sizeof(char) * ( len_dir + len_comm + 2));
		if (dir_path[i] == NULL)
		{
			free_commands(dir_path);
			return (NULL);
		}
        else 
        {
            for (k = 0; k < len_dir && token[k] != '\0'; k++)
                dir_path[i][k] = token[k];
            dir_path[i][k] = '/';
            k++;
            for (j = 0; j < len_comm && commands[0][j] != '\0';k++, j++)
                dir_path[i][k] = commands[0][j];
            dir_path[i][k] = '\0';
        }
        token = strtok(NULL, ":");
		i++;
	}
    dir_path[i] = NULL;
    return (dir_path);

}