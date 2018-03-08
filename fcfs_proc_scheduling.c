#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,p,i,t,j,*at,*bt,*ct,*tot,*wt;

	printf("\nEnter the number of processes:	");
	scanf("%d",&n);

	at=(int *)malloc(n * sizeof(int));
	bt=(int *)malloc(n * sizeof(int));
	ct=(int *)malloc(n * sizeof(int));
	tot=(int *)malloc(n * sizeof(int));
	wt=(int *)malloc(n * sizeof(int));

	printf("\n\nEnter the Arriving times...");
	for(i=0;i<n;i++)
	{
		printf("\nArriving Time of P%d:	",i+1);
		scanf("%d",at+i);
	}

	printf("\n\nEnter the Burst times...");
	for(i=0;i<n;i++)
	{
		printf("\nBurst Time of P%d:	",i+1);
		scanf("%d",bt+i);
	}

	t=0;
	int *order;
	order=(int*)malloc(n*sizeof(int));

	for(i=0;i<n;i++)
	{
		if(i==0)
		{	*(ct+i)=*(bt+i);
			*(tot+i)=*(bt+i);
			*(wt+i)=0;
		}
		else
		{
			*(ct+i)=*(ct+i-1)+*(bt+i);
			*(tot+i)=*(ct+i)-*(at+i);
			*(wt+i)=*(ct+i-1)-*(at+i);
		}
	}

	printf("\n");
	printf("|-------|-------|-------|-------|-------|-------|\n");
	printf("| P.No	| Ar.T 	| Bu.T 	| CT 	| TaT 	| WT 	|\n");
	printf("|-------|-------|-------|-------|-------|-------|\n");
	for(i=0;i<n;i++)
	{
		printf("| %d 	| %d 	| %d 	| %d 	| %d 	| %d 	|\n",i+1,*(at+i),*(bt+i),*(ct+i),*(tot+i),*(wt+i));
		printf("|-------|-------|-------|-------|-------|-------|\n");
	}
	float avg_tot=0,avg_wt=0;

	for(i=0;i<n;i++)
	{
		avg_tot=avg_tot+*(tot+i);
		avg_wt=avg_wt+*(wt+i);
	}

	avg_wt=avg_wt/n;
	avg_tot=avg_tot/n;

	printf("\n\nAverage Turn-Around-Time:	%f \nAverage Waiting-Time:	%f\n",avg_tot,avg_wt);
}
