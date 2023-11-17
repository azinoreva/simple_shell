/* errors.c */
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void handle_errors(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}
