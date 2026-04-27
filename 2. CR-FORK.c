#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void sort(int a[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void printArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int i, n;
    int a[20];

    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int pid = fork();

    if(pid == 0) {
        printf("\nChild Process (PID = %d)\n", getpid());
        sort(a, n);
        printf("Sorted Child Process: ");
        printArray(a, n);
        printf("Child exiting...\n");
    } 
    else {
        printf("\nParent Process (PID = %d)\n", getpid());
        wait(NULL);
        sort(a, n);
        printf("Sorted Parent Process: ");
        printArray(a, n);
    }

    return 0;
}
