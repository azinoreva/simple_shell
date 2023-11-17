#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"
#include "string.h"

int main() {
    char *command;
    size_t len = 0;
    char *token;

    while (1) {
        display_prompt();

        if (getline(&command, &len, stdin) == -1) {
            /* Handle Ctrl+D (end of file) */
            handle_eof();
        }

        /* Remove newline character */
        command[strcspn(command, "\n")] = '\0';

        token = get_next_token(command);

        if (token == NULL) {
            /* No command entered, display prompt again */
            continue;
        }

        if (execute_command(token) == -1) {
            handle_errors("Error executing command");
        }

        free(command);
    }

    return 0;
}
