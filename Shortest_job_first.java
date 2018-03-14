import java.util.Scanner;
import java.util.*;
import java.lang.*;
import java.io.*;

public class Sjf
{
	public static void main(String[] args)
	{
		int i,j,a,b;
		Scanner in=new Scanner(System.in);

		System.out.println("\nEnter the total no.of processes:	");
		int n=in.nextInt();

		ArrayList<processes> ready_queue=new ArrayList<processes>();
		ArrayList<Integer> exec=new ArrayList<Integer>();

		System.out.println("\nEnter the arriving times and burst times..");

		processes prc[]=new processes[n];

        for(i=0;i<n;i++)
        {
            System.out.print("\nArriving Time of P"+(i+1)+":    ");
            a=in.nextInt();
            System.out.print("Burst Time of P"+(i+1)+":    	");
            b=in.nextInt();
            prc[i]=new processes(i,a,b);
        }

       	int time=0,total_t=0,p_no=0,p_s=0;

		for(i=0;i<n;i++)
			total_t=total_t+prc[i].bt;


		for(i=0;i<total_t;i++)
		{
			for(j=p_no+1;j<n;j++)
				{
					if(prc[j].at==i+1)
						ready_queue.add(prc[j]);
					Collections.sort(ready_queue,new BurstTimeComparator());

				}

			if(exec.isEmpty())
			{
				exec.add(0);
				p_no=0;
				p_s=i;
			}

			else
			{
				if(i==total_t-1)
					prc[p_no].ct=total_t;

				if(i-p_s==prc[p_no].bt)
				{
					prc[p_no].ct=i;
					prc[p_no].tat=prc[p_no].ct-prc[p_no].at;
					prc[p_no].wt=prc[p_no].tat-prc[p_no].bt;

					p_no=(ready_queue.remove(0)).pid;
					exec.add(p_no);
					p_s=i;
				}


			}

		}

		System.out.println("\n");
		System.out.println("P.No 	Ar.t 	Bu.t 	CT 	TaT 	Wt\n");



		float avg_wt=0,avg_tat=0;

		for(i=0;i<n;i++)
		{
			avg_tat+=prc[i].tat;
			avg_wt+=prc[i].wt;
		}

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				if(prc[j].pid==i)
					System.out.println("P"+(i+1)+" 	"+prc[j].at+" 	"+prc[j].bt+" 	"+prc[j].ct+" 	"+prc[j].tat+" 	"+prc[j].wt);
		}

		System.out.println("\n\nThe average Turn-Around-Time:	"+avg_tat/n+
						   "\n\nThe average Waiting-Time is:	"+avg_wt/n+"\n\n");

	}
}

class processes
{
	int bt,at,pid,ct=0,tat=0,wt=0;

	processes(int i,int a,int b)
	{
		pid=i;
		at=a;
		bt=b;
	}

}


class BurstTimeComparator implements Comparator<processes> {
    public int compare(processes a, processes b) {
        return a.bt-b.bt;
    }
}
