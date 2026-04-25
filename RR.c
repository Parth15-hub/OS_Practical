#include <stdio.h>

int main() {
    int n, i, time = 0, remain, tq;
    int bt[20], rt[20], ct[20], tat[20], wt[20];
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input Burst Time
    for(i = 0; i < n; i++) {
        printf("Enter BT for P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];   // remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;

    // Round Robin Logic
    while(remain > 0) {
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                if(rt[i] <= tq) {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    remain--;
                } else {
                    time += tq;
                    rt[i] -= tq;
                }
            }
        }
    }

    // TAT & WT
    for(i = 0; i < n; i++) {
        tat[i] = ct[i];        // AT = 0
        wt[i] = tat[i] - bt[i];

        total_tat += tat[i];
        total_wt += wt[i];
    }

    // Output
    printf("\nP\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage TAT = %.2f", total_tat/(float)n);
    printf("\nAverage WT = %.2f", total_wt/(float)n);

    return 0;
}
