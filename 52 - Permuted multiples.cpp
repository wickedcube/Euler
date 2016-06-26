#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;


bool chkpermutation(long n1, long n2){

	int arr1[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int arr2[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	while (n1 > 0){

		int rem = n1 % 10;

		arr1[rem]--;

		n1 = n1 / 10;
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

	for (int i = 1; i < 1000000000; i++){

		long n2 = i * 2;
		long n3 = i * 3;
		long n4 = i * 4;
		long n5 = i * 5;
		long n6 = i * 6;
	
		if (chkpermutation(i, n2) && chkpermutation(i, n3) && chkpermutation(i, n4) && chkpermutation(i, n5) && chkpermutation(i, n6)){
			cout << i << "\n";
			break;
		}
	}

	getchar();
}