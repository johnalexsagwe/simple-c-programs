#include "shell.h"
#include <sys/types.h>

/**
* execute_arguments -  creates a child processes to run commands
* @tokenized_input: points to tokenized command.
* Return: 0 equals sucess or error for failure.
*/
int execute_arguments(char **tokenized_input)
{
int condition, command_count;
char *command;
const char *errorcommand, *program_name, *errormessage;
pid_t child_pid;

if (tokenized_input[0] == NULL)
return (1);

builtin_matcher(tokenized_input);
command = checkCommand(tokenized_input[0]);
program_name = "./hsh";
command_count = 1;
errormessage = "command not found";
errorcommand = tokenized_input[0];

if (command == NULL)
{
free(command);
exit_status = 127;
print_custom_error(program_name, command_count, errorcommand, errormessage);
return (-1);
}

child_pid = fork();
if (child_pid == -1)
{
perror("Error: Failed to create child process\n");
return (1);
}

if (!child_pid)
{
if (execve(command, tokenized_input, environ) == -1)
{
perror(command);
exit(1);
}
}
else
{
waitpid(child_pid, &condition, 0);
if (WIFEXITED(condition))
exit_status = WEXITSTATUS(condition);
}

free(command);
return (1);
}
