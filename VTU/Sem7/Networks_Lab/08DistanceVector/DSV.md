## Aim: 
### Write a program for distance vector algorithm to find suitable path for transmission.

## Theory
> Routing algorithm is a part of network layer software which is responsible for deciding which
output line an incoming packet should be transmitted on. If the subnet uses datagram internally, this
decision must be made anew for every arriving data packet since the best route may have changed
since last time. If the subnet uses virtual circuits internally, routing decisions are made only when a
new established route is being set up. The latter case is sometimes called session routing, because a
rout remains in force for an entire user session (e.g., login session at a terminal or a file).

> Routing algorithms can be grouped into two major classes: adaptive and non-adaptive.
Nonadaptive algorithms do not base their routing decisions on measurement or estimates of current
traffic and topology. Instead, the choice of route to use to get from I to J (for all I and J) is compute in
advance, offline, and downloaded to the routers when the network ids booted. This procedure is
sometime called static routing.

> Adaptive algorithms, in contrast, change their routing decisions to reflect changes in the
topology, and usually the traffic as well. Adaptive algorithms differ in where they get information
(e.g., locally, from adjacent routers, or from all routers), when they change the routes, and what metric is used for
optimization (e.g., distance, number of hops, or estimated transit time).

> Two algorithms in particular, distance vector routing and link state routing are the most popular.
Distance vector routing algorithms operate by having each router maintain a table (i.e., vector)
giving the best known distance to each destination and which line to get there. These tables are
updated by exchanging information with the neighbour's.
> The distance vector routing algorithm is sometimes called by other names, including the
distributed Bellman-Ford routing algorithm and the Ford-Fulkerson algorithm, after the researchers
who developed it (Bellman, 1957; and Ford and Fulkerson, 1962). It was the original ARPANET
routing algorithm and was also used in the Internet under the RIP and in early versions of DEC net
and Novell'Ps IPX. AppleTalk and Cisco routers use improved distance vector protocols.

> In distance vector routing, each router maintains a routing table indexed by, and containing one
entry for, each router in subnet. This entry contains two parts: the preferred outgoing line to use for
that destination, and an estimate of the time or distance to that destination. The metric used might
be number of hops, time delay in milliseconds, total number of packets queued along the path, or
something similar.

> The router is assumed to know the "distance" to each of its neighbour. If the metric is hops, the
distance is just one hop. If the metric is queue length, the router simply examines each queue. If the
metric is delay, the router can measure it directly with special ECHO packets that the receiver just
time stamps and sends back as fast as possible.

## Algorithm:
1. Start
2. By convention, the distance of the node to itself is assigned to zero and when a node is unreachable the distance is accepted as 999.
3. Accept the input distance matrix from the user (*dm[][]*) that represents the distance between each node in the network.
4. Store the distance between nodes in a suitable varible.
5. Calculate the minimum distance between two nodes by iterating.
    * If the distance between two nodes is larger than the calculated alternate available path, replace the existing distance with the calculated distaance. 
6. Print the shortest path calculated.
7. Stop.

## Code: filename.cpp

    #include<iostream> 
    #include<stdio.h>
    using namespace std;
    struct node // C1: define structure
    {
        int dist[20];
        int from[20];
     }rt[10]; // C2: structure variable
    int main()
    {
        int dm[20][20]; 
        int i, j, k, n, src, dest, flag=0;
        cout<<"Enter no of nodes:"<<endl;
        cin>>n;
        cout<<"Enter distance matrix:"<<endl;
        for(i=0;i<n;i++) // C3: input matrix
            for(j=0;j<n;j++)
            {
                cin>>dm[i][j];
                dm[i][i]=0;
                rt[i].dist[j]=dm[i][j]; // C4: node allocations
                rt[i].from[j]=j;
            }
        do
        {
            flag=0;
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    for(k=0;k<n;k++)
                        if((rt[i].dist[j])>(rt[i].dist[k]+rt[k].dist[j])) // C5: check & calculate minumum distance between each node
                        {
                            rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                            rt[i].from[j]=k;
                            flag=1;
                        }
        }while(flagt!=0);
        for(i=0;i<n;i++) // C6: Display the shortest path calculated between the nodes
        {
            cout<<"Router info for router "<<i+1<<endl;
            printf("Dest\tNext Hop\tDist\n");
            for(j=0;j<n;j++)
                printf("%d\t%d\t\t%d\n",j+1,rt[i].from[j]+1,rt[i].dist[j]);
        }
    return 0;
    }

## Output:
*Commands for execution:-*

* Open a terminal.
* Change directory to the file location.
* Run g++ *filename.cpp* 
* If there are no errors, run ./a.out

*Screenshots:-*

![ScreenShot of Output](dsv.png)
