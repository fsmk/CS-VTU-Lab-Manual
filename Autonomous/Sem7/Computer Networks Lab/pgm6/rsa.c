/* RSA algorithm to generate a public and a private key and encrypt and decrypt the message text*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
unsigned int c, m, pt[50], ct[50], msglength;
char message[50];

int mult(unsigned int plaintext, unsigned int key, unsigned int n){
	unsigned long int k = 1;
	int j;
	for (j = 1; j <= key; j++)
		k = (k * plaintext) % n;
	return (unsigned int) k;
}

int isPrime(int n){
	int i, lim;
	lim = n / 2;
	for(i = 2; i <= lim; i++)	{
		if((n % i) == 0)		{
			return 0; // Not prime
		}
	}
	return 1; //Prime
}

int gcd (int a, int b){
	if(b == 0) {
		return 1;
	}
	while(b){
		int rem = a % b;
		a = b;
		b = rem;
	}
	return a;
}

int main ()
{
	int i, j; // for loop
	int p, q; //The prime numbers
	int d, e; //d -> private key e -> public key
	int z, n; //n  = p * q and z = (p-1) * (q-1)
	
	printf("Enter two prime numbers (such that their product is atleast more than 150): ");
	scanf("%d %d", &p, &q);
	// p = 11; q = 23;

	if((isPrime(p) == 0) || (isPrime(q) == 0)){
		printf("Invalid Numbers !! Please Enter Prime Numbers \n");
		return 1;
	}

	if(p == q){
		printf("Two Prime Numbers Must be Different \n");
		return 1;
	}

	n = p * q;
	z = (p - 1) * (q - 1);

	//--- Calculating e ---//
	for(i = 2; i < z; i++) {
		if((gcd(z, i)) == 1){
			e = i;
			printf("e = %d\n", e);
			break;
		}
	}

	//--- Calculating d ---/
	for(j = n; j >= 1; j--){
		if(((e * j) % z) == 1){
			d = j; //private key
			printf("d = %d\n", d);
			break;
		}
	}

	printf("Enter The Text To Encrypt \n");
	scanf("%s", message);

	msglength = strlen(message);
	for(i = 0; i < msglength; i++)
	pt[i] = message[i];

	for(i = 0; i < msglength; i++){
		ct[i] = mult(pt[i], e, n);
	}

	printf("The Encrypted Text is \n");
	for(i = 0;i < msglength; i++)
	printf("%d ", ct[i]);

	printf("\nThe Decrypted Text is \n");
	for(i = 0;i < msglength; i++){
		pt[i] = mult(ct[i], d, n);
		printf("%c", pt[i]);
	}

	printf("\n");
	return 0 ; 
}