#include<iostream>
#include<conio.h>

using namespace std;

int digitarr[] = { 9, 189, 2889, 38889, 488889, 5888889 };

// return digit at location
int d(int n){

	if (n > 9){

		int i = 0, sum = 0, nod;

		while (digitarr[i] < n)
		{
			i++;
		}

		nod = i + 1;

		int temp = (n - digitarr[i-1]) / nod;
		int rem = (n - digitarr[i-1]) % nod;

		temp += pow(10, i);

		int temp2 = temp / pow(10, nod - rem);

		if (rem == 0)
			return temp % 10;
		else
			return temp2 % 10;

	}
	else
		return n;
}

void main(){

	cout << d(1)*d(10)*d(100)*d(1000)*d(10000)*d(100000)*d(1000000);

	getchar();
}