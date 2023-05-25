#include <stdio.h>

#define MAX_PROCESSES 10

struct Process
{
    int processID;
    int burstTime;
    int remainingTime;
};

void roundRobinScheduling(struct Process processes[], int n, int timeQuantum)
{
    int completed = 0;
    int currentTime = 0;

    while (completed < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (processes[i].remainingTime > 0)
            {
                if (processes[i].remainingTime <= timeQuantum)
                {
                    currentTime += processes[i].remainingTime;
                    processes[i].remainingTime = 0;
                    completed++;
                    printf("Process %d executed. Burst time: %d, Completion time: %d\n", processes[i].processID, processes[i].burstTime, currentTime);
                }
                else
                {
                    currentTime += timeQuantum;
                    processes[i].remainingTime -= timeQuantum;
                    printf("Process %d executed. Burst time: %d, Remaining time: %d\n", processes[i].processID, processes[i].burstTime, processes[i].remainingTime);
                }
            }
        }
    }
}

int main()
{
    int n, timeQuantum;
    struct Process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        processes[i].processID = i + 1;
        printf("Process %d: ", processes[i].processID);
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
    }

    printf("\n--- Round Robin Scheduling ---\n");
    roundRobinScheduling(processes, n, timeQuantum);

    return 0;
}
