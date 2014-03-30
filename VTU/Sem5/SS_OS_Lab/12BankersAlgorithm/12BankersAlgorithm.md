##AIM: Program 12: Design, develop and run a program to implement the Bankers Algorithm. Demonstrate its Working with different data values

###DESCRIPTION:
The Banker's algorithm is a resource allocation and deadlock avoidance algorithm developed by Edsger Dijkstra that tests for safety by simulating the allocation of predetermined maximum possible amounts of all resources, and then makes an "s-state" check to test for possible deadlock conditions for all other pending activities, before deciding whether allocation should be allowed to continue.The Banker's algorithm is run by the operating system whenever a process requests resources.The algorithm avoids deadlock by denying or postponing the request if it determines that accepting the request could put the system in an unsafe state. When a new process enters a system, it must declare the maximum number of instances of each resource type that it may ever claim; clearly, that number may not exceed the total number of resources in the system. Also, when a process gets all its requested resources it must return them in a finite amount of time.

###ALGORITHM:
<pre>
Let n be the number processes in the system and m be the number of resource types. We need the following data structures:
(1)Available 
(2) Max 
(3) Allocation 
(4) Need 
1) Available: A vector of length m indicates the number of available resources of each type. 
If available [j] = k, there are k instances of resource type R available.
2)Max: An n x m matrix defines the maximum demand of each process. 
If Max [i, j] = k, then process P. may request at most k instances of resource type Rr
3)Allocation: An n x m matrix defines the number of resources of each type currently allocated to each process.
 If allocation [i, j] = k, then P. is currently allocated k instances of resource type R
4)Need: An n x m matrix indicates the remaining resource need of each process.
 If Need |i, j] = k, then process P. may need k more instances of resource type R, to complete its task. Need [i, j] - Allocation [i, j].
</pre>
####Safety algorithm: 
Safety algorithm is used to find the state of the system: That is, system may be safe state or unsafe state. Method for this is as follows:
<pre>
1)Let work and finish be vector of length m and n respectively. Initialize work = Available and Finish [i] = False for i = 1, 2, 3, 4, … n.
2)Find an i such that both
a)Finish [i] = False b) Need f[j] &lt; work
If no such i exist, go to step 4.
3)Work : = Work + Allocation i
Finish [i] = true to step 2
4)If Finish [i] = true for all i, then the system is in a safe state. 
</pre>
####Resource-request algorithm: 
<pre>
Let request, be the request vector for process P. If Request, fj] = k, then process P. wants k instances of resource type R. 
When a request for resources is made by process P, the following actions are taken.
1)If Request. &lt; Need(, then go to step 2. Otherwise, raise an eitor condition since the process has exceeded its maximum claim.
2)If Request &lt; Available, then go to step 3. Otherwise, P. must wait since the resources are not available.
3)Available : = Available - Request.; Allocation : = Allocation + Request.; Need; : = Needt - Request.;

If the resulting resource allocation stale is safe, the transaction is completed and process P. is allocated its resources. If the new state is unsafe, then P. must wait to the Request, and the old resource allocation state is restored.
</pre>
###CODE 1:
<pre>
    #include&lt;stdio.h&gt;
    #include&lt;string.h&gt;
    #include&lt;stdlib.h&gt;
    int n,m,i,j;    //n=no. of processes, m= recources
    int all[10][10],max[10][10],need[10][10],avail[10],work[10],req[10];
    int count=0;
   struct process 
   {
     char process[10]; // to name the process like process=0 implies process 0 = P0
     int flag; //used to check safe sequence
    }p[10];
   void input()
    {
     printf("\n Enter total num of processes:");
     scanf("%d",&n);
     for(i=0;i&lt;n;i++)
     {
     printf("\nprocess:-");
      scanf("%s",p[i].process);
     }
     printf("\n Enter the number of resources:");
     scanf("%d",&m);
     printf("\n Enter allocation matrix:");
     for(i=0;i&lt;n;i++)
     {
      for(j=0;j&lt;m;j++)
      {
       scanf("%d",&all[i][j]);
      }
     }
     printf("\n Enter max matrix:");
     for(i=0;i&lt;n;i++)
     {
     for(j=0;j&lt;m;j++)
      {
       scanf("%d",&max[i][j]);
      }
     }
     printf("\n  need matrix:");
     for(i=0;i&lt;n;i++)
     {
      for(j=0;j&lt;m;j++)
      {
       need[i][j]=max[i][j]-all[i][j];
       printf("%d",need[i][j]);
      }
      printf("\n");
     }
     printf("\n Enter Available");
     for(i=0;i&lt;m;i++)
     {
      scanf("%d",&avail[i]);
     }
    }
   void safeseq() 
    {
     int sseq[10],ss=0,chk=0,chki=0;
     for(j=0;j&lt;m;j++)
       work[j]=avail[j];//initialise work=available
     for(i=0;i&lt;n;i++)
       p[i].flag=0;//initialise finish[i]=false for i=0,1,2...
     while(count!=n)
     {
     for(i=0;i&lt;n;i++)  
           {      
             chk=0;
             for(j=0;j&lt;m;j++)
             {
              if(p[i].flag==0)
              {
               if(need[i][j]&lt;=work[j])
               chk++;
              }
              if(chk==m)
              {
               for(j=0;j&lt;m;j++)
               {
                work[j]=work[j]+all[i][j];
                p[i].flag=1;
               }
              sseq[ss]=i;
              ss++;
              count++;
              }
             }
            }
     }
    for(i=0;i&lt;n;i++)
     {
      if(p[i].flag==1)
      chki++;
     }
     if(chki>=n)
     {
      printf("\n System is in safe state");
      for(i=0;i&lt;n;i++)
      printf("%d",sseq[i]);
     }
     else
     printf("\nsystem is not safe");
    }
   void request()
    {
     int processreq;
     printf("\n Enter the process process that is requesting:");
     scanf("%d",&processreq);
     printf("\n enter the reqested array:");
     for(i=0;i&lt;m;i++)
      scanf("%d",&req[i]);
     for(j=0;j&lt;m;j++)
     {
       if(req[j]&lt;=need[processreq][j])    
       {
          if(req[j]&lt;=avail[j])
           {
            avail[j]=avail[j]-req[j];
            all[processreq][j]=all[processreq][j]+req[j];
            need[processreq][j]=need[processreq][j]-req[j];
            printf("avail:%d",avail[j]);        
           }
       printf("\tneed: %d\n",need[processreq][j]);
       }
       else
       {
        printf("\n Process is not in safe state and hence request cannot be granted");
        exit(0);
       }
      }
      printf("\nrequest can be granted");
     }
</pre>
       
   void print()
    <pre>{
    printf("no. of processes=%d",n);
  
    printf("no. of resources=%d",m);
 
    printf("\npid\t max \t allocated \t need");
     for(i=0;i&lt;n;i++)
     {
       printf("\n%d\t",i);
       for(j=0;j&lt;m;j++) printf(" %d ",max[i][j]); printf("\t");
       for(j=0;j&lt;m;j++) printf(" %d ",all[i][j]); printf("\t");
       for(j=0;j&lt;m;j++) printf(" %d ",need[i][j]); printf("\t");
     }
     printf("\n Available");
     for(i=0;i&lt;m;i++)
     printf("%d ",avail[i]);
    }

 <pre>int main()
    {
     int ch;
     do
     {
      printf("\n menu:");
      printf("\n 1.Input:");
      printf("\n 2.Safe Seq:");
      printf("\n 3.Request:");
      printf("\n 4.Print:");
      printf("\n 5.exit:");
      printf("\n Ent choice");
      scanf("%d",&ch);
      switch(ch)
      {
       case 1: input();
               break;
       case 2: safeseq();
               break;
       case 3: request();
               break;
       case 4: print();
               break;
       case 5: break;
      }
     }while(ch!=n);
     return 0;
    }
</pre>
###Output:
<pre>
$ cc 12.c
$ ./a.out

 menu:
 1.Input:
 2.Safe Seq:
 3.Request:
 4.Print:
 5.exit:
 Ent choice1
</pre>
 Enter total num of processes:5
process:-0
process:-1
process:-2
process:-3
process:-4
</pre>
<pre>
 Enter the number of resources:3
 Enter allocation matrix:0 1 0
2 0 0 
3 0 2
2 1 1
0 0 2
 Enter max matrix:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
  need matrix:743
122
600
011
431
</pre>
<pre>
 Enter Available3 3 2
</pre>
<pre>
 menu:
 1.Input:
 2.Safe Seq:
 3.Request:
 4.Print:
 5.exit:
 Ent choice4
no. of processes=5no. of resources=3
pid	 max 	 allocated 	 need
0	 7  5  3 	 0  1  0 	 7  4  3 	
1	 3  2  2 	 2  0  0 	 1  2  2 	
2	 9  0  2 	 3  0  2 	 6  0  0 	
3	 2  2  2 	 2  1  1 	 0  1  1 	
4	 4  3  3 	 0  0  2 	 4  3  1 	
 Available3 3 2 
 menu:
 1.Input:
 2.Safe Seq:
 3.Request:
 4.Print:
 5.exit:
 Ent choice2
 System is in safe state13402
</pre>
<pre>
 menu:
 1.Input:
 2.Safe Seq:
 3.Request:
 4.Print:
 5.exit:
 Ent choice3
</pre>
<pre>
 Enter the process process that is requesting:1
enter the reqested array:1 0 2
avail:2	need: 0
avail:3	need: 2
avail:0	need: 0
request can be granted
</pre>
<pre>
 menu:
 1.Input:
 2.Safe Seq:
 3.Request:
 4.Print:
 5.exit:
 Ent choice3
</pre>
<pre>
 Enter the process process that is requesting:2
enter the reqested array:2 2 3
avail:0	need: 4
 Process is not in safe state and hence request cannot be granted
</pre>

##OR
###CODE 2:
<pre>
 #include&lt;stdio.h&gt;
struct process
{
int all[6],max[6],need[6],finished,request[6];
}p[10];
int avail[6],sseq[10],ss=0,check1=0,check2=0,n,pid,work[6];
int nor,nori;
int main()
{
int safeseq(void);
int ch,i=0,j=0,k,pid,ch1;
int violationcheck=0,waitcheck=0;
do
{
printf("\n\n\t 1. Input");
printf("\n\n\t 2. New Request");
printf("\n\n\t 3. Safe State or Not");
printf("\n\n\t 4. print");
printf("\n\n\t 5. Exit");
printf("\n\n\t Enter ur choice :");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\n\n\t Enter number of processes : ");
scanf("%d",&n);
printf("\n\n\t Enter the Number of Resources : ");
scanf("%d",&nor);
printf("\n\n\t Enter the Available Resouces : ");
for(j=0;j&lt;n;j++)
{
for(k=0;k&lt;nor;k++)
{
if(j==0)
{
printf("\n\n\t For Resource type %d : ",k);
scanf("%d",&avail[k]);
}
p[j].max[k]=0;
p[j].all[k]=0;
p[j].need[k]=0;
p[j].finished=0;
p[j].request[k]=0;
}
}
for(i=0;i&lt;n;i++)
{
printf("\n\n\t Enter Max and Allocated resources for P %d : ",i);
 for(j=0;j&lt;nor;j++)
{
printf("\n\n\t Enter the Max of resource %d : ",j);
scanf("%d",&p[i].max[j]);
printf("\n\n\t Allocation of resource %d    :",j);
scanf("%d",&p[i].all[j]);
if(p[i].all[j]&gt;p[i].max[j])
{
printf("\n\n\t Allocation should be less &lt; or == max");
j--;
}
else
p[i].need[j]=p[i].max[j]-p[i].all[j];
avail[j]=avail[j]-p[i].all[j];
}
}
break;
case 2:
violationcheck=0;
waitcheck=0;
printf("\n\n\t Requesting process id :");
scanf("%d",&pid);
for(j=0;j&lt;nor;j++)
{
printf("\n\n\t Number of Request for resource %d :",j);
  scanf("%d",&p[pid].request[j]);
if(p[pid].request[j]&gt;p[pid].need[j])
violationcheck=1;
if(p[pid].request[j]&gt;avail[j])
waitcheck=1;
}
if (violationcheck==1)
printf("\n\n\t The Process Exceeds it's Max Need: Terminated");
else if(waitcheck==1)
printf("\n\n\t Lack of Resourcess : Process State - Wait");
else
{
for(j=0;j&lt;nor;j++)
{
avail[j]=avail[j]-p[pid].request[j];
p[pid].all[j]=p[pid].all[j]+p[pid].request[j];
p[pid].need[j]=p[pid].need[j]-p[pid].request[j];
}
ch1=safeseq();
if(ch1==0)
{
for(j=0;j&lt;nor;j++)
{
avail[j]=avail[j]+p[pid].request[j];
p[pid].all[j]=p[pid].all[j]-p[pid].request[j];
p[pid].need[j]=p[pid].need[j]+p[pid].request[j];
}
}
else if(ch1==1)
printf("\n\n\t Request Committed ");
}
break;
case 3:
if(safeseq()==1)
printf("\n\n\t The System is in safe state ");
else
printf("\n\n\t The System is Not in safe state ");
break;
case 4:
printf("\n\n\t Number of processes : %d",n);
printf("\n\n\t Number of Resources : %d",nor);
printf("\n\n\t Pid \t   Max \t   Allocated \t Need ");
for(i=0;i&lt;n;i++)
{
printf("\n\n\t  P%d : ",i);
for(j=0;j&lt;nor;j++)
printf(" %d",p[i].max[j]);
printf("\t");
for(j=0;j&lt;nor;j++)
printf("%d",p[i].all[j]);
printf("\t");
for(j=0;j&lt;nor;j++)
printf("%d",p[i].need[j]);
}
printf("\n\n\t Available :");
for(i=0;i&lt;nor;i++)
printf("%d",avail[i]);
break;
case 5:
break;
}
}while(ch!=5);
}
int safeseq()
{
int tj,tk,i,j,k;
ss=0;
for(j=0;j&lt;nor;j++)
work[j]=avail[j];
for(j=0;j&lt;n;j++)
p[j].finished=0;
for( tk=0;tk&lt;nor;tk++)
{
for(j=0;j&lt;n;j++)
{
if(p[j].finished==0)
{
check1=0;
for(k=0;k&lt;nor;k++)
if(p[j].need[k]&lt;=work[k])
check1++;
if(check1==nor)
{
for(k=0;k&lt;nor;k++)
{
work[k]=work[k]+p[j].all[k];
p[j].finished=1;
}
sseq[ss]=j;
ss++;
}
}
}
}
check2=0;
for(i=0;i&lt;n;i++)
if(p[i].finished==1)
check2++;
printf("\n\n\t");
if(check2&gt;=n)
{
printf("\n\n\t The system is in safe state");
for( tj=0;tj&lt;n;tj++)
printf("P%d,",sseq[tj]);
return 1;
}
else
printf("\n\n\t The system is Not in safe state");
return 0;
}
</pre>
###Output:
<pre>
$cc 12.c
$./a.out
	 1. Input
	 2. New Request
	 3. Safe State or Not
	 4. print
	 5. Exit
	 Enter ur choice :1
</pre>
<pre>	
 	 Enter number of processes : 5
	 Enter the Number of Resources : 3
	 Enter the Available Resouces : 
 For Resource type 0 : 10
	 For Resource type 1 : 5
 For Resource type 2 : 7
</pre>
<pre>
	 Enter Max and Allocated resources for P 0 : 
	 Enter the Max of resource 0 : 7
	 Allocation of resource 0    :0
	 Enter the Max of resource 1 : 5
	 Allocation of resource 1    :1
	 Enter the Max of resource 2 : 3
	 Allocation of resource 2    :0
	 Enter Max and Allocated resources for P 1 : 
	 Enter the Max of resource 0 : 3
	 Allocation of resource 0    :2
	 Enter the Max of resource 1 : 2
	 Allocation of resource 1    :0
	 Enter the Max of resource 2 : 2
	 Allocation of resource 2    :0
	 Enter Max and Allocated resources for P 2 : 
	 Enter the Max of resource 0 : 9
	 Allocation of resource 0    :3
	 Enter the Max of resource 1 : 0
	 Allocation of resource 1    :0
          Enter the Max of resource 2 : 2
	 Allocation of resource 2    :2
	 Enter Max and Allocated resources for P 3 : 
	 Enter the Max of resource 0 : 2
	 Allocation of resource 0    :2
	 Enter the Max of resource 1 : 2
          Allocation of resource 1    :1
	 Enter the Max of resource 2 : 2
	 Allocation of resource 2    :1
	 Enter Max and Allocated resources for P 4 : 
	 Enter the Max of resource 0 : 4
	 Allocation of resource 0    :0
	 Enter the Max of resource 1 : 3
	 Allocation of resource 1    :0
	 Enter the Max of resource 2 : 3
	 Allocation of resource 2    :2
	 1. Input
	 2. New Request
	 3. Safe State or Not
	 4. print
	 5. Exit
	 Enter ur choice :3
	 The system is in safe stateP1,P3,P4,P0,P2,
	 The System is in safe state 
	 1. Input
	 2. New Request
	 3. Safe State or Not
	 4. print
	 5. Exit
	 Enter ur choice :2
	 Requesting process id :1
	 Number of Request for resource 0 :1
	 Number of Request for resource 1 :0
	 Number of Request for resource 2 :2
          The system is in safe stateP1,P3,P4,P0,P2
 Request Committed 
	 1. Input
	 2. New Request
	 3. Safe State or Not
	 4. print
	 5. Exit
	 Enter ur choice :2
	 Requesting process id :2
	 Number of Request for resource 0 :2
	 Number of Request for resource 1 :2
	 Number of Request for resource 2 :3
	 The Process Exceeds it�s Max Need: Terminated
</pre>
