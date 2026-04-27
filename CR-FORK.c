#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int p = fork();

    if(p < 0) {
        printf("Fork failed\n");
        return 1;
    }

    else if(p == 0) {
        // Child Process
        printf("Child Process:\n");
        printf("PID = %d, Parent PID = %d\n", getpid(), getppid());

        for(char ch = 'a'; ch <= 'z'; ch++) {
            printf("%c ", ch);
            sleep(1);
        }
        printf("\n");
    }

    else {
        // Parent Process
        wait(NULL);  // wait for child to finish

        printf("\nParent Process:\n");
        printf("PID = %d, Parent PID = %d\n", getpid(), getppid());

        for(char ch = 'A'; ch <= 'Z'; ch++) {
            printf("%c ", ch);
            sleep(1);
        }
        printf("\n");
    }

    return 0;
}
