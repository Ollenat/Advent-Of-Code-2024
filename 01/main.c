#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bufferSize 256

int main(int argc, char const *argv[])
{
    
    char buffer[bufferSize];
    unsigned long long int total = 0;

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        //Buffer is now a line from the input
        char *next_token = NULL;
        char *first = strtok_s(buffer, " ", &next_token);
        char *second = strtok_s(NULL, " ", &next_token);

        //we have the first and the second numbers now, as strings.
        //Parse them

        int num1 = atoi(first);
        int num2 = atoi(second);

        int diff = max(num1, num2) -  min(num1, num2);
        total += diff;

        fprintf(stdout, "%i\n", diff);
    }
    
    printf("Total difference:\n%llu", total);
    return 0;
}
