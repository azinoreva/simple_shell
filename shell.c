#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "header.h"

int main() {
    char *command;
    size_t len = 0;

    while (1) {
        char **args;
        printf("$");

        if (getline(&command, &len, stdin) == -1) {
            handle_exit();
        }

        /* Remove newline character */
        command[strcspn(command, "\n")] = '\0';

        args = parse_command(command);
        if (args == NULL) {
            /* No command entered, display prompt again */
            free(command);
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            handle_exit();
        } else if (strcmp(args[0], "env") == 0) {
            handle_env();
        } else {
            if (execute_command(args) == -1) {
                printf("%s: command not found\n", args[0]);
            }
        }

        free(command);
        free(args);
    }

    return 0;
}
