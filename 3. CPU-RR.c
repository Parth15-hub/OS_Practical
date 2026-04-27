#include <stdio.h>

int main() {
    int n, i, time = 0, remain, tq;
    int at[20], bt[20], rt[20], ct[20], tat[20], wt[20];
    int done[20] = {0};
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input AT & BT
    for(i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;

    // Round Robin with AT
    while(remain > 0) {
        int executed = 0;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {

                executed = 1;

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

        // CPU Idle
        if(!executed)
            time++;
    }

    // Calculate TAT & WT
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_tat += tat[i];
        total_wt += wt[i];
    }

    // Output
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage TAT = %.2f", total_tat/n);
    printf("\nAverage WT = %.2f", total_wt/n);

    return 0;
}
