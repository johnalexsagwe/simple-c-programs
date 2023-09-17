#include "shell.h"

/**
* custom_strdup - Duplicates a string including allocating memory dynamically
* @strng: The string to be duplicated
*
* Return: A pointer to the duplicated string
*/
char *custom_strdup(const char *strng)
{
int accept_index = 0;
char *duplicate_string;
int string_length = 0;

if (strng == NULL)
{
return (NULL);
}

while (strng[string_length] != '\0')
{
string_length++;
}

duplicate_string = malloc((string_length + 1) * sizeof(char));
if (duplicate_string == NULL)
{
/* If memory allocation fails */
return (NULL);
}

for (accept_index = 0; accept_index < string_length; accept_index++)
{
duplicate_string[accept_index] = strng[accept_index];
}
duplicate_string[accept_index] = '\0';
return (duplicate_string);
}

/**
* custom_strncat - Concatenates a specified number of characters from source to destination
* @append: A pointer to the source string
* @target: A pointer to the destination string
* @n: The maximum number of characters to be concatenated
*
* Return: A pointer to the destination string
*/
char *custom_strncat(char *target, char *append, int n)
{
int target_len = custom_strlen(target);
int accept_index;

for (accept_index = 0; accept_index < n && append[accept_index] != '\0'; accept_index++)
{
target[target_len + accept_index] = append[accept_index];
}
target[target_len + accept_index] = '\0';

return (target);
}

/**
* custom_strspn - Gets the length of a prefix substring
* @strng: The string to be checked
* @valid_characters: The substring to be checked
*
* Return: The number of bytes within strng that only belong to valid_characters
*/
size_t custom_strspn(char *strng, char *valid_characters)
{
size_t n, accept_index;

for (n = 0; strng[n] != '\0'; n++)
{
for (accept_index = 0; valid_characters[accept_index] != '\0'; accept_index++)
{
if (strng[n] == valid_characters[accept_index])
{
break;
}
}
if (valid_characters[accept_index] == '\0')
{
break;
}
}
return (n);
}

/**
* custom_atoi - Entry point
* Description - 'A function that converts a character string to an integer.'
* @s: the string to be converted
* Return: Converted integer value.
*/
int custom_atoi(char *s)
{
int res_value = 0;
int sn = 1;
int h = 0;

while (s[h] == ' ' || s[h] == '\t' || s[h] == '\n')
{
h++;
}

if (s[h] == '+' || s[h] == '-')
{
sn = (s[h++] == '-') ? -1 : 1;
}

while (s[h] >= '0' && s[h] <= '9')
{
res_value = res_value * 10 + (s[h] - '0');
h++;
}

return (res_value * sn);
}

/**
* custom_strncmp - Entry point
* Description - Compares two strings according to a specified
* number of bytes or characters.'
* @str1: pointer to a string
* @str2: pointer to another string
* @n: specified or maximum number of bytes used for comparing
*
* Return: If value less than 0, then str1 is shorter or less than str2.
* If the value is 0, then str1 and str2 are the same or have a match.
* If the value is greater than 0, then str2 is longer than str1.
*/
int custom_strncmp(const char *str1, const char *str2, int n)
{
int w = 0;

while (str1[w] && str2[w] && w < n)
{
if (str1[w] != str2[w])
{
return (str1[w] - str2[w]);
}
w++;
}

if (w == n)
{
return (0);
}

if (str1[w] && !str2[w])
{
return (1);
}
else if (!str1[w] && str2[w])
{
return (-1);
}

return (0);
}

/**
* custom_strncpy - Entry point
* Description - 'A function that copies a string.'
* @destination_pointer: destination char string type
* @source_pointer: initial char string type
* @string_length: maximum number of bytes to be used
* Return: Pointer to destination_pointer.
*/
char *custom_strncpy(char *destination_pointer, char *source_pointer, int string_length)
{
int copy_index;

for (copy_index = 0; copy_index < string_length && source_pointer[copy_index] != '\0'; copy_index++)
{
destination_pointer[copy_index] = source_pointer[copy_index];
}
for (; copy_index < string_length; copy_index++)
{
destination_pointer[copy_index] = '\0';
}
return (destination_pointer);
}

/**
* atoi_alt - Entry point
* Description - 'A function that converts a character string to an integer.'
* @strng: the string to be converted
* Return: Converted integer value
*/
int atoi_alt(char *strng)
{
int result_value = 0;
int sn = 1;
int character_index = 0;

while (strng[character_index] == ' ' || strng[character_index] == '\t' || strng[character_index] == '\n')
{
character_index++;
}

if (strng[character_index] == '+' || strng[character_index] == '-')
{
sn = (strng[character_index++] == '-') ? -1 : 1;
}

while (strng[character_index] >= '0' && strng[character_index] <= '9')
{
result_value = result_value * 10 + (strng[character_index] - '0');
character_index++;
}

return (result_value * sn);
}
