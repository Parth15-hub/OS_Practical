#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], pr[20];
    int ct[20], tat[20], wt[20], done[20] = {0};
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for(i = 0; i < n; i++) {
        printf("Enter AT, BT and Priority for P%d: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }

    // Priority Scheduling Logic
    while(completed < n) {
        int idx = -1, highest = 9999;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && done[i] == 0) {
                if(pr[i] < highest) {   // smaller = higher priority
                    highest = pr[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            time += bt[idx];        // run completely
            ct[idx] = time;
            done[idx] = 1;
            completed++;
        } else {
            time++;   // CPU idle
        }
    }

    // TAT & WT
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_tat += tat[i];
        total_wt += wt[i];
    }

    // Output
    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage TAT = %.2f", total_tat/(float)n);
    printf("\nAverage WT = %.2f", total_wt/(float)n);

    return 0;
}
