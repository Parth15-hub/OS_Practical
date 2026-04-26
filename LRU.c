#include <stdio.h>

int main() {
    int n, f, i, j, k;
    int pages[50], frames[10], time[10];
    int faults = 0, hits = 0, count = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");

    for(i = 0; i < n; i++) {
        int found = 0;

        // Check if page already present
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                hits++;
                count++;
                time[j] = count;   // update recent use
                break;
            }
        }

        // Page Fault
        if(!found) {
            int pos = 0;

            // Find empty frame
            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // If no empty frame, find least recently used
            if(j == f) {
                int min = time[0];
                pos = 0;
                for(k = 1; k < f; k++) {
                    if(time[k] < min) {
                        min = time[k];
                        pos = k;
                    }
                }
            }

            frames[pos] = pages[i];
            count++;
            time[pos] = count;
            faults++;
        }

        // Display
        printf("%d\t", pages[i]);
        for(j = 0; j < f; j++) {
            if(frames[j] == -1) printf("- ");
            else printf("%d ", frames[j]);
        }

        if(found)
            printf("\tHit\n");
        else
            printf("\tFault\n");
    }

    printf("\nTotal Hits = %d", hits);
    printf("\nTotal Faults = %d", faults);

    return 0;
}
