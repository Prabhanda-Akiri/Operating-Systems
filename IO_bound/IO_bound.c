#include <stdio.h>

int main()
{
	int i,j;
	long int n=104886889765739,m=0;
	char buff;
	FILE *fptr1,*fptr2;

	fptr1=fopen("sample.txt","r");
	fptr2=fopen("output.txt","w");

	while(1)
	{
		buff=fgetc(fptr1);
		m++;
		if(n==m)
			break;
		if(buff==EOF)
			break;
		fputc(buff,fptr2);
	}

	fclose(fptr1);
	fclose(fptr2);

	printf("\nDone...!!!\n");
}