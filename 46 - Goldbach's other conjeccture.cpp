#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

int primearr[100000];

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


bool chkGoldbach(int number){

	int k = 0;
	while (primearr[k] <= number){

		int diff = (number - primearr[k]) / 2;

		int sqrtdiff = sqrt(diff);

		k++;

		if (sqrtdiff*sqrtdiff == diff)
			return true;
	}

	return false;
}

void main(){

	int k = 0;
	for (int i = 2; i < 100000; i++){
		if (IsPrime(i)){
			primearr[k] = i;
			k++;
		}
	}

	for (int i = 1; i < 50000; i++){

		int o = 2 * i + 1;

		if (!chkGoldbach(o)){
			cout << o << "\n";
		}
	}


	getchar();
}