#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdbool.h>

int primearr[100000], circparr[10000];

//List primes
bool IsPrime(long n){

	if (n == 1)
		return false;
	else if (n < 4)
		return true;
	else if (n % 2 == 0)
		return false;
	else if (n < 9)
		return true;
	else if (n % 3 == 0)
		return false;
	else
	{
		long r = floor(sqrt(n));
		int f = 5;

		while (f <= r)
		{
			if (n % f == 0)
				return false;
			if (n % (f + 2) == 0)
				return false;

			f = f + 6;
		}
		return true;
	}
}

//Rotate for no of digits-1 times check if all are prime
bool IsCircPrime(long num){

	int noDig = floor(log10(num)), r = 0,orgn = num;

	while (r < noDig)
	{
		num = num % (int)(pow(10, noDig)) * 10 + num / (int)(pow(10, noDig));
		if (!IsPrime(num))
			return false;
		r++;
	}

	return true;
}


void main(){

	int k = 0, l = 0;
	for (long i = 1; i < 1000000; i++)
	{
		if (IsPrime(i)){
			primearr[k] = i;
			k++;
		}
	}

	for (long i = 0; i < k; i++)
	{
		if (IsCircPrime(primearr[i])){
			printf("%d \t", primearr[i]);
			circparr[l] = primearr[i];
			l++;
		}
	}

	printf("%d", l);

	_getch();
}