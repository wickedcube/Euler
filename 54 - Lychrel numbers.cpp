#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;


bool IsPalindrome(unsigned long long number){

	char str[40];

	sprintf(str, "%ld", number);

	int Nodigits = log10(number) + 1;

	for (int i = 0; i < Nodigits / 2; i++){

		if (str[i] != str[Nodigits - 1 - i])
			return false;

	}

	return true;
}



bool chkLychrel(unsigned long long number){

	int k = 0;

	while (k < 50){

		char str[40] = { ' ' };

		sprintf(str, "%I64d", number);

		_strrev(str);

		unsigned long long revn = atoll(str);
	
		unsigned long long total = number + revn;

		if (IsPalindrome(total))
			return true;

		number = total;

		k++;
	
	}

	return false;
}

void main(){

	int count = 0;
	for (int i = 0; i < 10000; i++){
	
		if (!chkLychrel(i)){
			cout << i << "\n";
			count++;
		}
	}

	cout << count;

	getchar();
}