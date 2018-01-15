## Lab Programs list for Networks Lab as specified by VTU for 7th Semester students:

### PART A - Simulation Exercises

The following experiments shall be conducted using either NS228/OPNET or 
any other suitable simulator.

1. Simulate a three nodes point - to - point network with duplex links 
between them. Set the queue size and vary the bandwidth and find the 
number of packets dropped.

2. Simulate a four node point-to-point network with the links connected as
follows:
n0 - n2, n1 - n2 and n2 - n3. Apply TCP agent between n0-n3 and UDP 
between n1-n3. Apply relevant applications over TCP and UDP agents 
changing the parameter and determine the number of packets sent by TCP/UDP.

3. Simulate the transmission of ping messages over a network topology 
consisting of 6 nodes and find the number of packets dropped due to 
congestion.

4. Simulate an Ethernet LAN using n nodes (6-10), change error rate and 
data rate and compare throughput.

5. Simulate an Ethernet LAN using n nodes and set multiple traffic nodes 
and plot congestion window for different source / destination.

6. Simulate simple ESS and with transmitting nodes in wire-less LAN by 
simulation and determine the performance with respect to transmission of
packets.

### PART-B

Implement the following in C/C++:

<!-- Currently this numbering will start again from 1 as markdown doesnt support beginning numbering from some arbitary number.-->
7. Write a program for error detecting code using CRC-CCITT (16- bits).

8. Write a program for distance vector algorithm to find suitable path for
transmission.

9. Using TCP/IP sockets, write a client - server program to make the client
send the file name and to make the server send back the contents of the
requested file if present.

10. Implement the above program using as message queues or FIFOs as IPC
channels.

11. Write a program for simple RSA algorithm to encrypt and decrypt the 
data.

12. Write a program for congestion control using leaky bucket algorithm.
