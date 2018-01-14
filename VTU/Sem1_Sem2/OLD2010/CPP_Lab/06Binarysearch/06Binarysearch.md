## Aim:
## Design, develop and execute a program in C to input N integer numbers in ascending order into a single dimension array, and then to perform a binary search for a given key integer number and report success or failure in the form of a suitable message.

## Summary:
>Binary search or half-interval search algorithm finds the position of a specified input value (the search "key") within an array sorted by key value. In each step, the algorithm compares the search key value with the key value of the middle element of the array. If the keys match, then a matching element has been found and its index, or position, is returned. Otherwise, if the search key is less than the middle element's key, then the algorithm repeats its action on the sub-array to the left of the middle element or, if the search key is greater, on the sub-array to the right. If the remaining array to be searched is empty, then the key cannot be found in the array and a special "not found" indication is returned.


>	Example: 

>	Array = 1 3 4 6 8 9 11 
>	Key = 4 	

>	Iteration1: 

>	   Find the mid element of Array , its 6 
>	   Compare key to 6. It's smaller. Repeat with Array = 1 3 4.
 
>	Iteration2: 

>	   Find the mid element , its 3 
>	   Compare key to 3. It's bigger. Repeat with Array = 4.
 
>	Iteration3: 

>	   Find mid element , its 4 
>	   Compare key to 4. It's equal. We're done, we found key. 

>	In each iteration  the length of the list we are
>	looking in gets cut in half. Therefore, the total 
>	number of iterations cannot be greater than logN.

## Algorithm:
1. Start.
2. Take the input for the size of array (n).
3. Take Input to the array in ascending order.
4. Take the input of key element to be searched(key).
5. Consider low as 0(starting bit address of given array), 
	high as n-1(last bit address of given array).
6. Until low is lesser than or equal to high, do find mid of 			array, go to step 7.
7. When key is found at mid, go to step 11 , else to step 8.
8. When key is not found at mid go to step 12. 
9. When key is found before mid, consider high as mid-1, go to 			step 6, else to step 10.
10. When key is found after mid, consider low as mid+1, go to step 6.
11. Print successful search with mid value, go to step 13.
12. Print unsuccessful search.
13. Stop.

## Program: binsearch.c
	#include<stdio.h>
	void main()
	{
		int a[20],i,low,high,mid,n,key,f=0;
	
		printf("Enter the number of elements\n");
		scanf("%d",&n);   //input for size of the array // 
		printf("Enter the elements in ascending order\n");
		for(i=0;i<n;i++)
		scanf("%d",&a[i]); //elements stored in array //
		printf("Enter the key element to be searched\n");
		 scanf("%d",&key);  // taking key element to be searched //
		low=0;  // initializing starting address of array //
		high=n-1; // initializing last bit address of array //
	
		while(low<=high) // loop executes until low=high //
		{
			mid=(low+high)/2;//computing to get mid	position //
		
			if(a[mid]==key) //executes when key is found at mid //
			{		
				f=1;
				break;
			}		

			else   
			{
				if(key<a[mid]) //executes when	key is found before the mid position //
					high=mid-1;
				else   // executes when key is found after the mid position //
					low=mid+1;

			}
		}

		if(f==1)
  			printf("Key element %d is found at position %d\n",key,mid+1);      
			//prints when key element found along with	its position//
		else
			printf("Key element %d is not found\n",key);
    		 // prints when key element not found in the array //
	}	

## Output:
Run the following commands in your terminal:<br>
###gcc binsearch.c
###./a.out

	1: Enter number of elements
   	   5
	   Enter the elements in ascending order
    	1 3 5 7 9
   	Enter the Key element to be searched
    	7
  	Key element 7 found at position 4



###gcc binsearch.c
###./a.out

	2: Enter number of elements
	    5
	   Enter the elements in ascending order
	    1 3 5 7 9
	   Enter the Key element to be searched
	    8
	  Key element 7 is not found 


