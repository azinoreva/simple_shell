#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - Entry point.
 * return - 0 on success
 */

extern char **environ;  /* Declaration for environ */

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 64
#define DELIMITER " \t\r\n\a"

void display_prompt() {
    printf("$ ");
}

char *read_command() {
    char *input = NULL;
    size_t bufsize = 0;
    getline(&input, &bufsize, stdin);
    return input;
}

void execute_command(char *command) {
    /* Tokenize the command */
    char *token;
    char *args[MAX_ARG_SIZE];
    int arg_count = 0;
     pid_t pid = fork();

    token = strtok(command, DELIMITER);
    while (token != NULL && arg_count < MAX_ARG_SIZE - 1) {
        args[arg_count++] = token;
        token = strtok(NULL, DELIMITER);
    }
    args[arg_count] = NULL;

    /* Check for built-in commands */
    if (arg_count > 0) {
        if (strcasecmp(args[0], "exit") == 0) {
            exit_shell();
            return;
        } else if (strcasecmp(args[0], "env") == 0) {
            char **env = environ;
            while (*env != NULL) {
                printf("%s\n", *env);
                env++;
            }
            return;
        }
    }

   
    if (pid == 0) {
        /* Child process */
        if (execvp(args[0], args) == -1) {
            perror("Error");
            exit(EXIT_FAILURE);
        }
    } else if (pid > 0) {
        /* Parent process */
        waitpid(pid, NULL, 0);
    } else {
        perror("Fork failed");
    }
}

void exit_shell() {
    printf("Exiting shell.\n");
    exit(0);
}

int main() {
    char *command;
    pid_t pid;

    while (1) {
        display_prompt();
        command = read_command();

        /* Check for end of file (Ctrl+D) */
        if (feof(stdin)) {
            printf("\n");
            break;
        }

        /* Fork and execute the command */
        pid = fork();

        if (pid == 0) {
            /* Child process */
            execute_command(command);
            free(command);
            exit(EXIT_SUCCESS);
        } else if (pid > 0) {
            /* Parent process */
            waitpid(pid, NULL, 0);
        } else {
            perror("Fork failed");
        }
    }

    return 0;
}
