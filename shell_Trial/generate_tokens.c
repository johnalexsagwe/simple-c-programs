#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * parse_input - Tokenizes a user input string.
 * @input_line: The input string from the user.
 * Return: An array of tokens.
 */
char **parse_input(char *input_line)
{
    size_t buf_s = INITIAL_TOKEN_CAPACITY;
    char **tokens = malloc(buf_s * sizeof(char *));
    char *token;
    size_t token_count = 0;

    if (input_line == NULL || tokens == NULL)
    {
        perror("Memory allocation error");
        free(tokens);
        exit(EXIT_FAILURE);
    }

    token = custom_strtok(input_line, TOKEN_DELIMITERS);

    while (token != NULL)
    {
        tokens[token_count] = custom_strdup(token);
        if (tokens[token_count] == NULL)
        {
            perror("Memory allocation error");
            free(tokens);
            exit(EXIT_FAILURE);
        }

        token_count++;

        if (token_count >= buf_s)
        {
            buf_s += INITIAL_TOKEN_CAPACITY;

            tokens = my_realloc(tokens, buf_s * sizeof(char *), buf_s * sizeof(char *));
            if (tokens == NULL)
            {
                perror("Memory allocation error");
                free(tokens);
                exit(EXIT_FAILURE);
            }
        }

        token = custom_strtok(NULL, TOKEN_DELIMITERS);
    }

    tokens[token_count] = NULL;
    return (tokens);
}

/**
 * my_realloc - Resizes a memory block.
 * @new_block: Pointer to the new  memory block.
 * @old_size: Old size of the memory block
 * @new_size: New size of the memory block.
 * Return: Pointer to the resized memory block.
 */
void *my_realloc(void *new_block, unsigned int old_size, size_t new_size)
{
    char *relloc_block, *current_block;
    unsigned int i;

    if (new_block != NULL)
        current_block = new_block;
    else
    { return (malloc(new_size)); }
    if (new_size == old_size)
	    return (new_block);
    if (new_size == 0 && new_block != NULL)
    {
        free(new_block);
        return (0);
    }

    relloc_block = malloc(new_size);

    if (relloc_block == NULL)
        return (NULL);

    for (i = 0; i < old_size && i < new_size; i++)
    {
        *(relloc_block + i) = current_block[i];
    }

    free(new_block);
    return (relloc_block);
}
