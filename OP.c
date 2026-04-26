#include <stdio.h>

int main() {
    int n, f, i, j, k;
    int pages[50], frames[10];
    int faults = 0, hits = 0;

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
                hits++;
                break;
            }
        }

        // If page fault
        if(!found) {
            int pos = -1, farthest = -1;

            // Check for empty frame
            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // If no empty frame → find optimal replacement
            if(pos == -1) {
                for(j = 0; j < f; j++) {
                    int next = -1;

                    for(k = i+1; k < n; k++) {
                        if(frames[j] == pages[k]) {
                            next = k;
                            break;
                        }
                    }

                    // If page not used again → best to replace
                    if(next == -1) {
                        pos = j;
                        break;
                    }

                    // Choose farthest use
                    if(next > farthest) {
                        farthest = next;
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
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
