#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

int primearr[1000000];

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


void main(){

	int k = 0;
	for (int i = 1; i < 1000001; i++){
		if (IsPrime(i)){
			primearr[k] = i;
			k++;
		}
	}

	int cmax = 0,pmax;

	for (int i = 0; i < k; i++){

		unsigned long long sum = 0;
		int count=0;
		for (int j = i; j < k; j++){
		
			sum += primearr[j];
			count++;

			if (count > cmax && IsPrime(sum) && sum < 1000000){
				cmax = count;
				pmax = sum;
				cout << i << "\t" << j << "\t" << sum << "\t" << count << "\n";
			}
		}
	}


	cout << pmax << "\t" << cmax << "\n";

	getchar();
}