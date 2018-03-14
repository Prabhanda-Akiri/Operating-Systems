import java.util.*;
import java.lang.*;
import java.io.*;


public class Priority_Scheduling
{
	public static void main(String[] args)
	{
		int n,i,j,tq,at,bt,pr;
		Scanner in=new Scanner(System.in);
		System.out.println("\n\nSimulation of Priority Scheduling Policy in piemptive fashion..\n\nEnter the number of processes:	");
		n=in.nextInt();

		ArrayList<processes> ready_queue=new ArrayList<processes>();
		ArrayList<Integer> exec=new ArrayList<Integer>();

		processes[] prc=new processes[n];

		System.out.println("\nEnter the arriving times, burst times an priorities..");

		for(i=0;i<n;i++)
		{
			System.out.print("\nArriving time of P"+(i+1)+" :	");
			at=in.nextInt();
			System.out.print("Burst time of P"+(i+1)+" :	");
			bt=in.nextInt();
			System.out.print("Priority of P"+(i+1)+" :	");
			pr=in.nextInt();
			prc[i]=new processes(i,at,bt,pr);
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
					Collections.sort(ready_queue,new PriorityComparator());
				}

			if(exec.isEmpty())
			{	
				exec.add(0);
				p_no=0;
				p_s=i;
				prc[p_no].r_bt--;

				if(!ready_queue.isEmpty())
				{
					if((ready_queue.get(0)).pr > prc[p_no].pr)
					{
						ready_queue.add(prc[p_no]);
						p_no=(ready_queue.remove(0)).pid;
						p_s=i;
					}

				}
			}

			else
			{
				prc[p_no].r_bt--;


				if(i==total_t-1)
				{	prc[p_no].ct=total_t;
					break;
				}
				
				if(prc[p_no].r_bt==0)
				{
					prc[p_no].ct=i+1;
					p_no=(ready_queue.remove(0)).pid;
					Collections.sort(ready_queue,new PriorityComparator());
					exec.add(p_no);
					p_s=i;
				}

				if(!ready_queue.isEmpty())
				{
					if((ready_queue.get(0)).pr > prc[p_no].pr)
					{
						ready_queue.add(prc[p_no]);
						p_no=(ready_queue.remove(0)).pid;
						Collections.sort(ready_queue,new PriorityComparator());
						p_s=i;
					}

				}


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
		System.out.println("P.No 	Ar.t 	Bu.t 	Pr 	CT 	TaT 	Wt\n");


		for(i=0;i<n;i++)
		{
			System.out.println("P"+(i+1)+" 	"+prc[i].at+" 	"+prc[i].bt+" 	"+prc[i].pr+" 	"+prc[i].ct+" 	"+prc[i].tat+" 	"+prc[i].wt);
		}

		System.out.println("\n\nThe average Turn-Around-Time:	"+avg_tat/n+
						   "\n\nThe average Waiting-Time is:	"+avg_wt/n+"\n\n");
	}
}

class processes
{
	int pid,at,bt,ct,r_bt,tat,wt,pr;

	processes(int i,int a,int b,int p)
	{
		pid=i;
		at=a;
		bt=b;
		pr=p;
		r_bt=b;
	}
}

class PriorityComparator implements Comparator<processes> {
    public int compare(processes a, processes b) {
        return b.pr-a.pr;
    }
}
