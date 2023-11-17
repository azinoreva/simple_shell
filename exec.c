#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "header.h"

int execute_command(char *command) {
    pid_t pid = fork();

    if (pid == -1) {
        handle_errors("fork");
        return -1;
    } else if (pid == 0) {

        char **args = malloc(sizeof(char *) * 2);
        if (args == NULL) {
            handle_errors("malloc");
            exit(EXIT_FAILURE);
        }

        args[0] = command;
        args[1] = NULL;

        if (execve(command, args, NULL) == -1) {
            handle_errors("execve");
            free(args);
            exit(EXIT_FAILURE);
        }

        free(args);
    } else {
        waitpid(pid, NULL, 0);
    }

    return 0;
}
