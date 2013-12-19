#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define npackets 2

int main(){
    int orate, bsize, i, clk, psz, packetsrm = 0,nextpacket;
    int npacketsrm;

    orate = 5; // 5 kbps
    bsize = 50; // 5kb
    // Alternatively take orate and bsize as inputs from user

    int packets[npackets];

    // Initialising random number generator rand()
    srand(time(NULL));
    
    // Generating packets of random sizes
    for(i = 0; i < npackets; ++i){
        packets[i] = rand() % 10;
    }

    // Processing the packets one by one
    for(i = 0; i < npackets; ++i){
        
        // Checking is the bucket is full...
        if((packets[i] + packetsrm) > bsize){

            // ...because of large packet size...
            if(packets[i] > bsize){
                printf("Incoming packet is bigger than the bucket\n");
                break;
            }

            // ...or not enough space in the bucket.
            else {
                printf("Bucket is full! Dropping this packet and trying the next\n");
            }
        }
        else{

            // Number of packets remaining. This variable is not used anywhere though
            npacketsrm = 4 - i;

            // Storing size of the current packet temporarily
            psz = packets[i];

            // The new packet has to be added to the bucket
            packetsrm += psz;
            
            printf("Incoming packet remain size: %d", psz);
            printf("\n\n=============================\n");
            printf("\nPacket size remaining initially: %d", packetsrm);
            
            // Arrival of the next packet - randomised and less than 10
            nextpacket = rand() % 10;

           printf("\nNext packet arrives after %d seconds\n", nextpacket);

           // A loop to send packets every second
           for(clk = 0; clk < nextpacket && packetsrm > 0; ++clk){
                
                printf("Time left: %d\nSending...", nextpacket - clk);
                sleep(1); // Simulates the time taken to send the packet
                printf("Sent!\n");

                if(packetsrm <= orate){
                    // Finishing the last few bytes left in the bucket
                    packetsrm = 0;
                }
                else{
                    // Removing the packet sent during this second
                    packetsrm -= orate;
                }
                
                printf("Bytes remaining: %d\n", packetsrm);
            }
            
            if(nextpacket - clk > 0){
                printf("Time left before next packet arrives %d\n", nextpacket - clk);
            }
        }
    }
    return  0;
}
    
