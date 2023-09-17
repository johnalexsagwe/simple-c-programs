#include "shell.h"

/**
* custom_strtok - Tokenizes a string using a specified delimiter
* @str: The input string to tokenize
* @delim: The delimiter used to split the string
*
* Return: A pointer to the next token in the input string, or NULL if no
*         more tokens are found.
*/
char *custom_strtok(char *str, const char *delim)
{
char *token;
static char *remainder;

if (str != NULL)
{
remainder = str;
}

if (remainder == NULL || *remainder == '\0')
{
return (NULL);
}

while (*remainder != '\0' && custom_strchr(delim, *remainder) != NULL)
{
remainder++;
}

if (*remainder == '\0')
{
return (NULL);
}

token = remainder;
while (*remainder != '\0' && strchr(delim, *remainder) == NULL)
{
remainder++;
}
if (*remainder != '\0')
{
*remainder = '\0';
remainder++;
}
return (token);
}
