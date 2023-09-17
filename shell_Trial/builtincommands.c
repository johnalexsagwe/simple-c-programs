#include "shell.h"

/**
* my_shell_exit - Function to handle the exit command.
*
* This function is responsible for gracefully exiting the shell.
*
* @exit_status: An integer representing the exit status.
* Return: Void.
*/
void my_shell_exit(int exit_status)
{
exit(exit_status);
}

/**
* builtin_matcher - Function to match and execute builtin commands.
*
* This function checks if the given command is a builtin command and
* executes it if it is.
*
* @tokenized_input: A pointer to the tokenized user input for execution.
*/
void builtin_matcher(char **tokenized_input)
{
if (custom_strcmp(tokenized_input[0], "exit") == 0)
{
int exit_status = 0;

if (tokenized_input[1] != NULL)
{
exit_status = custom_atoi(tokenized_input[1]);
}

my_shell_exit(exit_status);
}
else if (custom_strcmp(tokenized_input[0], "env") == 0)
{
return;
}
}

