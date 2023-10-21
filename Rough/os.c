#include <stdio.h>
#include <stdlib.h>

// Function to simulate LRU page replacement
void simulateLRU(int pageTableSize, int* pageRequests, int numPageRequests) {
    int* pageTable = (int*)malloc(pageTableSize * sizeof(int));
    int* pageTimestamps = (int*)malloc(pageTableSize * sizeof(int));
    int pageFaults = 0;
    int currentTime = 0;

    for (int i = 0; i < pageTableSize; i++) {
        pageTable[i] = -1;  // Initialize page table with -1 to indicate empty slots
        pageTimestamps[i] = 0;
    }

    for (int i = 0; i < numPageRequests; i++) {
        int page_number = pageRequests[i];
        int page_index = -1;

        // Check if the page is already in the page table
        for (int j = 0; j < pageTableSize; j++) {
            if (pageTable[j] == page_number) {
                page_index = j;
                break;
            }
        }

        if (page_index != -1) {
            // Page is already in the table, update its timestamp to indicate recent use
            pageTimestamps[page_index] = currentTime;
        } else {
            // Page is not in the table, we have a page fault
            pageFaults++;

            // Find the least recently used page for replacement
            int minTimestamp = pageTimestamps[0];
            page_index = 0;
            for (int j = 1; j < pageTableSize; j++) {
                if (pageTimestamps[j] < minTimestamp) {
                    minTimestamp = pageTimestamps[j];
                    page_index = j;
                }
            }

            // Replace the least recently used page with the new page
            pageTable[page_index] = page_number;
            pageTimestamps[page_index] = currentTime;
        }

        currentTime++;
    }

    free(pageTable);
    free(pageTimestamps);

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pageTableSize, numPageRequests;

    printf("Enter the size of the page table: ");
    scanf("%d", &pageTableSize);

    printf("Enter the number of page requests: ");
    scanf("%d", &numPageRequests);

    int* pageRequests = (int*)malloc(numPageRequests * sizeof(int));

    printf("Enter the sequence of page requests: ");
    for (int i = 0; i < numPageRequests; i++) {
        scanf("%d", &pageRequests[i]);
    }

    simulateLRU(pageTableSize, pageRequests, numPageRequests);

    free(pageRequests);

    return 0;
}
