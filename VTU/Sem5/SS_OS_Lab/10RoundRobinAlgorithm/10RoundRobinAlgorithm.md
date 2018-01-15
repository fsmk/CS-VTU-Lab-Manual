#AIM:
To Design, develop and execute a program in C / C++ to simulate the working of Shortest Remaining Time and Round-Robin Scheduling Algorithms.
##Description:
###Shortest remaining time:
Also known as shortest remaining time first (SRTF), is a scheduling method that is a preemptive version of shortest job next scheduling. In this scheduling algorithm, the process with the smallest amount of time remaining until completion is selected to execute. Since the currently executing process is the one with the shortest amount of time remaining by definition, and since that time should only reduce as execution progresses, processes will always run until they complete or a new process is added that requires a smaller amount of time.Shortest remaining time scheduling is the preemptive counter part of SJF and is useful in time sharing system. In SRT, process with the smallest estimated run time to completion is run next, in SJF once a job begin executing, it runs to completion. In SRT a running process may be preempted by a user process with a shorter estimated run time.Consider an example, where three processes arrived in the order P1, P2, P3 at the time mentioned below, and then the average waiting time using SJF scheduling algorithm will be calculated as:
process 	CPU Burst Time 	Time of Arrival
p1 	      10 	            0
p2 	       5 	            1 
p3 	       2 	            2
shortest remaining time scheduling
In this, the CPU will be taken away from the currently executing process whenever a process will less CPU burst time.
As shown in figure, the time when P2 arrives P1 needs 9 millisecond more to finish. As B's cpu burst in 5 millisecond < 9 millisecond, therefore, P1 execution will be preempted and P2 will be executed but against as P3 arrives P2 execution needs 3 more millisecond where as P3 needs only 2 millisecond to execute, thus P3 takes over P2 and so on.

<pre>Waiting time for P1 = 0+ (8-1) = 7 millisecond
Waiting time for P2 = 1+ (4-2) = 3 millisecond
Waiting time for P3 = 2 millisecond
Average waiting time = (7+3+2) / 3 = 4 millisecond
</pre>
####Round Robin Scheduling:
The basic purpose of this algorithm is to support time sharing system. This algorithm is similar to the FCFS algorithm but now it is preempted FCFS scheduling. The preempted take place after a fixed interval of time called quantum time of time slice. Its implementation requires timer interrupt based on which the preemption take place.Consider the set of the processes lined up in the ready queue. The processes are taken out of the ready queue in FCFS order. Let us suppose that a process has been taken up for execution now. The execution cannot go beyond that time slice. This process may either finish up its execution before the time goes off or CPU will be preempted from it after the timer goes off and this cause an interrupt to the operating system. At this time, context switching will take place. The next process will be taken up from the ready queue. The process, which is left by the CPU, will be added to the tail of the ready queue.
<pre>Round Robin scheduling
process 	CPU Burst Time
p1 	10
p2 	5
p3 	2
</pre>
<pre>The Gantt chart is shown below:
robin hood scheduling
Waiting time for P1 = 0 + (6-2) + (10-8) + (13-12) = 7 Millisecond
Waiting time for P2 = 2+ (8-4) + (12-10) = 8 millisecond
Waiting time for P3 = 4millisecond
Therefore average waiting time = (7+8+4)/3 = 6.33 Millisecond
</pre>
<pre>As shown in figure: first p1 gets the cpu and get executed for 2 millisecond, then context switching occurs and P2 get cpu for 2 millisecond, then again content switching occur and P3 get cpu for 2 millisecond, since its cpu burst time is 2 millisecond only, therefore it complete its execution and thus do not get the cpu again. P1 and P2 similarly continue to share the CPU in the same fashion till they are done.
</pre>
###CODE:
<pre>
 #include&lt;stdio.h>
struct proc
{
        int id;
        int arrival;
        int burst;
        int rem;
        int wait;
        int finish;
        int turnaround;
        float ratio;
}process[10]; //structure to hold the process information
struct proc temp;
int no;
int chkprocess(int);
int nextprocess();
 void roundrobin(int, int, int[], int[]);
 void srtf(int);
</pre>
int main()
<pre>{
          int n,tq,choice;
          int bt[10],st[10],i,j,k;
for(; ;)
{
printf("Enter the choice \n");
printf(" 1. Round Robin\n 2. SRT\n 3. Exit \n");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Round Robin scheduling algorithm\n");
printf("Enter number of processes:\n");
  scanf("%d",&n);
  printf("Enter burst time for sequences:");
  for(i=0;i&lt;n;i++)
   {
     scanf("%d",&bt[i]);
     st[i]=bt[i];        //service time
   }
   printf("Enter time quantum:");
   scanf("%d",&tq);
   roundrobin(n,tq,st,bt);
   break;
case 2:
        printf("\n \n ---SHORTEST REMAINING TIME NEXT---\n \n ");
        printf("\n \n Enter the number of processes: ");
        scanf("%d", &n);
        srtf(n);
break;
case 3: break;
}// end of switch
}// end of for
}//end of main()
</pre>
void roundrobin(int n,int tq,int st[],int bt[])
<pre> {                 
int time=0;
          int tat[10],wt[10],i,count=0,swt=0,stat=0,temp1,sq=0,j,k;
          float awt=0.0,atat=0.0;
         while(1)
           {
                     for(i=0,count=0;i&lt;n;i++)
                     {
       temp1=tq;
       if(st[i]==0) // when service time of a process equals zero then
  //count value is incremented
       {
         count++;
         continue;
       }
       if(st[i]>tq) // when service time of a process greater than time
//quantum then time
                st[i]=st[i]-tq; //quantum value subtracted from service time
       else
        if(st[i]>=0)
        {
                 temp1=st[i]; // temp1 stores the service time of a process
                 st[i]=0; // making service time equals 0
        }
        sq=sq+temp1; // utilizing temp1 value to calculate turnaround time
        tat[i]=sq; // turn around time
     } //end of for
     if(n==count) // it indicates all processes have completed their task because the count value
     break; // incremented when service time equals 0
   } //end of while
   for(i=0;i&lt;n;i++) // to calculate the wait time and turnaround time of each process
   {
    wt[i]=tat[i]-bt[i]; // waiting time calculated from the turnaround time - burst time
    swt=swt+wt[i]; // summation of wait time
    stat=stat+tat[i]; // summation of turnaround time
   }
   awt=(float)swt/n; // average wait time
   atat=(float)stat/n; // average turnaround time
   printf("Process_no        Burst time        Wait time        Turn around time\n");
   for(i=0;i&lt;n;i++)
    printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
    printf("Avg wait time is %f\n Avg turn around time is %f\n",awt,atat);
 }// end of Round Robin
</pre>
int chkprocess(int s) // function to check process remaining time is zero or not
<pre>{
        int i;
        for(i = 1; i &lt;= s; i++)
        {
                if(process[i].rem != 0)
                        return 1;
        }
        return 0;
} // end of chkprocess
</pre>           
int nextprocess() // function to identify the next process to be executed
<pre>{
        int min, l, i;
        min = 32000; //any limit assumed
        for(i = 1; i &lt;= no; i++)
        {
                if( process[i].rem!=0 && process[i].rem &lt; min)
                {
                        min = process[i].rem;
                        l = i;
                }
        }
        return l;
} // end of nextprocess
</pre>
void srtf(int n)
<pre>{
int i,j,k,time=0;
float tavg,wavg;
for(i = 1; i &lt;= n; i++)
        {
                process[i].id = i;
                printf("\n\nEnter the arrival time for process %d: ", i);
                scanf("%d", &(process[i].arrival));
                printf("Enter the burst time for process %d: ", i);
                scanf("%d", &(process[i].burst));
                process[i].rem = process[i].burst;
         }
        for(i = 1; i &lt;= n; i++)
        {
                for(j = i + 1; j &lt;= n; j++)
                {
                        if(process[i].arrival > process[j].arrival) // sort arrival time of a process
                        {
                                temp = process[i];
                                process[i] = process[j];
                                process[j] = temp;
                        }
                }
        }
        no = 0;
        j = 1;
       while(chkprocess(n) == 1)
        {
                if(process[no + 1].arrival == time)
                {
                        no++;
                        if(process[j].rem==0)
                         process[j].finish=time;
                        j = nextprocess();
                }
                if(process[j].rem != 0) // to calculate the waiting time of a process
                {
                        process[j].rem--;
                        for(i = 1; i &lt;= no; i++)
                        {
                                if(i != j && process[i].rem != 0)
                                        process[i].wait++;
                        }
                }
                     else
                {

                        process[j].finish = time;
                        j=nextprocess();
                        time--;
                        k=j;
                }

                time++;
        }
        process[k].finish = time;
        printf("\n\n\t\t\t---SHORTEST REMAINING TIME FIRST---");
        printf("\n\n Process Arrival Burst Waiting Finishing turnaround Tr/Tb \n");
        printf("%5s %9s %7s %10s %8s %9s\n\n", "id", "time", "time", "time", "time", "time");
        for(i = 1; i <= n; i++)
        {
                     process[i].turnaround = process[i].wait + process[i].burst; // calc of turnaround
                     process[i].ratio = (float)process[i].turnaround / (float)process[i].burst;
                     printf("%5d %8d %7d %8d %10d %9d %10.1f ", process[i].id, process[i].arrival,
                     process[i].burst, process[i].wait, process[i].finish, process[i].turnaround,
                     process[i].ratio);
         	  tavg=tavg+ process[i].turnaround; //summation of turnaround time
         	  wavg=wavg+process[i].wait; // summation of waiting time
                    printf("\n\n");
        }
        tavg=tavg/n; // average turnaround time
        wavg=wavg/n; // average wait time
            printf("tavg=%f\t shortest remaining time scheduling=%f\n",tavg,wavg);
}// end of srtf
</pre>

####OUTPUT:
<pre>Enter the choice
 1) Round Robin 2) SRT
 3) Exit
1
Round Robin scheduling algorithm
**********************************
Enter number of processes:3
Enter burst time for sequences:24

3

3

</pre>Enter time quantum:4
<pre>Process_no      Burst time      Wait time       Turnaround time
        1                    24              6                  30
        2                    3               4                  7
        3                    3               7                  10
Avg  wait time is 5.666667 
Avg  turnaround time is 15.666667
Enter the choice
 1) Round Robin 2) SRT
 3) Exit
2
 ---SHORTEST REMAINING TIME NEXT---
 Enter the number of processes: 4
Enter the arrival time for process 1: 0
Enter the burst time for process 1: 8
Enter the arrival time for process 2: 1
Enter the burst time for process 2: 4
Enter the arrival time for process 3: 2
Enter the burst time for process 3: 9
Enter the arrival time for process 4: 3
Enter the burst time for process 4: 5
1               24              6               30
2               3               4               7
3               3               7               10
 ---SHORTEST REMAINING TIME FIRST---
 Enter the number of processes: 4
Enter the arrival time for process 1: 0
Enter the burst time for process 1: 8
Enter the arrival time for process 2: 1
Enter the burst time for process 2: 4
Enter the arrival time for process 3: 2
Enter the burst time for process 3: 9
Enter the arrival time for process 4: 3
Enter the burst time for process 4: 5</pre>
                      ---SHORTEST REMAINING TIME NEXT---

<pre> Process  Arrival  Burst   Waiting  Finishing turnaround  Tr/Tb
   id      time    time       time     time      time     time
    1        0       8        	9       17        17       2.1
    2        1       4          0        5         4       1.0
    3        2       9         15       26        24       2.7
    4        3       5          2       10         7       1.4

tavg=12.734766   

wavg=6.500000
