#include<stdio.h>
 
void main(){
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp,at[20],ct[20];
    float avwt,avtat;
    printf("Enter number of process:");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
	printf("\nEnter Burst Time and Arrival Time:\n");
        printf("p%d:",i+1); scanf("%d %d",&bt[i],&at[i]);
        p[i]=i+1;           //contains process number
    }
    for(i=0;i<n;i++, pos=i) { //sorting burst time in ascending order
        for(j=i+1;j<n;j++)
            if(bt[j]<bt[pos])
                pos=j;
        temp=bt[i]; bt[i]=bt[pos]; bt[pos]=temp;
        temp=p[i]; p[i]=p[pos]; p[pos]=temp;
	temp=at[i]; at[i]=at[pos]; at[pos]=temp;
	
    }
   for(i=0;i<n;i++)
	printf("%d",bt[i]);
   ct[0]=bt[0];
   wt[0]=0;
    
    for(i=1;i<n;i++)
    {
	ct[i]=ct[i-1]+bt[i];
        printf("%d",ct[i]);
    }
    
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++) { //calculating turnaround time
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\n%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time=%f",avwt);
    printf("\nAverage Turnaround Time=%f\n",avtat);
}

