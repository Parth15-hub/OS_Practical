#include<stdio.h>

int main() {
    int n, i , j, temp;
    int at[20], bt[20], ct[20], tat[20], wt[20];
    int total_tat = 0, total_wt = 0;
    
    printf("Enter the no. of process: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("Enter the Arrival and Burst Time of P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
    }
    
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(at[j] < at[i]) {
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
            }
        }
    }
    
    ct[0] = at[0] + bt[0];
    
    for(i = 1; i < n; i++) {
        if(ct[i-1] < at[i]) {
            ct[i] = at[i] + bt[i];
        } else {
            ct[i] = ct[i-1] + bt[i];
        }
    }
    
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        
        total_tat += tat[i];
        total_wt += wt[i];
    }
    
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    
    printf("Average Turn Around Time = %.2f", total_tat/ (float)n);
    printf("\nAverage Waiting Time = %.2f", total_wt/ (float)n);
    
    return 0;
}
