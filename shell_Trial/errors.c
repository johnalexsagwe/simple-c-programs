#include "shell.h"

/**
* print_custom_error - Print a custom error message to stderr.
* @program_name: Shell program's name.
* @command_count: Command count for identification.
* @command: Specific command causing the error.
* @error_description: Error message to be printed.
*/
void print_custom_error(const char *program_name, int command_count, const char *command,
const char *error_description)
{
	char cmd_count_str[20];
	char new_line = '\n';

/* Print shell name and a separator */
	write_string(STDERR_FILENO, program_name);
	write_string(STDERR_FILENO, ": ");

/* Transform and print the command count */
	transform_string(command_count, cmd_count_str);

/* Print command number and a separator */
	write_string(STDERR_FILENO, cmd_count_str);
	write_string(STDERR_FILENO, ": ");

/* Print the specific command causing the error */
	write_string(STDERR_FILENO, command);
	write_string(STDERR_FILENO, ": ");

/* Print the custom error message */
	write_string(STDERR_FILENO, error_description);

/* Print a new line to stderr */
	write(STDERR_FILENO, &new_line, 1);
}

/**
 * write_string - Write a string to a specified file descriptor.
 * @descriptor: The file descriptor to write to.
 * @error_description: A description of the error (can be NULL).
 * @result_string: The result string to write (can be NULL).
 */
void write_string(int descriptor, const char *result_string)
{
    write(descriptor, result_string, strlen(result_string));
}

/**
* transform_string - Convert an integer to a string representation.
* @number: The number to be converted.
* @str: The string to store the converted number.
* Return: The transformed strng
*/
void transform_string(int number, char *str)
{
	int index = 0;
	int num_length = 0;
	int temp_num = number;

/* Calculate the number of digits in the integer */
	while (temp_num > 0)
	{
		temp_num /= 10;
		num_length++;
	}
/* Convert the integer to a string in reverse order */
	for (index = num_length - 1; index >= 0; index--)
	{
		str[index] = '0' + (number % 10);
		number /= 10;
	}
	str[num_length] = '\0';
}
