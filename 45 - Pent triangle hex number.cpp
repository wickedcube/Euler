#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

void main(){

	for (long i = 143; i < 1000000000; i++){
	
		unsigned long long hexnumber = i*(2 * i - 1);

		unsigned long long trianglenumber = 8 * hexnumber + 1;

		long long sqrtt = sqrt(trianglenumber);

		unsigned long long pentnumber = 24 * hexnumber + 1;

		long long sqrtp = sqrt(pentnumber);

		if (sqrtp*sqrtp == pentnumber && sqrtp % 6 == 5 && sqrtt*sqrtt == trianglenumber && sqrtt % 2 == 1){
		
			cout << hexnumber<<"\n";
		}
	}

	getchar();
}