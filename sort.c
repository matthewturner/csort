#include <stdio.h>
#include <string.h>

int main()
{
    if (!isatty(fileno(stdin)))
    {
        int i = 0;
        char pipe[65536];
        while (-1 != (pipe[i++] = getchar()))
            ;
        pipe[i - 3] = '\0';

        char *split = strtok(pipe, "\n");
        while (split != NULL)
        {
            fprintf(stdout, "%s\n", split);
            split = strtok(NULL, "\n");
        }
    }
}