#include<iostream>
#include<math.h>
#include<conio.h>
#include<string>
#include<fstream>
#include<algorithm>

int arr1[594], cunt = 0;

using namespace std;

int main(){

	int k = 0;

	for (int i = 1; i < 100; i++){

		arr1[k] = i + 1;
		arr1[k + 1] = 2 * (i + 1);
		arr1[k + 2] = 3 * (i + 1);
		arr1[k + 3] = 4 * (i + 1);
		arr1[k + 4] = 5 * (i + 1);
		arr1[k + 5] = 6 * (i + 1);

		k = k + 6;

	}

	int size = sizeof(arr1) / sizeof(int);

	sort(arr1, arr1 + size);

	for (int i = 1; i < 595; i++){
		if (arr1[i - 1] == arr1[i])
			cunt++;

	}

	/*sort(arr1, arr1 + size);*/

	cout << cunt;
	getchar();

	return 0;
}