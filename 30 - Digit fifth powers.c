#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdbool.h>


int orgn;

bool Sumofpowfivedigits(long n){

	int sum = 0;

	while (n > 0){
	
		int rem = n % 10;

		sum += rem*rem*rem*rem*rem;

		if (sum > orgn)
			return false;

		n  = n / 10;
	}

	if (sum == orgn)
		return true;

	return false;

}


void main(){

	int sum = 0;

	for (long i = 10; i < 99999999; i++){
		
		orgn = i;

		if (Sumofpowfivedigits(i))
		{
			printf("%d \t",i);
			sum += i;
		}
	}

	printf("%d \t", sum);

	_getch();
}