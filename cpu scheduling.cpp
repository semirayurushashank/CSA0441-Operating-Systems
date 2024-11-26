#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], wt[n], tat[n];
    float total_wt = 0, total_tat = 0;

    printf("Enter arrival times:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &at[i]);

    printf("Enter burst times:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    wt[0] = at[0]; // First process waiting time equals its arrival time
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1] - at[i]; // Waiting time calculation

    printf("\nP\tAT\tBT\tWT\tTAT");
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i]; // Turnaround time
        total_wt += wt[i];
        total_tat += tat[i];
        printf("\nP%d\t%d\t%d\t%d\t%d", i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}

