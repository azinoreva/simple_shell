#include <string.h>
#include <stdio.h>
#include "header.h"

char *get_next_token(char *command) {
    return strtok(command, " ");
}
void display_prompt() {
    printf("$ ");
}
