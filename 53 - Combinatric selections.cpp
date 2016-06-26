#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

void main(){

	int Total = 0;
	for (int i = 23; i < 101; i++){

		int ncr = i, k = 1, count = 1;

		while (ncr < 1000000){
			ncr = (ncr*(i - k)) / (k + 1);
			k++;
			count++;
		}

		Total += i - 2*count + 1;

	}

	cout << Total << "\n";

	getchar();
}