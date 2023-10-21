#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void *calculate_length(void *arg);

int main() {
    pthread_t thread;
    char input_string[100]; // Adjust the size as needed
    int length;

    printf("Enter a string: ");
    scanf("%s", input_string);

    // Create a thread to calculate the length of the string
    if (pthread_create(&thread, NULL, calculate_length, (void *)input_string) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Wait for the thread to finish and get its exit status
    void *threadResult;
    pthread_join(thread, &threadResult);

    // Convert the result to an integer
    length = *(int *)threadResult;

    // Free the allocated memory
    free(threadResult);

    // Print the length of the string
    printf("Length of the string: %d\n", length);

    return 0;
}

void *calculate_length(void *arg) {
    char *str = (char *)arg;
    int *length = (int *)malloc(sizeof(int));
    *length = strlen(str);

    // Return the address of the length variable
    return (void *)length;
}
