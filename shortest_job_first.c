#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,temp,n;
    printf("Enter how many processes\n");
    scanf("%d",&n);
    int process[n],burstTime[n],waitingTime[n],turnAroundTime[n];

    //process input
    printf("Enter the processes\n");
    for(i=0;i<n;i++){
        scanf("%d",&process[i]);
    }
    //burst time input
    printf("Enter the burst time\n");
    for(i=0;i<n;i++){
        scanf("%d",&burstTime[i]);
    }
    // applying bubble sort
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(burstTime[j]>burstTime[j+1]){
                temp = burstTime[j];
                burstTime[j] = burstTime[j+1];
                burstTime[j+1] = temp;

                temp = process[j];
                process[j] = process[j+1];
                process[j+1] = temp;
            }
        }
    }

    //calculate waiting time and burst time
    printf("process \t burst time \t waiting time \t turnaround time\n");
    for(i=0;i<n;i++){
        waitingTime[i] = 0;
        turnAroundTime[i]=0;
        for (j=0;j<i;j++){
            waitingTime[i] = waitingTime[i]+burstTime[j];
        }
        turnAroundTime[i] = waitingTime[i]+burstTime[i];
        printf("%d\t\t %d\t\t %d\t\t %d\n",process[i], burstTime[i],waitingTime[i],turnAroundTime[i]);
    }

    return 0;
}
