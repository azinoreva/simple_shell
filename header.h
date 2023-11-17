#ifndef HEADER_H
#define HEADER_H

void display_prompt();
char *get_next_token(char *command);
int execute_command(char *command);
void handle_exit();
void handle_eof();
void handle_errors(char *msg);

#endif
