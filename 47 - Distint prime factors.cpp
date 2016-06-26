#include<iostream>
#include<math.h>
#include<conio.h>
#include<string>
#include<fstream>
#include<algorithm>

using namespace std;

int primrarr[9000001];

bool IsPrime(unsigned long long n){

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
		long long r = floor(sqrt(n));
		long long f = 5;

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


int countdistinctprimes(unsigned long long num){


	int primeList[40], k = 0,l = 0;

	while (num > 0 && primrarr[k] <= num){

		int prime = primrarr[k];

		if (num % prime == 0)
		{
			if (l == 0){
				primeList[l] = prime;
				l++;
			}
			else if (primeList[l-1] != prime){
				primeList[l] = prime;
				l++;
			}
			num = num / prime;
		}
		else
		{
			k++;
		}
	}

	return l;
}


int main(){

	int k = 0;

	for (unsigned long long i = 1; i < 1000000; i++){
		if (IsPrime(i)){
			primrarr[k] = i;
			k++;
		}
	}

	for (unsigned long long i = 1; i < 1000000; i++){
		if (countdistinctprimes(i) == 4 && countdistinctprimes(i + 1) == 4 && countdistinctprimes(i + 2) == 4 && countdistinctprimes(i + 3) == 4){
			cout << i <<"\n";
		}
	}

	getchar();

	return 0;
}