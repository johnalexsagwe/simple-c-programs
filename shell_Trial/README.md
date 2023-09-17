SHELL.C
 It continuously prompts the user for input by displaying the "#cisfun$" prompt. It reads the user's input, checks for empty or whitespace-only input, and if the input is not empty, it forks a new process to execute the entered command. The child process uses execlp to attempt to execute the command, and if the command is not found, it prints an error message. The parent process waits for the child process to complete and checks if it exited with an error status, displaying an appropriate error message if necessary. The program then frees the memory used for input and repeats the process, allowing the user to enter and execute more commands. This simple shell provides basic command execution functionality while handling empty input gracefully to prevent crashes.

MAIN.C

