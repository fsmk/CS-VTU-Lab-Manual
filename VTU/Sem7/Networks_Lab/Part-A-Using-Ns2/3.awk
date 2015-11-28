BEGIN{
#include<stdio.h>
count=0;
}

{
if($1=="d")
count++
}
END{
printf("total no of pack dropd due to cngsn : %d",count)
}

