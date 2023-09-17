#include "shell.h"
#include <stddef.h>
#include <unistd.h>

/**
* custom_strlen - Calculate the length of a string
* @strng: The string to measure
*
* Return: The length of the string.
*/
size_t custom_strlen(const char *strng)
{
size_t len = 0;

while (strng[len] != '\0')
{
len++;
}
return (len);
}

/**
* custom_strcat - Concatenate two strings
* @target: Destination string
* @append: Source string
*
* Return: Pointer to the concatenated string.
*/
char *custom_strcat(char *target, const char *append)
{
int target_len = 0;
int h;

/* Find the length of the target string */
while (target[target_len] != '\0')
{
target_len++;
}

/* Append the source string to the target string */
for (h = 0; append[h] != '\0'; h++)
{
target[target_len + h] = append[h];
}

/* Add a null-terminating character to the concatenated string */
target[target_len + h] = '\0';

return (target);
}

/**
* custom_strcmp - Compare two strings
* @str1: First string
* @str2: Second string
*
* Return: 0 if strings are equal, positive if str1 > str2, negative if str1 < str2.
*/
int custom_strcmp(const char *str1, const char *str2)
{
int len;

for (len = 0; str1[len] == str2[len] && str1[len]; len++)
;

if (str1[len] > str2[len])
return (1);
if (str1[len] < str2[len])
return (-1);
return (0);
}

/**
* _strlen - Calculate the length of a string.
* @strng: The string to be measured.
*
* Return: The length of the string.
*/
size_t _strlen(const char *strng)
{
size_t len = 0;

while (strng[len] != '\0')
{
len++;
}
return (len);
}

/**
* custom_strchr - Search for the first occurrence of a character in a string.
* @strng: A pointer to the string to be searched.
* @charsearched: The character to be looked up.
*
* Return: A pointer to the first occurrence of the character c in strng,
* or NULL if char c is not found in strng.
*/
char *custom_strchr(const char *strng, char charsearched)
{
while (*strng != '\0')
{
if (*strng == charsearched)
return ((char *)strng);
strng++;
}
return (NULL);
}

/**
* _memcpy - Copy memory area.
* @destination_pointer: Destination buffer.
* @target: Source buffer.
* @n: Number of bytes to copy.
*
* Return: A pointer to the destination buffer.
*/
char *_memcpy(char *target, const char *source_pointer, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
{
target[i] = source_pointer[i];
}
return (target);
}

/**
* _strcpy - Copy a string from source to destination.
* @destination_pointer: Destination string.
* @source_pointer: Source string.
*
* Return: Pointer to the destination string.
*/
char *custom_strcpy(char *destination_pointer, const char *source_pointer)
{
int i = 0;

while (source_pointer[i] != '\0')
{
destination_pointer[i] = source_pointer[i];
i++;
}
destination_pointer[i] = '\0';
return (destination_pointer);
}

/**
* custom_getenv - Retrieve the value of an environment variable.
* @var_name: The name of the variable to retrieve.
*
* Return: The value of the environment variable, or NULL if not found.
*/
char *custom_getenv(const char *var_name)
{
int var_name_len = _strlen(var_name);
char **env;

for (env = environ; *env; ++env)
{
if (custom_strncmp(var_name, *env, var_name_len) == 0 && (*env)[var_name_len] == '=')
{
return (&((*env)[var_name_len + 1]));
}
}
return (NULL);
}
