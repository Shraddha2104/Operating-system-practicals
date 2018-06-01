#include<stdio.h>
int main()
{
  int i,j,n,time,sum_wait=0;
  int smallest,at[10],bt[10],priority[10],remain;
  
  printf("Enter no of Processes : ");
  scanf("%d",&n);
  remain=n;
  
  
  for(i=0;i<n;i++)
  {
    printf("Enter arrival time, burst time and priority for process p%d :\n",i+1);
    scanf("%d",&at[i]);
    scanf("%d",&bt[i]);
    scanf("%d",&priority[i]);
  }
  
  
  priority[9]=11;
  printf("\n\nProcess\twaiting time\n");
  
  for(time=0;remain!=0;)
  {
    smallest=9;
    
    for(i=0;i<n;i++)
    {
      if(at[i]<=time && priority[i]<priority[smallest] && bt[i]>0)
      {
        smallest=i;
      }
    }
    
    time+=bt[smallest];
    remain--;
    printf("P[%d]\t\t%d\n",smallest+1,time-at[smallest]-bt[smallest]);
    sum_wait+=time-at[smallest]-bt[smallest];
    bt[smallest]=0;
    
  }
  
  printf("\nAvg waiting time = %f\n",sum_wait*1.0/n);

  return 0;
}
