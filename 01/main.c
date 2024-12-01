#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bufferSize 256

// Comparison function
int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int main(int argc, char const *argv[])
{
    
    char buffer[bufferSize];

    int *list1 = NULL;
    int *list2 = NULL;
    int capacity = 0;

    int i = 0;

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
        if (i == capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            list1 = realloc(list1, capacity * sizeof(int));
            list2 = realloc(list2, capacity * sizeof(int));
        }
        
        list1[i] = num1;
        list2[i] = num2;

        i++;
    }

    qsort(list1, i + 1, sizeof(int), compare);
    qsort(list2, i + 1, sizeof(int), compare);

    for (int j = 0; j < i; j++)
    {
        int num1 = list1[j];
        int num2 = list2[j];

        int diff = max(num1, num2) -  min(num1, num2);
        total += diff;
    }
    printf("Total difference:\n%llu", total);
    free(list2);
    free(list1);
    return 0;
}
