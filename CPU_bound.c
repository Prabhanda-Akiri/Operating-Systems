#include <stdio.h>

int main()
{
	int n=1000000,m=0,i,j,k=0,count,flag;

	while(1)
	{
		if(m==n)
			break;
		k++;
		flag=0;
		for(i=2;i<k;i++)
		{
			if(k%i==0)
			{
				flag=1;
				break;
			}
		}

		if(flag==0)
			printf("%d\n",k);
		m++;
	}
}

//CPU %=99.7
