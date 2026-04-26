#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, size, total = 0, temp;
    int req[50];

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence: ");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    int start = head;   // store original head

    // Sort requests
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    printf("\nMovement of head:\n");

    // Step 1: Move towards higher tracks
    for(i = 0; i < n; i++) {
        if(req[i] >= start) {
            printf("%d -> %d\n", head, req[i]);
            total += abs(head - req[i]);
            head = req[i];
        }
    }

    // Step 2: Go to end of disk
    printf("%d -> %d\n", head, size-1);
    total += abs(head - (size-1));
    head = size - 1;

    // Step 3: Jump to start (0)
    printf("%d -> %d\n", head, 0);
    total += (size - 1);
    head = 0;

    // Step 4: Process remaining requests (< original head)
    for(i = 0; i < n; i++) {
        if(req[i] < start) {
            printf("%d -> %d\n", head, req[i]);
            total += abs(head - req[i]);
            head = req[i];
        }
    }

    printf("\nTotal Seek Time = %d\n", total);

    return 0;
}
