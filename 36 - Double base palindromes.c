#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdbool.h>

int r[40],len = 0;;

void baseConvert(int input,int base){

	if (input<base)
	{
		r[len] = input;
		return input;
	}
	else
	{
		r[len] = input % base;
		len++;
		return baseConvert(input / base, base);
	}

}

bool IsPalindrome(long long number){

	char str[40];

	sprintf(str, "%ld", number);

	int Nodigits = log10(number) + 1;

	for (int i = 0; i < Nodigits / 2; i++){
		
		if (str[i] != str[Nodigits - 1 - i])
			return false;
	
	}
	
	return true;
}


bool IsBinaryPalindrome(int str[],int size){

	for (int i = 0; i < size / 2; i++){

		if (str[i] != str[size - 1 - i])
			return false;
	}

	return true;
}

void main(){

	long sum = 0;

	for (int i = 1; i < 1000000; i++){
		long long basetwo = 0;

		baseConvert(i,2);

		if (IsPalindrome(i) && IsBinaryPalindrome(r,len+1)){
			printf("%ld \t",i);
			sum += i;
		}

		for (int j = len; j >= 0; j--)
		{
			r[j] = 0;
		}

		len = 0;
	}

	printf("%ld", sum);

	_getch();
}