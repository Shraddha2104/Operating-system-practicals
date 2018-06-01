import java.util.*;

class Bank
 {
  static int max[][],need[][],alloc[][],marked[],ResIns[],avail[]; 
  static int NumRes,NumProc; 


   public static void main(String[] args)
    {
	accept();
	Bankers();
    }

   static void accept()
    {
	Scanner sc=new Scanner(System.in);
	
	System.out.println("Enter the number of processes and resources:");
	NumProc=sc.nextInt();
	NumRes=sc.nextInt();

	max=new int[NumProc][NumRes];
	alloc=new int[NumProc][NumRes];
	need=new int[NumProc][NumRes];
	ResIns=new int[NumRes];

	System.out.println("Enter the number of instances of each resource:");
	for(int i=0;i<NumRes;i++)
		ResIns[i]=sc.nextInt();

	System.out.println("Enter the Max matrix for the " +NumProc+ " Prcoesses:");

	for(int i=0;i<NumProc;i++)
		for(int j=0;j<NumRes;j++)
			max[i][j]=sc.nextInt();

	
	System.out.println("Enter the Allocated matrix for the "+ NumProc+ " Prcoesses:");

	for(int i=0;i<NumProc;i++)
		for(int j=0;j<NumRes;j++)
		{
			alloc[i][j]=sc.nextInt();
			need[i][j]=max[i][j]-alloc[i][j];	// calc Need Matrix
		}

	
	for(int i=0;i<NumRes;i++)
	{
		int temp=0;
		for(int j=0;j<NumProc;j++)
			temp+=alloc[j][i];
		avail[i]=ResIns[i]-temp;
		
	}

   }

  static int check(int i)
   {
	for(int j=0;j<NumRes;j++)
	  if(need[i][j]<=avail[j])
		return 1;
	return 0;
   }



 static void Bankers()
  {
	marked=new int[NumProc];
	
	
	for(int i=0;i<NumProc;i++)
		marked[i]=0;
	
	int i;
	for(i=0;i<NumProc;i++)					// big loop to run NumProc times
	{
		for(int j=0;j<NumProc;j++)			// keeping track of each process
		{
			if(marked[j]==0&&check(j)==1)
				for(int k=0;k<NumRes;k++)
					avail[k]=avail[k]+max[j][k];
			
			marked[j]=1;
			System.out.println("Process allocated is: P"+j);
			
		}

	}
	
	if(i==NumProc)
		System.out.println("Safety Sequence Allocated");
	else 
		System.out.println("Safety Sequence Not Allocated");
  }

}
	

		
