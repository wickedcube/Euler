#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdbool.h>

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

void main(){

	int countmax = 0, a, b;

	for (int i = 1; i < 1000; i++){
		for (int j = 1; j < 1000; j++){

			bool foundcomp = false;
			int n = 0, count = 0;

			int d = i*i - 4 * j;

			while (!foundcomp && IsPrime(j) && d<0){

				int quadex = n*n - i*n + j;

				if (IsPrime(quadex)){
					count++;
					n++;
				}
				else
					foundcomp = true;

				if (count > countmax){
					countmax = count;
					a = i; b = j;
				}
			}
		}
	}

	printf("%d %d %d", countmax, a, b);

	_getch();
}