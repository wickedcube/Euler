#include<iostream>
#include<math.h>

using namespace std;

int main(){

	int loopvar = 1000,count = 0;
	unsigned long long numerator = 3;
	unsigned long long denominator = 2;


	while (loopvar > 0){

		int nodn = floor(log10(numerator));
		int nodd = floor(log10(denominator));

		if (nodn > 13 || nodd > 13){
		
			numerator = numerator / 100;
			denominator = denominator / 100;
		
		}

		if (nodn > nodd)
		{
			cout << numerator << " " << denominator << "\n";
			count++;
		}

		numerator = 2 * denominator + numerator;
		denominator = numerator - denominator;
	
		loopvar--;
	}


	cout << count;

	getchar();

	return 0;
}