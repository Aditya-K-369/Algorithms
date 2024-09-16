#include <stdio.h>
int main() {
    int n;
    // Input number of processes
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    int burstTime[n], priority[n], waitTime[n], turnAroundTime[n], processId[n];
    // Input Burst Time and Priority for each process
    for (int i = 0; i < n; i++) {
        processId[i] = i + 1;
        printf("Enter Burst Time and Priority Value for Process %d: ", processId[i]);
        scanf("%d %d", &burstTime[i], &priority[i]);
	}
    // Sort processes by priority (higher priority value first)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] < priority[j]) {
                // Swap priorities
                int temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
                // Swap burst times
                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;
                // Swap process IDs
                temp = processId[i];
                processId[i] = processId[j];
                processId[j] = temp;
            }
        }
	}
    int currentTime = 0;
    printf("Order of process Execution is\n");
    // Calculate wait time and turnaround time for each process
    for (int i = 0; i < n; i++) {
        waitTime[i] = currentTime;
        currentTime += burstTime[i];
        turnAroundTime[i] = currentTime;
        // Print process execution order
        printf("P%d is executed from %d to %d\n", processId[i], waitTime[i], turnAroundTime[i]);
	}
    // Print the final table with Burst Time, Wait Time, and Turnaround Time
    printf("Process Id\tBurst Time\tWait Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", processId[i], burstTime[i], waitTime[i], turnAroundTime[i]);
	}
    return 0;
}