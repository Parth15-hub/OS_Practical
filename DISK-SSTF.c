#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    int req[50], head;
    int visited[50] = {0};
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
        int min = 9999, index = -1;

        // Find nearest request
        for(j = 0; j < n; j++) {
            if(!visited[j]) {
                int dist = abs(head - req[j]);
                if(dist < min) {
                    min = dist;
                    index = j;
                }
            }
        }

        // Move head
        printf("%d -> %d\n", head, req[index]);

        total_seek += abs(head - req[index]);
        head = req[index];
        visited[index] = 1;
    }

    printf("\nTotal Seek Time = %d\n", total_seek);

    return 0;
}
