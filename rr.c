#include<stdio.h>

int main()
{
	int a[10],e[10],arr[10],i=0,j,q,n,k,temp,clk,wt[10]={0};
	printf("Enter number of processes:");
	scanf("%d",&n);
	printf("Enter Arrival Time & Execution Time For Processes");
	for(i=0;i<=n-1;i++)
	{
		
		scanf("%d%d",&a[i],&e[i]);
	}
	
	printf("Enter Quantum Time:");
	scanf("%d",&q);

	for(i=0;i<=n-2;i++)
	{
		for(j=0;j<=n-2;j++)
		{
			if(a[j]>=a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;

				temp = e[j];
				e[j] = e[j+1];
				e[j+1] = temp;
			}
		}
	}

	clk = 0;
	i=0;
	clk = a[0];

	for(i=0;i<=n-1;i++)
		arr[i] = 1;

	i = 0;
	while(1)
	{
		
		if((e[i]-q)>=0){
			e[i] = e[i] - q;
			clk = clk + q;
			
			if(e[i]==0 && arr[i]!=0){
				arr[i] = 0;
				printf("P%d end at %d\n",i,clk);
			}
		}
		else{
			clk = clk + e[i];
			e[i] = 0;
			if(e[i]==0 && arr[i]!=0) {printf("P%d end at %d\n",i,clk);
			arr[i] = 0;}
			
		}
		
		if(e[i]!=0) printf("P%d at %d\n",i,clk);
		
			
		if(1)
		{
			for(j=0;j<=n-1;j++)
			{
				if(arr[j] == 1)
					break;
			}

			
			
			if(i<=n-2) i++;
			else if(i<=n-1) i = 0;
			else{ i = j; }
			
		}
		
		for(k=0;k<=n-1;k++)
			if(arr[k] == 1) break;

		if(k==n) break;
		
	}


	


	return 0;
}


OUTPUT:

Enter number of processes:4
Enter Arrival Time & Execution Time For Processes0
5
1
3
2
8
3
6
Enter Quantum Time:2
P0 at 2
P1 at 4
P2 at 6
P3 at 8
P0 at 10
P1 end at 11
P2 at 13
P3 at 15
P0 end at 16
P2 at 18
P3 end at 20
P2 end at 22




