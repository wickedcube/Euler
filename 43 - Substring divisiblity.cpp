#include<iostream>
#include<conio.h>

using namespace std;

bool IsPandigital(long long number, int n){

	int arr[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, amax = 0, amin;
	while (number > 0){

		int rem = number % 10;

		arr[rem]--;

		if (arr[rem] < 0)
			return false;

		number = number / 10;
	}

	for (int i = 0; i < n; i++){

		if (i == 0)
			amin = arr[i];

		if (arr[i] > amax)
			amax = arr[i];

		if (arr[i] < amin)
			amin = arr[i];
	}

	if (amax == 0 && amin == 0)
		return true;
	else
		return false;
}

bool chkdivprop(long long num){

	int parr[] = { 2, 3, 5, 7, 11, 13, 17 };

	int i = 0;
	while (i < 7){

		int dividend = pow(10, 6 - i);
		long long temp = num / dividend;

		temp = temp % 1000;

		if (temp % parr[i] > 0)
			return false;

		i++;
	}

	return true;
}


void main(){

	long long sum = 0;

	for (long long i = 1406357289; i < 9876543211; i++)
	{
		if (IsPandigital(i, 10) && chkdivprop(i)){
			cout << i << "\n";
			sum += i;
		}
	}

	cout << sum;

	getchar();
}