#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef char InputString[65536];
typedef char InputLine[10];
typedef char * LinePtr;

int cmpstr(void const *a, void const *b);

int main()
{
    if (isatty(fileno(stdin)))
    {
        return 0;
    }

    size_t i = 0;
    InputString input;
    while (-1 != (input[i++] = getchar()))
        ;
    input[i - 1] = '\0';

    size_t bufferSize = 10;
    InputLine * lines = (InputLine*)calloc(bufferSize, sizeof(InputLine));
    LinePtr linePtr = strtok(input, "\n\r");

    int index = 0;
    while (linePtr != NULL)
    {
        strcpy(lines[index], linePtr);
        linePtr = strtok(NULL, "\n\r");
        index++;
        if (index >= bufferSize)
        {
            bufferSize += 10;
            lines = (InputLine*)realloc(lines, bufferSize);
        }
    }

    qsort(lines, index, 10, cmpstr);

    for(int i = 0; i < index; i++)
    {
        fprintf(stdout, "%s\n", lines[i]);
    }

    free(lines);
}

int cmpstr(void const *a, void const *b) { 
    char const *aa = (char const *)a;
    char const *bb = (char const *)b;

    return strcmp(aa, bb);
}