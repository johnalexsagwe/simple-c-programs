#include "shell.h"

/**
* checkCommand - Check if the command exists in the PATH directories
* @command: command being checked
* Return: path of the executable if it exists
*/
char *checkCommand(const char *command)
{
char *path_Variable = custom_getenv("PATH");
size_t command_length, pathSize;
char *path_Copy, *token;
char absolute_Path[1024] = "";

if (command[0] == '/' || command[0] == '.' || command[0] == '~')
{
if (access(command, F_OK) == 0)
return (custom_strdup(command));
}
else
{
if (path_Variable == NULL)
return (NULL);
command_length = custom_strlen(command);
path_Copy = custom_strdup(path_Variable);
token = custom_strtok(path_Copy, ":");

while (token != NULL)
{
pathSize = custom_strlen(token);

if (pathSize + 1 + command_length >= sizeof(absolute_Path))
{
free(path_Copy);
return (NULL);
}
custom_strcpy(absolute_Path, token);
custom_strcat(absolute_Path, "/");
custom_strcat(absolute_Path, command);
if (access(absolute_Path, F_OK) == 0)
{
free(path_Copy);
return (custom_strdup(absolute_Path));
}
token = custom_strtok(NULL, ":");
}
free(path_Copy);
}
return (NULL);
}
