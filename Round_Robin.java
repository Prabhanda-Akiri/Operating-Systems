import java.util.Scanner;
import java.util.LinkedList;

public class round_robin
{
	public static void main(String[] args)
	{
		int n,i,j,tq,at,bt;
		Scanner in=new Scanner(System.in);
		System.out.println("\n\nSimulation of Round Robin Scheduling Policy..\n\nEnter the number of processes:	");
		n=in.nextInt();

		LinkedList<Integer> ready_queue=new LinkedList<Integer>();
		LinkedList<Integer> exec=new LinkedList<Integer>();

		processes[] prc=new processes[n];

		System.out.println("\nEnter the arriving times and burst times..");

		for(i=0;i<n;i++)
		{
			System.out.print("\nArriving time of P"+(i+1)+" :	");
			at=in.nextInt();
			System.out.print("Burst time of P"+(i+1)+" :	");
			bt=in.nextInt();
			prc[i]=new processes(i,at,bt);
		}

		System.out.print("\n\nEnter Time Quatum:	");
		tq=in.nextInt();

		int time=0,total_t=0,p_no=0,p_s=0;

		for(i=0;i<n;i++)
			total_t=total_t+prc[i].bt;


		for(i=0;i<total_t;i++)
		{
			for(j=p_no+1;j<n;j++)
				{
					if(prc[j].at==i+1)
						ready_queue.add(j);
				}

			if(exec.isEmpty())
			{	
				exec.add(0);
				p_no=0;
				p_s=i;
				prc[p_no].r_bt--;
			}

			else
			{
				prc[p_no].r_bt--;

				
				if(prc[p_no].r_bt==0)
				{
					prc[p_no].ct=i+1;
					if(!ready_queue.isEmpty())
					p_no=ready_queue.remove(0);
					exec.add(p_no);
					p_s=i;
				}

				if((i-p_s)==tq)
				{
					if(!ready_queue.isEmpty())
					{
						ready_queue.add(p_no);
						p_no=ready_queue.remove(0);
						p_s=i;
					}

				}

				if(i==total_t-1)
					prc[p_no].ct=total_t;

			}
		}
		float avg_wt=0,avg_tat=0;

		for(i=0;i<n;i++)
		{
			prc[i].tat=prc[i].ct-prc[i].at;
			prc[i].wt=prc[i].tat-prc[i].bt;
			avg_tat+=prc[i].tat;
			avg_wt+=prc[i].wt;
		}

		System.out.println("\n");
		System.out.println("P.No 	Ar.t 	Bu.t 	CT 	TaT 	Wt\n");


		for(i=0;i<n;i++)
		{
			System.out.println("P"+(i+1)+" 	"+prc[i].at+" 	"+prc[i].bt+" 	"+prc[i].ct+" 	"+prc[i].tat+" 	"+prc[i].wt);
		}

		System.out.println("\n\nThe average Turn-Around-Time:	"+avg_tat/n+
						   "\n\nThe average Waiting-Time is:	"+avg_wt/n+"\n\n");

	}


}

class processes
{
	int pid,at,bt,ct,r_bt,tat,wt;

	processes(int i,int a,int b)
	{
		pid=i;
		at=a;
		bt=b;
		r_bt=b;
	}
}
