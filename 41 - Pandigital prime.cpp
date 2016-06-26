#include<iostream>
#include<conio.h>

using namespace std;

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


// Improved pandigital to n
bool IsPandigital(long number,int n){

	int arr[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, amax = 0, amin;
	while (number > 0){

		int rem = number % 10;

		arr[rem]--;

		number = number / 10;
	}

	for (int i = 1; i < n+1; i++){

		if (arr[i] < 0)
			return false;

		if (i == 1)
			amin = arr[i];

		if (arr[i]>amax)
			amax = arr[i];
	}

	if (amax == 0 && amin == 0)
		return true;
	else
		return false;
}



void main(){

	for (long i = 1000000; i < 9999999; i++){
		
		if (IsPrime(i) && IsPandigital(i, 7))
			cout << i<<"\n";
	}

	getchar();
}