#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,*arr,i,pr;

    printf("\nThis program is the stimulation of varied size allocation..\n");
    printf("\n\nMemory size of 1500 bytes is designed as a continuous slot.\nBut three processes already occupied some space.\n\n");

    arr=(int*)malloc(40 * sizeof(int));

    int fill_start[]={1,251,901};
    int fill_end[]={100,550,1500};

    printf("\nProcess 	Start 	End 	Size(in bytes)\n");

    for(i=0;i<3;i++)
    {
    	printf("\n  %d. 		%d 	%d 	%d",i+1,fill_start[i],fill_end[i],fill_end[i]-fill_start[i]+1);

    }

    int free_s[]={101,551};
    int free_e[]={250,900};

    printf("\n\nThe free slots are as below:\n");

    printf("\nSlot 		Start 	End 	Size(in bytes)\n");

    for(i=0;i<2;i++)
    {
    	printf("\n  %d. 		%d 	%d 	%d",i+1,free_s[i],free_e[i],free_e[i]-free_s[i]+1);

    }

    printf("\n\nEnter the number of processes you want to allocate: ");
    scanf("%d",&pr);


    int *proc_size,*proc_type,*proc_start,*proc_end;


    proc_size=(int*)malloc(pr *sizeof(int));
    proc_type=(int*)malloc(pr *sizeof(int));
    proc_start=(int*)malloc(pr *sizeof(int));
    proc_end=(int*)malloc(pr *sizeof(int));

    char strateg[3][20]={"First Fit","Best Fit","Worst Fit"};
    char frag_type[3][20]={"Internal","External","None"};

    for(i=0;i<pr;i++)
    {
    	*(proc_size + i)=-1;
    	*(proc_type + i)=-1;
    	*(proc_start + i)=-1;
    	*(proc_end + i)=-1;
    }

    int choice,size,strat,j,count=0,temp,s,e,pos=0,p;

    		printf("\n\nChoose your strategy...\n\n1.First fit\n2.Best fit\n3.Worst fit\n");
            scanf("%d",&strat);
 
    for(i=0;i<pr;i++)
    {

            printf("Enter the size(in bytes) of the Process %d(P%d):    ",i+1,i+1);
            scanf("%d",&size);
            
            p=0;
            switch(strat)
            {
                case 1: 
                		for(j=0;j<2;j++)
                		{
                			if(free_s[j]>0 && free_e[j]>0)
                			if((free_e[j]-free_s[j]+1)>=size)
                				{p=1;
                			break;}
                		}

                        if(p==0)
                        {
                        	int sum=0;
                                for(int k=0;k<i;k++)
                                {
                                    if(proc_start[k]!=-1)
                                        sum=sum+proc_size[k];
                                }
                                if((500-sum)>size)
                                {
                                    proc_type[i]=1;

                                }
                                proc_size[i]=size;
                        }

                        else
                        {
                        	*(proc_size + i)=size;
    						*(proc_type + i)=2;
    						*(proc_start + i)=free_s[j];
    						*(proc_end + i)=free_s[j]+size;
    						if((free_s[j]+size+1)<free_e[j])
    							free_s[j]=free_s[j]+size+1;
    						else
    							{free_s[j]=-1;
    							free_e[j]=-1;}
                        }
                        
                        break;

                case 2: temp=-1;
                        
                		for(j=0;j<2;j++)
                		{
                			if(free_s[j]>0 && free_e[j]>0)
                				if((free_e[j]-free_s[j]+1)>=size)
                				if(temp>-1)
                					{
                						if((free_e[j]-free_s[j]+1)<(free_e[temp]-free_s[temp]+1))
                					{
                						temp=j;
                					}}
                				else
                					temp=j;
                		}

                        if(temp!=-1)
                        {
                        	*(proc_size + i)=size;
    						*(proc_type + i)=2;
    						*(proc_start + i)=free_s[temp];
    						*(proc_end + i)=free_s[temp]+size;
    						if((free_s[temp]+size+1)<free_e[temp])
    							free_s[temp]=free_s[temp]+size+1;
    						else
    							{free_s[j]=-1;
    							free_e[j]=-1;}
                        }
                        else
                        {
                        	int sum=0;
                                for(int k=0;k<i;k++)
                                {
                                    if(proc_start[k]!=-1)
                                        sum=sum+proc_size[k];
                                }
                                if((500-sum)>size)
                                {
                                    proc_type[i]=1;

                                }
                                proc_size[i]=size;
                        }
                        break;

                case 3: temp=-1;
                        
                		for(j=0;j<2;j++)
                		{
                			if(free_s[j]>0 && free_e[j]>0)
                				if((free_e[j]-free_s[j]+1)>=size)
                				if(temp>-1)
                					{
                						if((free_e[j]-free_s[j]+1)<(free_e[temp]-free_s[temp]+1))
                					{
                						temp=j;
                					}}
                				else
                					temp=j;
                		}

                        if(temp!=-1)
                        {
                        	*(proc_size + i)=size;
    						*(proc_type + i)=2;
    						*(proc_start + i)=free_s[temp];
    						*(proc_end + i)=free_s[temp]+size;
    						if((free_s[temp]+size+1)<free_e[temp])
    							free_s[temp]=free_s[temp]+size+1;
    						else
    							{free_s[j]=-1;
    							free_e[j]=-1;}
                        }
                        else
                        {
                        	int sum=0;
                                for(int k=0;k<i;k++)
                                {
                                    if(proc_start[k]!=-1)
                                        sum=sum+proc_size[k];
                                }
                                if((500-sum)>size)
                                {
                                    proc_type[i]=1;

                                }
                                proc_size[i]=size;                        
                            }
                        break;

    		}
    }

    printf("\n\nThe final memory allocation of 1500 bytes is as follows:	\n\n");
    printf("\nStrategy Used:    %s",strateg[strat-1]);
    printf("\n\nProcess. 	Start 	End 	Size(in bytes) 	Fragmentation-type\n");

    int cout=0,l;

    for(i=0;i<pr;i++)
    {
    	for(j=0;j<3;j++)
    	{
    		if((*(proc_start + i)== fill_end[j] + 1) || (i==0 && j==0))
    		{	printf("\n%d. 		%d 	%d 	%d 		%s",j+1,fill_start[j],fill_end[j],fill_end[j]-fill_start[j]+1,frag_type[2]);
    			cout=cout+1;
    		}
    	}
    	if(proc_start[i]==-1)
    		if(proc_type[i]==1)
    		{	printf("\nP%d.		-- 	-- 	%d 		%s",i+1,*(proc_size + i),frag_type[1]);
    			cout=cout+1;
    		}
    		else
    		{	printf("\nP%d.		-- 	-- 	%d 		Couldn't allocate",i+1,*(proc_size + i));
    			cout=cout+1;
    		}
    	else
    		{printf("\nP%d.		%d 	%d 	%d 		%s",i+1,*(proc_start + i),*(proc_end + i),*(proc_size + i),frag_type[2]);
    		cout=cout+1;
    	}


    	for(j=0;j<3;j++)
    	{
    		if(*(proc_end + i) + 1== fill_start[j])
    		{	printf("\n%d. 		%d 	%d 	%d 		%s",j+1,fill_start[j],fill_end[j],fill_end[j]-fill_start[j]+1,frag_type[2]);
    			cout=cout+1;
    		}

    	}
    }

    if(cout<3+pr)
    {
    	l=3+pr-cout;
    	int k=cout-pr;

    	for(i=0;i<l;i++)
    	{
    		printf("\n%d. 		%d 	%d 	%d 		%s",k+i+1,fill_start[i+k],fill_end[i+k],fill_end[i+k]-fill_start[i+k]+1,frag_type[2]);
    	}
    }

    printf("\n\n");

}
