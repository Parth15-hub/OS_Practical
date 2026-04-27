#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], pr[20], rt[20], ct[20], tat[20], wt[20];
    float total_wt = 0, total_tat = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter AT, BT and Priority for P%d: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }
    
    while(completed < n) {
        int highest = 9999, idx = -1;
        
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(bt[i] < highest) {
                    highest = bt[i];
                    idx = i;
                }
            }
        }
        
        if(idx != -1) {
            rt[idx]--;
            time++;
            
            if(rt[idx] == 0) {
                ct[idx] = time;
                completed++;
            }
        } else {
            time++;
        }
    }
    
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
