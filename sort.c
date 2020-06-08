#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char InputString[65536];
typedef char InputLine[10];
typedef char * LinePtr;

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

    LinePtr linePtr = strtok(input, "\n");
    LinePtr originalLinePtr = linePtr;
    int counter = 0;
    while (linePtr != NULL)
    {
        fprintf(stdout, "%s\n", linePtr);
        linePtr = strtok(NULL, "\n");
        counter++;
    }

    InputLine * lines = (InputLine*)calloc(counter, sizeof(InputLine));
    for(int i = 0; i < counter; i++)
    {
        strcpy(lines[i], originalLinePtr);
        originalLinePtr++;
    }

    fprintf(stdout, "Count: %d\n", counter);

    qsort(lines, counter, 10, strcmp);

    fprintf(stdout, "Sorted!\n");

    for(int i = 0; i < counter; i++)
    {
        fprintf(stdout, "%s\n", lines[i]);
    }
}