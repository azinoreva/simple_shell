#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char **parse_command(char *command) {
    char **args = malloc(sizeof(char *));
    if (args == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    {
        int count = 0;

        char *token = strtok(command, " ");
        while (token != NULL) {
            char **temp = malloc((count + 1) * sizeof(char *));
            if (temp == NULL) {
                perror("malloc");
                exit(EXIT_FAILURE);
            }

            memcpy(temp, args, count * sizeof(char *));
            temp[count] = strdup(token);
            if (temp[count] == NULL) {
                perror("strdup");
                exit(EXIT_FAILURE);
            }

            free(args);
            args = temp;
            count++;

            token = strtok(NULL, " ");
        }

        args = realloc(args, (count + 1) * sizeof(char *));
        if (args == NULL) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        args[count] = NULL;
    }

    return args;
}
