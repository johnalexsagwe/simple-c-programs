#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
/**
* custom_read_command - Reads user input using getline and handles EOF condition.
* Return: The input string from the user.
*/
char *custom_read_command(void)
{
char *input_line = NULL;
size_t buffer_size = 0;
ssize_t read_size;

if (isatty(STDIN_FILENO) == 1)
{
write(STDOUT_FILENO, "$ ", 2);
}

read_size = getline(&input_line, &buffer_size, stdin);

if (read_size == -1)
{
free(input_line);
return (NULL);
}

if (input_line[0] == '\n' || (custom_strspn(input_line, " \t\r\n") == custom_strlen(input_line)))
{
free(input_line);
return (custom_read_command());
}

if (input_line[custom_strlen(input_line) - 1] != '\n')
{
buffer_size += 2;
input_line = (char *)realloc(input_line, buffer_size);
if (input_line == NULL)
{
free(input_line);
perror("Memory allocation failed");
return (NULL);
}
input_line[custom_strlen(input_line) - 1] = '\0';
}

return (input_line);
}
