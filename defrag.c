#include &amp;lt;stdio.h&amp;gt;
#include &amp;lt;stdlib.h&amp;gt;
void firstfit(int b[],int p[],int bfree[],int m,int n,int sum)
{
    int i,j,k,s[n],g[m];
    printf(&amp;quot;Firstfit\n&amp;quot;); //firstfit allocation
    for(i=0;i&amp;lt;n;i++)
    {
        for(j=0;j&amp;lt;m;j++)
        {
            if(bfree[j]==0 &amp;amp;&amp;amp; b[j]&amp;gt;=p[i])
            {
                printf(&amp;quot;Process Size:%d Block
Size:%d\n&amp;quot;,p[i],b[j]);
                b[j]=b[j]-p[i]; //calculate unallocated memory in a block
                sum=sum-p[i]; //calculate unallocated memory in a total
memory
                s[i]=1;
                break;
            }
        }
    }
    int a=0;
    for(i=0;i&amp;lt;m;i++)
    {
        if(bfree[i]!=0) //assigning allocated memory to another array
        {
            g[a]=b[i];
            a++;
        }
    }
    g[a]=0;

    for(i=0;i&amp;lt;m;i++)
    {
        if(bfree[i]==0) //assigning unallocated memory to another array
        {
            g[a]=g[a]+b[i]; //summing up unallocated memory blocks
        }
    }
    printf(&amp;quot;\nDefragmentation\n&amp;quot;);
    for(i=0;i&amp;lt;a+1;i++)
    printf(&amp;quot;\n%d&amp;quot;,g[i]); //again allocate the unallocated memory
blocks to process blocks
    for(i=0;i&amp;lt;n;i++)
    {
        for(j=0;j&amp;lt;m;j++)
        {
            if(bfree[j]==0 &amp;amp;&amp;amp; g[j]&amp;gt;=p[i])
            {
                printf(&amp;quot;Process Size:%d Block
Size:%d\n&amp;quot;,p[i],g[a]);
                g[j]=g[j]-p[i]; //calculate the unallocated memory
                sum=sum-p[i]; //calculate unallocated memory in a total
memory
                s[i]=1;
                break;
            }
        }
    }
    for(i=1;i&amp;lt;n;i++)
    {
        if(s[i]!=1)
        {
            printf(&amp;quot;Memory not allocated for block of
size:%d\n&amp;quot;,p[i]); //printing the unallocated
//memory blocks
            printf(&amp;quot;External fragmentation:%d\n&amp;quot;,p[i]);
        }
    }
    //printf(&amp;quot;Total unallocated memory:%d\n&amp;quot;,sum);
}
void sortarray(int arr[],int x) //sortarray function to sort the memory
blocks according to the size
//of the memory blocks
{
    int i,j,temp;
    for(i=0;i&amp;lt;x;i++)
    {
        for(j=i+1;j&amp;lt;x;j++)
        {
            if(arr[i]&amp;gt;arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }

    }
}
void bestfit(int bl[],int p[],int bfree[],int m,int n,int count,int sum)
{
    int i,j,k=0,b[count],s[n],g[m];
     printf(&amp;quot;\nBestfit\n&amp;quot;);
    for(j=0;j&amp;lt;m;j++)
    {
        if(bfree[j]==0) //if the block is free then assign that block to
another array b
        {
            b[k]=bl[j];
            k++;
        }
    }
    int all[n];
    for(i=0;i&amp;lt;n;i++)
    {
        sortarray(b,count); //sort the array b
        for(j=0;j&amp;lt;count;j++)
        {
            if(b[j]&amp;gt;=p[i])
            {
                printf(&amp;quot;Process Size:%d Block
size:%d\n&amp;quot;,p[i],b[j]);
                b[j]=b[j]-p[i]; //calculate the unallocated memory
                sum=sum-p[i]; //calculate the unallocated total memory
                s[i]=1;
                all[i]=0;
                break;
            }
        }
    }
    int a=0;
    for(i=0;i&amp;lt;m;i++)
    {
        if(bfree[i]!=0)
        {
            g[a]=bl[i]; //assigning allocated memory to another array
            a++;
        }
    }
    g[a]=0;
    for(i=0;i&amp;lt;m;i++)
    {
        if(bfree[i]==0)
        {
            g[a]=g[a]+bl[i]; //summing up unallocated memory blocks
        }
    }
    printf(&amp;quot;\nDefragmentation\n&amp;quot;);
    for(i=0;i&amp;lt;a+1;i++)
    printf(&amp;quot;\n%d&amp;quot;,g[i]); //again allocate the unallocated memory
blocks to process blocks
    for(i=0;i&amp;lt;n;i++)
    {

        sortarray(g,a);
        for(j=0;j&amp;lt;a;j++)
        {
            if(g[j]&amp;gt;=p[i])
            {
                printf(&amp;quot;Process Size:%d Block
size:%d\n&amp;quot;,p[i],g[a]);
                g[j]=g[j]-p[i]; //calculate the unallocated memory
                sum=sum-p[i]; // calculate unallocated memory in a total
memory
                s[i]=1;
                all[i]=0;
                break;
            }
        }
    }
    for(i=1;i&amp;lt;n;i++)
    {
        if(s[i]!=1)
        {
            printf(&amp;quot;Memory not allocated for block of
size:%d\n&amp;quot;,p[i]); //printing the unallocated
//memory blocks
            printf(&amp;quot;External fragmentation:%d\n&amp;quot;,p[i]);
        }
    }
     //printf(&amp;quot;Total unallocated memory:%d\n&amp;quot;,sum);
}
void sortreverse(int arr[],int x1) //sortarray function to reversely sort the
memory blocks
//according to the size of the memory blocks
{
    int i,j,temp;
    for(i=0;i&amp;lt;x1;i++)
    {
        for(j=i+1;j&amp;lt;x1;j++)
        {
            if(arr[i]&amp;lt;arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void worstfit(int bl[],int p[],int bfree[],int m,int n,int count,int sum)
{
    int i,j,k=0,b[count],s[n],g[m];
     printf(&amp;quot;\nWorstfit\n&amp;quot;);
    for(j=0;j&amp;lt;m;j++)
    {
        if(bfree[j]==0)
        {
            b[k]=bl[j];
            k++;

        }
    }
    int all[n];
    for(i=0;i&amp;lt;n;i++)
    {
        sortreverse(b,count);
        for(j=0;j&amp;lt;2;j++)
        {
            if(b[j]&amp;gt;=p[i])
            {
                printf(&amp;quot;Process Size:%d  Block
size:%d\n&amp;quot;,p[i],b[j]);
                b[j]=b[j]-p[i]; //calculate the unallocated memory
                sum=sum-p[i]; //calculate unallocated memory in a total
memory
                s[i]=1;
                all[i]=0;
                break;
            }
        }
    }
    int a=0;
    for(i=0;i&amp;lt;m;i++)
    {
        if(bfree[i]!=0)
        {
            g[a]=bl[i]; //assigning allocated memory to another array
            a++;
        }
    }
    g[a]=0;
    for(i=0;i&amp;lt;m;i++)
    {
        if(bfree[i]==0)
        {
            g[a]=g[a]+bl[i]; //summing up unallocated memory block
  } }
    printf(&amp;quot;\nDefragmentation\n&amp;quot;);
    for(i=0;i&amp;lt;a+1;i++)
    printf(&amp;quot;\n%d&amp;quot;,g[i]); //again allocate the unallocated memory
blocks to process
//blocks
    for(i=0;i&amp;lt;n;i++)
    {
        sortreverse(g,a);
        for(j=0;j&amp;lt;2;j++)
        {
            if(g[j]&amp;gt;=p[i])
            {
                printf(&amp;quot;Process Size:%d  Block
size:%d\n&amp;quot;,p[i],g[a]);
                g[j]=g[j]-p[i]; //calculate the unallocated memory
                sum=sum-p[i]; //calculate unallocated memory in a total
memory
                s[i]=1;
                all[i]=0;

                break;
         }}   }
 
    for(i=1;i&amp;lt;n;i++)
    {
        if(s[i]!=1)
            {
            printf(&amp;quot;Memory not allocated for block of
size:%d\n&amp;quot;,p[i]); //printing the unallocated
//memory blocks
            printf(&amp;quot;External fragmentation:%d\n&amp;quot;,p[i]);
            }
    }
    // printf(&amp;quot;Total unallocated memory:%d\n&amp;quot;,sum);
}
int main()
{
    //input
    int e,sumup=0,count=0,i;
    int b1[4]={5,2,3,2};
    int p1[2]={2,4};
    int bfree1[4]={1,0,1,0};
    int b2[4]={5,2,3,2};
    int p2[2]={2,4};
    int bfree2[5]={1,0,1,0};
    int b3[4]={5,2,3,2};
    int p3[2]={2,4};
    int bfree3[4]={1,0,1,0};
    for(e=0;e&amp;lt;4;e++)
    {
        sumup=sumup+b1[e];
    }
    for(i=0;i&amp;lt;4;i++)
    {
        if(bfree1[i]==0)
            count++;
    }
    firstfit(b1,p1,bfree1,4,2,sumup);
    bestfit(b2,p2,bfree2,4,2,count,sumup);
    worstfit(b3,p3,bfree3,4,2,count,sumup);
  
    return 0;
}
