import java.util.Scanner;
import java.util.LinkedList;

public class LList
{
    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        System.out.println("\nThis is stimulation of PAGING with help of LINKED LISTS..\n\n");
        System.out.println("This operating system has secondary memory containing pages each of size 256 bytes..\n");

        int size,i,j,k,l,n,m;
        int emp_frames[]={5,7,12,17,19,23,25,29,33,36,40};
        m=emp_frames.length;


        System.out.print("Enter the size of the PROCESS(in Bytes) :    ");
        size=in.nextInt();

        n=(int)size/256;
        if(size%256!=0)
            n=n+1;

        System.out.println("\nThe process needs "+n+" PAGES..\n");

        LinkedList<Integer> llist=new LinkedList<Integer>();

        System.out.println("MAIN MEMORY contains frames each of size 256 bytes\n");

        Thread t=Thread.currentThread();

        for(i=0;i<n;i++)
        {
            try{
                Thread.sleep(1000);   
                if((i+1)<=m)
                    System.out.println("Transferring PAGE "+ (i+1)+" to MAIN MEMORY...");
                else
                {    System.out.println("\nMAIN MEMORY is out of space..\nRemaining pages can't be allocated");   
                break;
                }       
            }

            catch(InterruptedException e)
            {
                System.out.println("Process given is exceding the time limit to transfer in to the main memory");
            }
        }

        k=i;

        if(n<m)
            System.out.println("\nAll PAGES are transferred into the main memory");
        else
            System.out.println("\nOnly "+k+" PAGES are allocated in to the main memory");

        for(i=0;i<k;i++)
        {
            if(i<m)
                llist.add(emp_frames[i]);
            else
                break;
        }

        int pg_no,by_no,flag_1=0;

        System.out.print("\nENTER QUERY PAGE.NO :");

        pg_no=in.nextInt();
        pg_no=pg_no-1;
       
        System.out.println("\nSearching for the Page "+(pg_no+1)+" started..\n");

        for(i=0;i<=pg_no;i++)
        {
            if(i<m)
            {

                try{
                Thread.sleep(1000);   
                if(i<=pg_no)
                    System.out.println("Found PAGE "+(i+1)+" at FRAME "+llist.get(i));
                else
                   
                    {   
                    System.out.println("The QUERY PAGE "+(pg_no+1) +" is fount at the FRAME "+llist.get(i));
                    flag_1=1;
                    }
                }

                catch(InterruptedException e)
                {
                    System.out.println("\nSearch for the Page "+(pg_no+1)+" is exceding time limit\n");
                }
            }
        }

        if(flag_1==0)
        {
            System.out.println("\nThe QUERY page is not allocated in the main memory..\n\nPAGE-IN and PAGE-OUT should be done");

            try{
                Thread.sleep(2000);   
                System.out.println("\nPAGING OUT Page 1");
                Thread.sleep(2000);
                System.out.println("\nPAGING IN Page "+ (pg_no+1));
                }

                catch(InterruptedException e)
                {
                    System.out.println("\nSearch for the PAGE "+(pg_no+1)+" is exceding time limit\n");
                }

            llist.add(llist.get(0));
            llist.set(1,-1);

            System.out.println("\nThe requested PAGE "+(pg_no+1) +" is fount at the FRAME "+llist.get(pg_no)+"\n");
        }
    }
}
