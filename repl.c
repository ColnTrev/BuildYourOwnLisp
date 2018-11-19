#include <stdio.h>
#include <stdlib.h>
#include "mpc.h"

#ifdef _WIN32
#include <string.h>
#else
#include <editline/history.h>
#include <editline/readline.h>
#endif

#define BUFFER_SIZE 2048
void readLine(char *prompt, char *buffer, int buf_size);

int main(int argc, char **argv)
{
    char input_buf[BUFFER_SIZE];
    puts("Collin\'s Lisp v0.0.0");
    puts("press ctrl+c to exit");

    while(1)
    {
        readLine("lisp> ", input_buf, BUFFER_SIZE);
        printf("%s", input_buf);
    }

    return 0;
}

void readLine(char *prompt, char *buffer, int buf_size)
{
    fputs(prompt, stdout);
    fgets(buffer, buf_size, stdin);
}