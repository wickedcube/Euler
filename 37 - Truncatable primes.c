#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdbool.h>

int primearr[100000], truncparr[20];

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

//Remove one digit at a time
bool IsTruncPrime(long num){

	int noD = log10(num), r = 0;

	while (r < noD)
	{
		int rem = num % (int)(pow(10, noD - r));
		if (!IsPrime(rem))
			return false;
		r++;
	}

	r = 1;

	while (r < noD + 1)
	{
		int rem = num / (int)(pow(10,r));
		if (!IsPrime(rem))
			return false;
		r++;
	}

	return true;
}


void main(){

	int k = 0, l = 0, sum = 0;
	for (long i = 1; i < 1000000; i++)
	{
		if (IsPrime(i)){
			primearr[k] = i;
			k++;
		}
	}

	for (long i = 5; i < k; i++)
	{
		if (IsTruncPrime(primearr[i])){
			printf("%d \t", primearr[i]);
			truncparr[l] = primearr[i];
			sum += primearr[i];
			l++;
		}
	}

	printf("%d", sum);

	_getch();
}