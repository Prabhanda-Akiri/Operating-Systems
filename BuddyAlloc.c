#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j,n,m=16,blocks,d;

	printf("\n-----Stimulation of Buddy Memory Allocation-----\n\n");
	printf("Memory of 1024KB is divided into 16 blocks.\nEach block is of size 64KB\n");
	
	while(1)
	{
		printf("\nEnter the Number of processes to allocate:	");
		scanf("%d",&n);

		if(n>0 & n<16)
			break;
		else
			printf("\nSelect a valid number..");
	}

	int M_block[16],*size_n;

	size_n=(int *)malloc(n*sizeof(int));

	for(i=0;i<m;i++)
		M_block[i]=-1;

	float a;
	int b,ck,flag=0;

	for(i=0;i<n;i++)
	{
		printf("\nSize of Process %d(in KB):	",i+1);
		scanf("%d",&size_n[i]);

		a=size_n[i]/64.0;
		b=size_n[i]/64;


		if(a>b)
			blocks=(int)(size_n[i]/64)+1;
		else
			blocks=(int)(size_n[i]/64);

		switch(blocks)
		{
			
			case 0:
					for(j=0;j<m;j++)
					{
						if(M_block[j]==-1)
						{	M_block[j]=i;
							break;
						}
					}
					break;

			case 1:
					for(j=0;j<m;j++)
					{
						if(M_block[j]==-1)
						{	M_block[j]=i;
							break;
						}
						
					}
					break;

			case 2: 
					for(j=0;j<m;)
					{
						flag=0;
						if(j+1<m)
						{
							if(M_block[j]==-1 && M_block[j+1]==-1)						
							{
								M_block[j]=i;
								M_block[j+1]=i;
								break;
							}
						
							j=j+2;
						}
					}
					break;
			case 3:
			case 4:
					for(j=0;j<m;)
					{
						flag=0;
						if(j+3<m)
						{
							if(M_block[j]==-1 && M_block[j+1]==-1 && M_block[j+2]==-1 && M_block[j+3]==-1)
							{
								M_block[j]=i;
								M_block[j+1]=i;
								M_block[j+2]=i;
								M_block[j+3]=i;
								break;
							}
							
							j=j+4;
						}
					}
					break;
			case 5:
			case 6:
			case 7:
			case 8:
					for(j=0;j<m;)
					{
						flag=0;
						if(j+7<m)
						{
							if(M_block[j]==-1 && M_block[j+1]==-1 && M_block[j+2]==-1 && M_block[j+3]==-1 && M_block[j+4]==-1 && M_block[j+5]==-1 && M_block[j+6]==-1 && M_block[j+7]==-1)
							{
								M_block[j]=i;
								M_block[j+1]=i;
								M_block[j+2]=i;
								M_block[j+3]=i;
								M_block[j+4]=i;
								M_block[j+5]=i;
								M_block[j+6]=i;
								M_block[j+7]=i;
								break;
							}
						
							j=j+8;
						}
					}
					break;

			default:
					printf("\nThis Process is exceding the memory limit\nCan't be allocated\n");

		}

		printf("\n");

		if(blocks>=0 && blocks<9)
		{	
			for(j=0;j<m;j++)
		{
			printf("BLOCK_%d  ",j+1);
		}

		printf("\n");

		for(j=0;j<m;j++)
		{
			if(M_block[j]!=-1)
				printf("    %d  ",size_n[M_block[j]]);
			else
				printf("     --- ");
		}
		printf("\n");
		printf("\n");
	}


	}
	int n1;
	while(1)
	{
		printf("\nEnter the Number of processes to delete:	");
		scanf("%d",&n1);

		if(n1<n)
			break;
		else
			printf("\nSelect a valid number..");
	}
	int sz;
	for(i=0;i<n1;i++)
	{
		printf("\nSize of Process %d(in KB):	",i+1);
		scanf("%d",&sz);

		a=sz/64.0;
		b=sz/64;


		if(a>b)
			blocks=(int)(sz/64)+1;
		else
			blocks=(int)(sz/64);

		switch(blocks)
		{
			
			case 0:
					for(j=0;j<m;j++)
					{
						if(M_block[j]!=-1)
						{	if(size_n[M_block[j]]==sz)
							{	M_block[j]=-1;
							break;}
						}
					}
					break;

			case 1:
					for(j=0;j<m;j++)
					{
						if(M_block[j]!=-1)
						{	if(size_n[M_block[j]]==sz)
							{	M_block[j]=-1;
							break;}
						}
						
					}
					break;

			case 2: 
					for(j=0;j<m;)
					{
						flag=0;
						if(j+1<m)
						{
							if(M_block[j]!=-1 && M_block[j+1]!=-1)						
							{
								if(size_n[M_block[j]]==sz){
								M_block[j]=-1;
								M_block[j+1]=-1;
								break;}
							}
						
							j=j+2;
						}
					}
					break;
			case 3:
			case 4:
					for(j=0;j<m;)
					{
						flag=0;
						if(j+3<m)
						{
							if(M_block[j]!=-1 && M_block[j+1]!=-1 && M_block[j+2]!=-1 && M_block[j+3]!=-1)
							{
								if(size_n[M_block[j]]==sz){
								M_block[j]=-1;
								M_block[j+1]=-1;
								M_block[j+2]=-1;
								M_block[j+3]=-1;
								break;}
							}
							
							j=j+4;
						}
					}
					break;
			case 5:
			case 6:
			case 7:
			case 8:
					for(j=0;j<m;)
					{
						flag=0;
						if(j+7<m)
						{
							if(M_block[j]!=-1 && M_block[j+1]!=-1 && M_block[j+2]!=-1 && M_block[j+3]!=-1 && M_block[j+4]!=-1 && M_block[j+5]!=-1 && M_block[j+6]!=-1 && M_block[j+7]!=-1)
							{
								if(size_n[M_block[j]]==sz){
								M_block[j]=-1;
								M_block[j+1]=-1;
								M_block[j+2]=-1;
								M_block[j+3]=-1;
								M_block[j+4]=-1;
								M_block[j+5]=-1;
								M_block[j+6]=-1;
								M_block[j+7]=-1;
								break;}
							}
						
							j=j+8;
						}
					}
					break;

			default:
					printf("\nThis Process is exceding the memory limit\nCan't be allocated\n");

		}

		printf("\n");

		if(blocks>=0 && blocks<9)
		{	
			for(j=0;j<m;j++)
		{
			printf("BLOCK_%d  ",j+1);
		}

		printf("\n");

		for(j=0;j<m;j++)
		{
			if(M_block[j]!=-1)
				printf("    %d  ",size_n[M_block[j]]);
			else
				printf("     --- ");
		}
		printf("\n");
		printf("\n");
	}
}
}
