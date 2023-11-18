/* header.h */
#ifndef HEADER_H
#define HEADER_H

void display_prompt();
char **parse_command(char *command);
int execute_command(char **args);
void handle_exit();
void handle_env();

#endif
