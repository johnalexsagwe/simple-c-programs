#include "shell.h"
#include <unistd.h>
#include <stdlib.h>

/**
* free_tokens - Deallocates memory used for storing tokens.
* @token_array: A double pointer to an array of tokens.
*/
void free_tokens(char **token_array)
{
int token_index;

if (token_array == NULL)
{
return;
}

for (token_index = 0; token_array[token_index] != NULL; token_index++)
{
free(token_array[token_index]);
}
free(token_array);
}

/**
* run_shell_loop - Continuously runs the shell until Ctrl+D is pressed.
* @arg_count: The number of command-line arguments.
* @arg_values: An array of command-line argument strings.
* Return: void
*/
void run_shell_loop(int arg_count __attribute__((unused)), char **arg_values __attribute__((unused)))
{
int shell_condition = 1;
char *input_line = NULL;
char **tokenized_input;

const char *shell_prompt = "$ ";

do {
write(STDOUT_FILENO, shell_prompt, 2);

input_line = custom_read_command();
if (input_line == NULL)
{
free(input_line);
break;
}
tokenized_input = parse_input(input_line);

shell_condition = execute_arguments(tokenized_input);

free(input_line);
free_tokens(tokenized_input);

} while (shell_condition);
}

/**
* main - Executes a basic Unix command-line interpreter.
* @arg_count: The count of command-line arguments.
* @arg_values: An array of command-line argument strings.
* Return: The exit status of the last executed command.
*/
int main(int arg_count __attribute__((unused)), char **arg_values __attribute__((unused)))
{
	exit_status = 0;
	run_shell_loop(arg_count, arg_values);
	return (exit_status);
}
