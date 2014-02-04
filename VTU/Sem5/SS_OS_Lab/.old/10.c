 #include<stdio.h>
typedef struct
{
        int name;	//input by user, id of process
        int at;		//arrival time input by user
        int burst;	//input by user
        int wait;	//waiting time
        int tat;	//total average time
        int remaining;  //remaining burst time
        int flag;
}process;

process p[5],p1[5];
int n,n1;
void rr();
void accept();
void sjf();
int minimum();
int tq, t, i, count=0, rtwt=0, rttat=0, temp, sq=0, stwt=0, sttat=0;
float rawt=0.0, ratat=0.0, sawt=0.0, satat=0.0;

void main()
{
        int ch;
        printf("\n      ****MENU****\n1.Shortest Job First\n2.Round Robin Scheduling\n3.Exit\n\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
                case 1: accept();
                        sjf();
                        break;
                      
                case 2: rr();
                        break;
                        
                case 3: break;
                
                default: printf("\nInvalid choice\n");
                
         }
}

//SJF algorithm
//accept function for entering values for SJF scheduling
void accept()
{
        int i;
        printf("Enter total number of processes");
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
                printf("\nEnter the processes name:");
                scanf("%d",&p[i].name);
	        printf("\nEnter arrival time:");
	        scanf("%d",&p[i].at);
	        printf("\nEnter burst time:");
	        scanf("%d",&p[i].burst);
	        p[i].wait=0;
	 }
}	
//sjf() for simulating Shortest Job First scheduling algorithm
void sjf()
{
        int i, j, tbt=0, no, k, min;
        for(i=0; i<n; i++)
        {
                p[i].remaining=p[i].burst;
                tbt = tbt+p[i].burst;		//total burst time
        }
        printf("\n");
        for(i=0; i<tbt; i++)						//i is current burst time
        {
                min=999;
                for(j=0; j<n; j++)
                {
                        if(p[j].at <= i && p[j].remaining > 0)
                        {
                                if(p[j].remaining < min)
                                {
                                        min = p[j].remaining;		//first process to arrive's burst time
                                        no = j;				//process id
                                }
                         }
                }
        
                printf("%d [P%d] ",i,no);				//print current burst time & current process id as Pid
                p[no].remaining=p[no].remaining-1;			//deduct 1 from the remaining burst time
        
                //--------------waiting time------------------
        
                for(k=0; k<n; k++)
                {
                        if(p[k].at<=i && p[k].remaining > 0 && p[k].name!=no)	//if it has already arrived & there is some burst time & it is not the process that was just completed
                        {
                                p[k].wait=p[k].wait+1;				//then process must wait
                        }       
                }
        } //for loop ends here

        printf("%d",i);		//print the final burst time to complete the Gantt chart

	//calculate turnaround time(p) = burst time(p) + waiting time(p)
         for(k=0; k<n; k++)
         {
                p[k].tat=p[k].burst + p[k].wait;		
         }
         
         printf("\nName\tArrival time\tBurst Time\tWaiting Time\tTurnaround Time\n");
         for(k=0; k<n; k++)
         {
                stwt = stwt+p[k].wait;		//total waiting time
                sttat = sttat + p[k].tat;	//total turnaround time
                printf("\nP%d\t%d\t\t%d\t\t%d\t\t%d",p[k].name,p[k].at,p[k].burst,p[k].wait,p[k].tat);
         }
         
         sawt = (float) stwt/n;		//average waiting time
         satat = (float) sttat/n;	//average turnaround time
	 printf("\nFor Shortest Job First algorithm,");
         printf("\nTotal Waiting time = %d\nTotal Turnaround Time = %d\nAverage Waiting Time = %f\nAverage Turnaround Time = %f\n", stwt,sttat,sawt,satat);
}

//Round Robin algorithm
void rr()
{
        printf("Enter total number of processes:\n");
        scanf("%d",&n1);
        printf("Enter burst time for sequences:\n");
        for(i=0; i<n1; i++)
        {
                scanf("%d", &p1[i].burst);
                p1[i].remaining = p1[i].burst;
                p1[i].at=0;
        }
        printf("\nEnter time quantum:");
        scanf("%d", &tq);
        t=0;
        printf("\n");

        while(1)
        {
                for(i=0, count=0; i<n1; i++)
                {
                        temp=tq;
                        if(p1[i].remaining==0)
                        {
                                count++;
                                continue;
                        }
                        
                        if(p1[i].remaining > tq)
                        {
                                p1[i].remaining = p1[i].remaining - tq;
                                printf(" %d ",t);
                                t = t+tq;
                                printf("[ P%d ]", i);
                        }
                        else if (p1[i].remaining >= 0)
                        {
                                temp = p1[i].remaining;
                                printf(" %d ",t);
                                t = t + p1[i].remaining;
                                p1[i].remaining=0;
                                printf("[ P%d ]",i);
                        }
                        
                        sq = sq + temp;
                        p1[i].tat = sq;
                 }
                 if(n1==count)
                        break;
          }
          
          printf(" %d",t);
	  printf("\n");
          for(i=0; i<n1; i++)
          {
                p1[i].wait = p1[i].tat - p1[i].burst;
                rtwt = rtwt + p1[i].wait;
                rttat = rttat + p1[i].tat;
          }
          
          rawt = (float) rtwt/n1;
          ratat = (float) rttat/n1;
          printf("\nProcess id\tBurst Time\tWaiting Time\tTurnaround Time\n");
          for(i=0; i<n1; i++)
                printf("\n%d\t\t%d\t\t%d\t\t%d\n",i+1,p1[i].burst,p1[i].wait,p1[i].tat);
          printf("\n\nFor Round Robin algorithm,\n");           
          printf("Average waiting time = %f\nAverage turnaround time = %f\n",rawt,ratat);
}
