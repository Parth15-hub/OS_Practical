#include <stdio.h>

int main() {
    int n, f, i, j;
    int pages[50], frames[10];
    int faults = 0, hits = 0, front = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    // Initialize frames
    for(i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");

    for(i = 0; i < n; i++) {
        int found = 0;

        // Check hit
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If page fault
        if(!found) {
            frames[front] = pages[i];
            front = (front + 1) % f;
            faults++;
            printf("%d\t", pages[i]);
        }
        else {
            hits++;
            printf("%d\t", pages[i]);
        }

        // Print frames (common for both cases)
        for(j = 0; j < f; j++) {
            if(frames[j] == -1) printf("- ");
            else printf("%d ", frames[j]);
        }

        // Status
        if(found)
            printf("\tHit\n");
        else
            printf("\tFault\n");
    }

    printf("\nTotal Hits = %d", hits);
    printf("\nTotal Faults = %d", faults);

    return 0;
}
