#include <stdio.h>
#include <stdlib.h>   // for abs()

int main() {
    int n, i;
    int req[50], head;
    int total_seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence: ");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nMovement of head:\n");

    for(i = 0; i < n; i++) {
        printf("%d -> %d\n", head, req[i]);

        total_seek += abs(head - req[i]);  // main formula
        head = req[i];
    }

    printf("\nTotal Seek Time = %d\n", total_seek);

    return 0;
}
