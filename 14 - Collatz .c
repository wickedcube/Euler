#include<stdio.h>
#include<stdlib.h>

int collatz[1000000] = {0,0,1};


long long fcollatz(long long n){

	if (n < 1000000){
		if (collatz[n] == 0)
		{
			if (n % 2 == 0)
			{
				long long temp = fcollatz(n / 2);
				collatz[n] = temp + 1;
				return temp + 1;
			}
			else
			{
				long long temp = fcollatz(3 * n + 1);
				collatz[n] = temp + 1;
				return temp + 1;
			}
		}
		else
			return collatz[n];
	}
	else
	{
		if (n % 2 == 0)
		{
			long long temp = fcollatz(n / 2);
			return temp + 1;
		}
		else
		{
			long long temp = fcollatz(3 * n + 1);
			return temp + 1;
		}
	}

}


void main(){

	long long max = 0,num = 3,maxn;

	while (num < 1000000)
	{

		long long val = fcollatz(num);

		if (val>max)
		{
			max = val;
			maxn = num;
		}
			
		num++;
	}

	printf("%d", maxn);

	getch();

}