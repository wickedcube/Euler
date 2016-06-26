#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdbool.h>

int fac[] = {1,1,2,6,24,120,720,5040,40320,362880};


// limit is 7 digits and only 4 factorions exist 1,2,145,40585;
bool chkSumofFacofdigits(long long number){


	long long orgn = number;
	while (number > 0){
	
		int rem = number % 10;
		orgn -= fac[rem];
		if (orgn < 0)
			return false;

		number = number / 10;
	}

	if (orgn == 0)
		return true;
	else
		return false;
}


void main(){

	int sum = 0;
	for (long long i = 3; i < 999999; i++)
	{
		if (chkSumofFacofdigits(i)){
			sum += i;
			printf("%d \t", i);
		}
	}
	
	printf("%d",sum);

	_getch();
}