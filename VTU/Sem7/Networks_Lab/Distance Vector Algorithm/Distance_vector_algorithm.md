## Aim: 
### Write a C program for Distance Vector Algorithm to find a suitable path for transmission.

## Theory
> Routing algorithm is a part of network layer software which is responsible for deciding which
output line an incoming packet should be transmitted on. If the subnet uses datagram internally, this
decision must be made anew for every arriving data packet since the best route may have changed
since last time. If the subnet uses virtual circuits internally, routing decisions are made only when a
new established route is being set up. The latter case is sometimes called session routing, because a
rout remains in force for an entire user session (e.g., login session at a terminal or a file).
Routing algorithms can be grouped into two major classes: adaptive and non-adaptive.

> Nonadaptive algorithms do not base their routing decisions on measurement or estimates of current
traffic and topology. Instead, the choice of route to use to get from I to J (for all I and J) is compute in advance, offline, and downloaded to the routers when the network ids booted. This procedure is sometime called static routing.

>Adaptive algorithms, in contrast, change their routing decisions to reflect changes in the
topology, and usually the traffic as well. Adaptive algorithms differ in where they get information
(e.g., locally, from adjacent routers, or from all routers), when they change the routes (e.g., every ∆T sec, when the load changes, or when the topology changes), and what metric is used for optimization (e.g., distance, number of hops, or estimated transit time).

>Two algorithms in particular, distance vector routing and link state routing are the most popular.
Distance vector routing algorithms operate by having each router maintain a table (i.e., vector)
giving the best known distance to each destination and which line to get there. These tables are
updated by exchanging information with the neighbour’s.

>The distance vector routing algorithm is sometimes called by other names, including the distributed Bellman-Ford routing algorithm and the Ford-Fulkerson algorithm, after the researchers
who developed it (Bellman, 1957; and Ford and Fulkerson, 1962). 

>In distance vector routing, each router maintains a routing table indexed by, and containing one
entry for, each router in subnet. This entry contains two parts: the preferred outgoing line to use for that destination, and an estimate of the time or distance to that destination. The metric used might be number of hops, time delay in milliseconds, total number of packets queued along the path, or something similar.

>The router is assumed to know the “distance” to each of its neighbour. If the metric is hops, the
distance is just one hop. If the metric is queue length, the router simply examines each queue. If the metric is delay, the router can measure it directly with special ECHO packets that the receiver just time stamps and sends back as fast as possible.

## Algorithm: 
1. Start.
2. Assume that each node knows the cost of the link to its directly connected neighbors. A link that is down is assigned an infinite cost.
3. Each node knows its own table. Iteratively, find out the shortest path between two nodes(for every node). 
4. Update the tables as changes are made.
5. Display the tables with the updated routes.
6. Stop. 

## Code:
	#include<stdio.h>
	int n, e, dist[20][20], graph[20][20];
	void initialize()
	{       
	  int i, j;
	  for(i = 1; I <= 20; i++)
	   for(j = 1;  j <= 20;  j++)
	     dist[i][j] = graph[i][j] = 0;
	}

	void getgraph()
	{
	  int i, strt, end;
	  printf("Enter no. of Routers & Edges in the graph:");
	  scanf("%d%d", &n, &e);
             while(e-- > 0)
             {
	          printf("Enter start router --> end router\n");
              scanf("%d%d",&strt, &end);
              graph[strt][end] = graph[end][strt] = 1;
	         } 
}

	void gettable(int src)
	{       
	  int i, j;
	  printf("\nEnter details of Source router %d\n",src);
	  printf("Enter distance from Source router to Adjacent routers...\n");
             for(i=1; i <= n; i++)
	    	  if(graph[src][i] == 1)
                 printf("%d to %d :", src, i),
                 scanf("%d", &dist[src][i]);
        	 printf("\nEnter the routing table details of Adjacent routers...\n");
	 		 for(i = 1; i <= n; i++)
                if(graph[src][i] == 1)
                {
	      		  printf("Enter the details of routing table of router %d\n", i);
                        for(j = 1; j <= n; j++)
                        {
		   				  if(i == j)
						   continue;
	   					  printf("Distance from router %d to %d :", i, j);
	  					  scanf("%d", &dist[i][j]);
						}
				 }
}

	void process(int src, int dest)
	{       
	  int min=32765, i, delay, via;
	  for(i = 1; i <= n; i++)
  	   if(graph[src][i] == 1)
   	   {
	    delay = dist[src][i] + dist[i][dest];
	    if(delay < min)
	     min = delay, via = i;
	   }
	  printf("\nSuitable path from source router %d to destination router %d is through router %d with delay %d units\n",src, dest, via, min);
	}

	main()
	{
	  int src, dest;
	  initialize();
	  getgraph();
	  printf("\nEnter the Source & Destination router\n");
	  scanf("%d%d",&src, &dest);
	  gettable(src);
	  process(src, dest);
	}






 