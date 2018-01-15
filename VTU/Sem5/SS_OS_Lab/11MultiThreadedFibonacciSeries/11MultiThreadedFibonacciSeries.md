##AIM:
 Using OpenMP, Design, develop and run a multi-threaded program to generate and print Fibonacci Series. One thread has to generate the  numbers up to the specified limit and another thread has to print them. Ensure proper synchronization.

###DESCRIPTION:
In mathematics, the Fibonacci numbers or Fibonacci series or Fibonacci sequence are the numbers in the following integer sequence:0 1 1 2 3 5 8 13 21 34 55 . . . . . . . 
###FORMULA:
F<sub>n</sub> = F<sub>(n-1)</sub> + F<sub>(n-2)</sub>
###CODE:
`#`include&lt;stdio.h&gt;

`#`include&lt;omp.h&gt;

int main()
{
<pre>   int n,a[100],i;
   omp_set_num_threads(2);
   printf("enter the no of terms of fibonacci series which have to be generated\n");
   scanf("%d",&n);
   a[0]=0;
   a[1]=1;
   #pragma omp parallel
   {
    	  #pragma omp single
    	  for(i=2;i&lt;n;i++)
    	  {
           	a[i]=a[i-2]+a[i-1];
     		printf("id of thread involved in the computation of fib no %d is=%d\n",i+1,omp_get_thread_num());
   	  }
          #pragma omp barrier
          #pragma omp single
    	 {
       		printf("the elements of fib series are\n");
       		for(i=0;i&lt;n;i++)
       		printf("%d,id of the thread displaying this no is =  %d\n",a[i],omp_get_thread_num());
   	 }
   }
   return 0;
}
</pre>
###OUTPUT
<pre>
cc -fopenmp 11.c 
./a.out
enter the no of terms of fibonacci series which have to be generated
5
id of thread involved in thes computation of fib no 3 is=0
id of thread involved in the computation of fib no 4 is=0
id of thread involved in the computation of fib no 5 is=0
the elements of fib series are
0,id of the thread displaying this no is =  1
1,id of the thread displaying this no is =  1
1,id of the thread displaying this no is =  1
2,id of the thread displaying this no is =  1
3,id of the thread displaying this no is =  1
</pre>

