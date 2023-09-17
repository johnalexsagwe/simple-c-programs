#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE_B 1024
#define INITIAL_TOKEN_CAPACITY 64
#define TOKEN_DELIMITERS " \n"
/* Deallocates memory used for storing tokens. */
void free_tokens(char **token_array);

/* Continuously runs the shell until Ctrl+D is pressed. */
void run_shell_loop(int arg_count, char **arg_values);

/* Executes a basic Unix command-line interpreter. */
int main(int arg_count, char **arg_values);

/* Reads user input using getline and handles EOF condition. */
char *custom_read_command(void);

/* Uses execve and fork to create processes to execute commands. */
int execute_arguments(char **tokenized_input);

/* Tokenizes a string using a specified delimiter. */
char *custom_strtok(char *str, const char *delim);

/* Calculate the length of a string. */
size_t custom_strlen(const char *strng);

/* Concatenate two strings. */
char *custom_strcat(char *target, const char *append);

/* Compare two strings. */
int custom_strcmp(const char *str1, const char *str2);

/* Search for the first occurrence of a character in a string. */
char *custom_strchr(const char *strng, char c);

/* Copy memory area. */
char *custom_memcpy(char *destination_pointer, const char *source_pointer, unsigned int n);

/* Copy a string from source to destination. */
char *custom_strcpy(char *destination_pointer, const char *source_pointer);

/* Retrieve the value of an environment variable. */
char *custom_getenv(const char *var_name);

/* Duplicates a string including allocating memory dynamically. */
char *custom_strdup(const char *strng);

/* Concatenates a specified number of characters from source to destination. */
char *custom_strncat(char *target, char *append, int n);

/* Gets the length of a prefix substring. */
size_t custom_strspn(char *strng, char *valid_characters);

/* Compares two strings according to a specified number of bytes or characters. */
int custom_strcmp(const char *str1, const char *str2);

/* Copies a string with a specified maximum number of bytes. */
char *custom_strncpy(char *destination_pointer, char *source_pointer, int n);

/* Converts a character string to an integer. */
int custom_atoi(char *s);

/* Check if the command exists in the PATH directories. */
char *checkCommand(const char *command);

/* Print a custom error message to stderr. */
void print_custom_error(const char *program_name, int command_count, const char *command,
const char *error_description);
/* Write a string to a specified file descriptor. */
void write_string(int descriptor, const char *result_string);
/* Convert an integer to a string representation. */
void transform_string(int number, char *str);

/* Deallocates memory used for storing tokens. */
void free_tokens(char **token_array);

/* Continuously runs the shell until Ctrl+D is pressed. */
void run_shell_loop(int arg_count, char **arg_values);

/* Executes a basic Unix command-line interpreter. */
int main(int arg_count, char **arg_values);

/* Reads user input using getline and handles EOF condition. */
char *custom_read_command(void);

/* Executes commands using execve and fork. */
int execute_arguments(char **tokenized_input);

/* Tokenizes a string using a specified delimiter. */
char *custom_strtok(char *str, const char *delim);

/* Duplicates a string including allocating memory dynamically. */
char *custom_strdup(const char *strng);

/* Concatenates a specified number of characters from source to destination. */
char *custom_strncat(char *target, char *append, int n);

/* Gets the length of a prefix substring. */
size_t custom_strspn(char *strng, char *valid_characters);

/* Compares two strings according to a specified number of bytes or characters. */
int custom_strncmp(const char *str1, const char *str2, int n);

/* Copies a string. */
char *custom_strncpy(char *destination_pointer, char *source_pointer, int n);

/* Converts a character string to an integer. */
int custom_atoi(char *str);

/* Check if the command exists in the PATH directories. */
char *checkCommand(const char *command);

/* function that takes input line (a string) and returns a pointer to a character */
char **parse_input(char *input_line);

/* Exit the shell with the specified exit status. */
void my_shell_exit(int exit_status);

/* Matches and executes built-in shell commands. */
void builtin_matcher(char **tokenized_input);

/* Reallocates memory */
void *my_realloc(void *new_block, unsigned int old_size, size_t new_size);

/* Environment */
extern char **environ;

int exit_status;
#endif /* SHELL_H */
