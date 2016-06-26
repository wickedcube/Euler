#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;


void main(){
	
	unsigned long long sum = 0;

	for (int i = 1; i < 1001; i++){
	
		int k = i;
		unsigned long long res = 1;

		while (k>0){

			res *= i;

			int digits = log10(res)+1;

			if (digits >= 11)
				res = res % 10000000000;

			k--;
		}

		sum += res;
	}

	cout << sum % 10000000000;

	getchar();
}