## Aim:
## Write a program for Error Detection using CRC-CCITT(16 bits)

## Description:

> The cyclic redundancy check, or CRC, is a technique for detecting     
errors in digital data, but not for making corrections when errors are detected. It is used primarily in data transmission. 

> In the CRC method, a certain number of check bits, often called a checksum, are appended to the message being transmitted. The receiver can determine whether or not the check bits agree with the data, to ascertain with a certain degree of probability whether or not an error occurred in transmission.

> If an error occurred, the receiver sends a "negative acknowledgement" (NAK) back to the sender, requesting that the message be retransmitted.
The technique is also sometimes applied to data storage devices, such as a disk drive. In this situation each block on the disk would have check bits, and the hardware might automatically initiate a reread of the block when an error is detected, or it might report the error to software. The material that follows speaks in terms of a "sender" and a "receiver" of a "message," but it should be understood that it applies to storage writing and reading as well.

> 	

## Algorithm
1. Start
2. Enter the message to be transmitted
3. Append the message with 16(since it is 16-bit CRC) 0`s (i.e. if you input 5 digit message, the appeneded message should be 21-bits.)
4. XOR appended message and transmit it.(Here, you compare with an already exisitng string such as `10001000000100001` and replace the bits the same way XOR operation works)
5. Verify the message that is received is the same as the one sent.
6. End 

## Code:

```c
#include <iostream>
#include <string.h>

using namespace std;

int crc(char *ip, char *op, char *poly, int mode)
{
	strcpy(op, ip);
	if (mode) {
		for (int i = 1; i < strlen(poly); i++)
			strcat(op, "0");
	}
	/* Perform XOR on the msg with the selected polynomial */
	for (int i = 0; i < strlen(ip); i++) {
		if (op[i] == '1') {
			for (int j = 0; j < strlen(poly); j++) {
				if (op[i + j] == poly[j])
					op[i + j] = '0';
				else
					op[i + j] = '1';
			}
		}
	}
	/* check for errors. return 0 if error detected */
	for (int i = 0; i < strlen(op); i++)
		if (op[i] == '1')
			return 0;
	return 1;
}

int main()
{
	char ip[50], op[50], recv[50];
	char poly[] = "10001000000100001";

	cout << "Enter the input message in binary"<< endl;
	cin >> ip;
	crc(ip, op, poly, 1);
	cout << "The transmitted message is: " << ip << op + strlen(ip) << endl;
	cout << "Enter the recevied message in binary" << endl;
	cin >> recv;
	if (crc(recv, op, poly, 0))
		cout << "No error in data" << endl;
	else
		cout << "Error in data transmission has occurred" << endl;

	return 0;
}
```

## Output:
*Commands for execution:-*

* Open a terminal.
* Change directory to the file location.
* Run g++ *filename.cpp* 
* If there are no errors, run ./a.out

*Screenshots:-*

![ScreenShot of output](crc.png)
