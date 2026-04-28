#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, total = 0, temp;
    int req[50];

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence: ");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Sort
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

    for(i = 0; i < n; i++) {
        if(req[i] >= head) {
            printf("%d -> %d\n", head, req[i]);
            total += abs(head - req[i]);
            head = req[i];
        }
    }

    if(pos > 0) {
        printf("%d -> %d\n", head, req[0]);
        total += abs(head - req[0]);
        head = req[0];
    }

    for(i = 0; i < n; i++) {
        if(req[i] < head) {
            printf("%d -> %d\n", head, req[i]);
            total += abs(head - req[i]);
            head = req[i];
        }
    }

    printf("\nTotal Seek Time = %d\n", total);

    return 0;
}
