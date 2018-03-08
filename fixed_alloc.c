#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,*arr,i;

    printf("\nThis program is the stimulation of fixed size allocation..\n");
    printf("\nMemory size of 160 bytes is designed as a continuous slot");

    arr=(int*)malloc(40 * sizeof(int));

    int slots[]={32,40,20,12,28,4,24};
    n=7;

    printf("\nThe memory is divided as shown below..!!\n");

    for(i=0;i<n-1;++i)
    {
        printf("\nSLOT_%d:    %d bytes",i+1,slots[i]);
    }

    int free_sl[]={1,2,3,4,5,6,7};
    int choice,size,strat,count=0,temp;
    int proc[]={-1,-1,-1,-1,-1,-1,-1};
    int proc_size[]={-1,-1,-1,-1,-1,-1,-1};
    int proc_type[]={-1,-1,-1,-1,-1,-1,-1};
    char strateg[3][20]={"First Fit","Best Fit","Worst Fit"};
    char frag_type[3][20]={"Internal","External","None"};

    while(1)
    {
    printf("\n\nEnter the number of processes you want to allocate: ");
    scanf("%d",&count);

    if(count<8 && count>0)
        break;
    else
        printf("\n\nChoose capable number of processes..!!");
    }

    printf("\n\nChoose your strategy...\n\n1.First fit\n2.Best fit\n3.Worst fit\n");
    scanf("%d",&strat);

    for(int co=0;co<count;co++)
    {
       
            
            printf("Enter the size of the Process %d:    ",co+1);
            scanf("%d",&size);

            switch(strat)
            {
                case 1: for(i=0;i<n;i++)
                        {
                            if(free_sl[i]!=0)
                            {
                                if(slots[i]>=size)
                                {
                                    proc[co]=i;
                                    proc_size[co]=size;
                                    free_sl[i]=0;
                                    if(slots[i]>size)
                                        proc_type[co]=0;
                                    else
                                        proc_type[co]=2;
                                  
                                    break;
                                }
                            }
                        }
                        if(proc[co]==-1)
                        {
                                int sum=0;
                                for(int k=0;k<co;k++)
                                {
                                    if(proc[k]!=-1)
                                        sum=sum+proc_size[k];
                                }
                                if((160-sum)>size)
                                {
                                    proc_type[co]=1;

                                }
                                proc_size[co]=size;
                        }
                        break;

                case 2: temp=-1;
                        for(i=0;i<n;i++)
                        {
                            if(free_sl[i]!=0)
                                {
                                    if(slots[i]>=size)
                                    {
                                        if(temp==-1)
                                            temp=i;
                                        else if(slots[temp]>slots[i])
                                            temp=i;
                                    }
                                }
                        }
                        if(temp!=-1)
                        {proc[co]=temp;
                        proc_size[co]=size;
                        free_sl[temp]=0;
                        if(slots[i]>size)
                            proc_type[co]=0;
                        else
                            proc_type[co]=2;
                        
                        }
                        else
                        {
                                int sum=0;
                                for(int k=0;k<co;k++)
                                {
                                    if(proc[k]!=-1)
                                        sum=sum+proc_size[k];
                                }
                                if((160-sum)>size)
                                {
                                    proc_type[co]=1;

                                }
                                
                                proc_size[co]=size;
                        }
                        break;

                case 3: temp=-1;
                        for(i=0;i<n;i++)
                        {
                            if(free_sl[i]!=0)
                                {
                                    if(slots[i]>=size)
                                    {
                                        if(temp==-1)
                                            temp=i;
                                        else if(slots[temp]<slots[i])
                                            temp=i;
                                    }
                                }
                        }
                        if(temp!=-1)
                        {proc[co]=temp;
                        proc_size[co]=size;
                        free_sl[temp]=0;
                        if(slots[i]>size)
                            proc_type[co]=0;
                        else
                            proc_type[co]=2;
                        
                        }
                        else
                            {
                                int sum=0;
                                for(int k=0;k<co;k++)
                                {
                                    if(proc[k]!=-1)
                                        sum=sum+proc_size[k];
                                }
                                if((160-sum)>size)
                                {
                                    proc_type[co]=1;

                                }
                            
                                proc_size[co]=size;
                            }
                        break;

            }
            
    }
            printf("\nprocesses entered are allocated\n");
            printf("\nThe original memory division..!!\n");

            for(i=0;i<n-1;++i)
            {
                printf("\nSLOT_%d:    %d bytes",i+1,slots[i]);
            }

            printf("\n\nStrategy Used:    %s",strateg[strat-1]);

            printf("\n\nProcess.No     Size(in bytes)    Slot   Fragmentation\n");
            for(i=0;i<count;i++)
            {   
                if(proc[i]==-1)
                    if(proc_type[i]==1)
                        printf("\n  %d.             %d               ---         %s",i+1,proc_size[i],frag_type[proc_type[i]]);
                    else
                        printf("\n  %d.             %d              ---       Couldn't Allocate",i+1,proc_size[i]);
                else
                    printf("\n  %d.             %d                 %d         %s",i+1,proc_size[i],proc[i]+1,frag_type[proc_type[i]]);
            }
            printf("\n");
    }

