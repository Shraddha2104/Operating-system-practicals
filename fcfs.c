#include<stdio.h>
 
int main() {
    int n,bt[20],wt[20],at[20],tat[20],i,j,ct[20];
    float avwt=0,avtat=0;
    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&n);
    printf("\nEnter Process Burst Time and arrival time\n");
    for(i=0;i<n;i++){
        printf("P[%d]:",i+1);
        scanf("%d %d",&bt[i],&at[i]);
    }
    wt[0]=0;
    ct[0]=bt[0];
    //waiting time for first process is 0
    for(i=1;i<n;i++)
    {
	ct[i]=ct[i-1]+bt[i];
    }
   
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++) { //calculating turnaround time
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
    avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time:%f",avwt);
    printf("\nAverage Turnaround Time:%f",avtat);
    return 0;
}

