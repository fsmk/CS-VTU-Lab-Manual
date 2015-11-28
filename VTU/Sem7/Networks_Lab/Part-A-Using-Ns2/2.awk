BEGIN{
#include<stdio.h>
tcp=0;
udp=0;
}

{
if($1=="r"&&$3=="2"&&$4=="3"&&$5=="tcp")
tcp++;
if($1=="r"&&$3=="2"&&$4=="3"&&$5=="cbr")
udp++;
}
END{
printf("\n total num of pack sent by TCP : %d\n",tcp);
printf("\n total num of pack sent by UDP : %d\n",udp);
}





