/* env.c */
#include <stdio.h>
#include <stdlib.h>

extern char **environ;

void handle_env() {
    int i;
    for (i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
}
