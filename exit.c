/* exit.c */
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "header.h"

void handle_exit() {
    int status;
    pid_t pid;

    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        /* Handle completed child processes to prevent zombie processes */
    }
}

void handle_eof() {
    printf("\n");
    exit(0);
}
