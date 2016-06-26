#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

int primearr[9001];

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


bool chkpermutation(int n1, int n2){

	int arr1[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int arr2[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	while (n1 > 0){

		int rem = n1 % 10;

		arr1[rem]--;

		n1 = n1/ 10;
	}

	while (n2 > 0){

		int rem = n2 % 10;

		arr2[rem]--;

		n2 = n2 / 10;
	}

	for (int i = 0; i < 10; i++){
		if (arr1[i] != arr2[i])
			return false;
	}

	return true;

}


void main(){

	int k = 0;
	for (int i = 1000; i < 10000; i++){
		if (IsPrime(i)){
			primearr[k] = i;
			k++;
		}
	}

	for (int i = 0; i < k; i++){
		for (int j = 1; j < 5000; j++){

			int n = primearr[i];
			int n1 = primearr[i] + j;
			int n2 = primearr[i] + 2 * j;
			if (chkpermutation(n, n1) && IsPrime(n1) && chkpermutation(n, n2) && IsPrime(n2))
				cout << n << "\t" << n1 << "\t" << n2 << "\n";

		}
	}


	getchar();
}